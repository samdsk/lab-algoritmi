#include <stdio.h>
#include <ctype.h>

#define N 20

int main(void){
	char parola[N];
	int i=0;
	
	char c = getchar();
	
	while (c != '.'){
		parola[i++]=c;
		c = getchar();
	}
	
	int offset=0;	
	scanf("%d",&offset);	
	

	int j;
	for(j=0;j<i;j++){
		int x = parola[j];
		int y;
		if(isalpha(x)){
			if(x>96){
				y = (x-'a'+offset)%26;
				printf("%c",y+'a');
			}else{
				y = (x-'A'+offset)%26;
				printf("%c",y+'A');
			}
		}else{
			printf("%c",x);	
		}

		
	}
	
	printf("\n");
	
	return 0;
}
