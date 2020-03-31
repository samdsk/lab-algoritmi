#include <stdio.h>

#define FATTORE_SCALA (5.0f/9.0f)
#define ZERO 32.0f

int main(void){
	float f,c;
	printf("Inserisci la temperatura in gradi Fahrenheit:");
	scanf("%f",&f);

	c = (f-ZERO)*FATTORE_SCALA;

	printf("Gradi Celsius equivalenti: %.1f\n",c);

	return 0;


}
