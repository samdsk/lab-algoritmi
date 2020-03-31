#include <stdio.h>
#include <string.h>


void smallest_largest(char**,int,char**,char**);

int main(void){
  char *dict[] = {"ciao","mondo","come","funzione","bene","il","programma","a"};
  int lun = 8;
  char *small = {"non_cambiato_s"};
  char *large = {"non_cambiato_l"};
  char **smallest = &small;
  char **largest = &large;

  #ifdef DEBUG
  printf("Smallest: %p, largest: %p\n",*smallest,*largest);
  #endif

  smallest_largest(dict,lun,smallest,largest);

  printf("Smallest- '%s' : %p, Largest- '%s' : %p\n",*smallest,*smallest,*largest,*largest);

  return 0;
}

void smallest_largest(char *s[],int n,char **smallest,char **largest){
  smallest[0] = s[0];
  largest[0] = s[0];
  int i=1;

  while(i<n){
    char *temp = s[i];
    int small = strcmp(*smallest,temp);
    int large = strcmp(*largest,temp);

    #ifdef DEBUG
    printf("Temp: %s, Smallest: %s : %d, Largest: %s : %d\n",temp,*smallest,small,*largest,large);
    #endif

    if(small>0){
      *smallest = temp;

      #ifdef DEBUG
      printf("changed smallest to %s\n",temp);
      #endif
    }

    if(large<0){
      *largest = temp;

      #ifdef DEBUG
      printf("changed largest to %s\n",temp);
      #endif
    }

    i++;
  }

}
