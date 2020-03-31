#include <stdio.h>
#define N 100

int main(void){
	char parola[N];
	
	int i=0;
	char c = getchar();
	while(c !='.'){
		parola[i++] = c;
		c = getchar();		
	}
	int j=0;
	char skip = parola[i-1];
	
	while(j<i){
		if(skip != parola[j]){
			printf("%c",parola[j]);
		}
		j++;	
	}

}
