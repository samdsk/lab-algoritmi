#include <stdio.h>
#include <ctype.h>

int main(void){

	int c, f[10] = {0};
	c = getchar();
	
	while(c!='.'){

		if(isdigit(c)){
			
			f[c-'0']++;			
		}
		c = getchar();
	}
	
	int i;
	for(i=0;i<10;i++){
		if(f[i]>1){
			printf("%d\n",f[i]);
		}				

	}

}
