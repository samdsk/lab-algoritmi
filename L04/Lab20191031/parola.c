#include <stdio.h>
#include <string.h>

typedef char* String;

int smallest_word_index(String*,int);
String *smallest_word_address(String[],int);

int main(void){
  String dict[]={"ciao","mondo","come","funzione","bene","il","programma","a"};
  int lun = 8;
  int pos = smallest_word_index(dict,lun);
  String *ind = smallest_word_address(dict,lun);
  printf("La parola piu piccola: %s - %d %p\n",dict[pos],pos,dict[pos]);
  printf("Indirizzo della parola piu piccola: %p\n",*ind);

  return 0;
}

int smallest_word_index(String a[],int n){
  String small = a[0];
  int i=1,index=0;
  while(i<n){
    int res = strcmp(small,a[i]);
    if (res > 0){
      small = a[i];
      index = i;
    }
    i++;
  }

  return index;
}

String *smallest_word_address(String s[],int n){
  String *small = s;
  int i=1;
  while(i<n){
    int res = strcmp(*small,s[i]);
    if(res>0){
      *small = s[i];
    }
    i++;
  }
  return small;
}
