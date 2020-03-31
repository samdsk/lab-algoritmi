/*

Post Office (IOI 2000)
Copyright (C) 2000 Paolo Boldi and Sebastiano Vigna

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



Il problema si risolve facilmente tramite programmazione dinamica, dopo aver
fatto la seguente osservazione: data una disposizione ottima di uffici postali,
questa divide le citta` in blocchi, dove ogni blocco e` formato da citta` che
condividono l'ufficio postale piu` vicino (il blocco comprende, ovviamente, la
citta` dove e` posizionato l'ufficio postale corrispondente).

Se togliamo l'ultimo blocco, abbiamo ancora, per le citta` e gli uffici postali
rimanenti, una disposizione ottima: altrimenti, riaggiungendo l'ultimo blocco
ed eventualmente "aggiustando" la posizione delle citta` agli estremi
dell'ultimo e del penultimo blocco otterremmo una soluzione migliore di quella
da cui eravamo partiti.

Possiamo quindi calcolare le soluzioni ottime per n villaggi e p uffici utilizzando
quelle ottime per meno di <n villaggi e <p uffici.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define min(a,b) ((a)<(b)?(a):(b))

#define MAXV 300 /* Massimo numero di villaggi */
#define MAXP 30  /* Massimo numero di uffici postali */

int v[MAXV+1]; /* Distanza dei villaggi */
int pos[MAXP+1][MAXV+1]; /* posizione dell'ufficio p nella disposizione ottima
                            che utilizza solo i primi v villaggi */
int sommadist[MAXP+1][MAXV+1]; /* Somma delle distanze per l'ufficio p nella disposizione
											 ottima che utilizza solo i primi v villaggi */
int prec[MAXP+1][MAXV+1]; /* Per ogni soluzione, la lunghezza del prefisso di
									  villaggi che compone la soluzione ottima che si
									  ottiene eliminando l'ultimo blocco */
int temp[MAXP+1]; /* Vettore temporaneo per riordinare il risultato */

int V, P;
FILE *F;

int main(int argc, char *argv[]) {
	int i, j, k, l, t, p, curmin;

	F = stdin;
	fscanf(F, "%d %d\n", &V, &P);
	for(i=1; i<=V; i++) fscanf(F, "%d", &v[i]);

	for(i=1; i<=V; i++) {
		curmin = INT_MAX;
		for(j=1; j<=i; j++) {
			t = 0;
			for(k=1; k<=i; k++) t += abs(v[j] - v[k]);
			if (t < curmin) {
				/* Durante la lettura dell'input, calcoliamo la soluzione ottima
					con un solo ufficio postale per ogni prefisso di villaggi. */
				curmin = t;
				pos[1][i] = j;
				sommadist[1][i] = t;
			}
		}
	}

	for(p=2; p<=P; p++) { /* p>1 e` il numero di uffici */
		for(i=p; i<=V; i++) { /* i e` la lunghezza del prefisso di villaggi in cui li posiziono */
			curmin = INT_MAX;
			for(j=p-1; j<i; j++) { /* j e` la lunghezza del prefisso che prendo degli i villaggi */
				if (sommadist[p][j] != INT_MAX) {
					for(k=j+1; k<=i; k++) {/* k e` la posizione del nuovo ufficio
                                         postale tra gli i-j villaggi rimanenti */
						/* Questi due test corrispondono a posizionamenti che vanno
							evitati perche' perturberebbero la soluzione ottima
							precedente. */
						if (v[k]-v[j] < v[j]-v[pos[p-1][j]]) continue;
						if (v[k]-v[j+1] > v[j+1]-v[pos[p-1][j]]) break;
	    
						t = 0;
						/* il ciclo su l calcola la somma delle distanze con gli i-j villaggi rimanenti */
						for(l=j+1; l<=i; l++) t += abs(v[k] - v[l]);

						/* Se abbiamo trovato una nuova soluzione, aggiorniamo pos e
                     sommadist; inoltre, ricordiamo tramite prec quale
                     soluzione ottima abbiamo esteso. */
						if (t + sommadist[p-1][j] < curmin) {
							curmin = t + sommadist[p-1][j];
							pos[p][i] = k;
							sommadist[p][i] = curmin;
							prec[p][i] = j;
						}
					}
				}
			}
			if (curmin == INT_MAX) sommadist[p][i] = INT_MAX;
		}
	}


	/* Ricostruiamo ora la soluzione ottima globale utilizzando prec
      "all'indietro". */

	j = V;
	for(i=P; i>=1; i--) {
		temp[i] = pos[i][j];
		j = prec[i][j];
	}

	F = stdout;
	fprintf(F, "%d\n", sommadist[P][V]);
	for(i=1; i<=P; i++) fprintf(F, "%d ", temp[i]);
	fprintf(F, "\n");

	return 0;
}
