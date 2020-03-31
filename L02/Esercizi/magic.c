#include <stdio.h>
#define N 5

int main(void){
	int quadrato[N][N] = {{0}}, k = 1;
	int i, j, inew, jnew;
	
	i = 0; j = N/2;
	int nn = N*N;
	for ( k = 1; k <= nn; k++ ) {
		
		quadrato[i][j] = k; 
		inew = ( i == 0 ) ? N - 1 : i - 1;
		jnew = ( j == N - 1 ) ? 0 : j + 1;
		if ( quadrato[ inew ][ jnew ] == 0 ) {
		  i = inew;
		  j = jnew;
		}
		else {
		  i++; 
		}
	}
	
	int x,y,sumx[N]={0},sumy[N]={0},sumd[2]={0};
	
	for (x=0;x<N;x++){
		for(y=0;y<N;y++){
			int temp = quadrato[x][y];
			
			printf("%d\t",temp);
			
			sumx[x] += temp;
			sumy[y] += temp;
			
			if(x==y){
				sumd[0]+=temp;
			}
			if(y==N-1-x){
				sumd[1]+=temp;
			}			
		}
		
		printf("\n\n");
	}
	
	printf("1:%d 2:%d\n",sumd[0],sumd[1]);
	printf("1:%d 2:%d 3:%d 4:%d\n",sumx[0],sumx[1],sumx[2],sumx[3]);
	printf("1:%d 2:%d 3:%d 4:%d\n",sumy[0],sumy[1],sumy[2],sumy[3]);

}
