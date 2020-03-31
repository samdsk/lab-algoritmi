#include <stdio.h>
#define PI 3.14159

typedef struct {
	float x, y;
} Punto;
	
typedef struct {
	Punto p1;
	Punto p2;
} Rettangolo;

typedef struct{
	Punto centro;
	float raggio;
}Cerchio;
	
int main(void){
	
	float b, h, area , duep;
	/*Rettangolo r;*/
	Cerchio c;
	/*
	printf( "RETTANGOLO :\n" );
	printf( "Inserisci le coordinate del punto in basso a sinistra\n" );
	scanf( "%f%f" , &r.p1.x, &r.p1.y );
	
	printf( "Inserisci le coordinate del punto in alto a destra\n" );
	scanf( "%f%f", &r.p2.x, &r.p2.y );
	

	
	b = r.p2.x - r.p1.x;
	h = r.p2.y - r.p1.y;
	area = b * h;
	duep = 2 * ( b + h );*/
	printf("Inserisci le coordinate del centro del cerchio e raggio\n");
	scanf("%f %f %f",&c.centro.x,&c.centro.y,&c.raggio);
	printf("L'area del rettangolo vale %f, il perimetro vale %f\n", area , duep );	
	float ac = (c.raggio*c.raggio);
	float pc = (2*c.raggio);
	printf("L'area del cerchio vale %f, il perimetro vale %f\n",ac*PI,pc*PI);
	
	return 0;
 }
