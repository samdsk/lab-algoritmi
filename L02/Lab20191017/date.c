#include <stdio.h>
typedef struct{
  int giorno,mese,anno;
}Date;
int main(void){
  Date d[100]={0};
  int i=0;
  printf("Inserisci al massimo 100 date:");
  scanf("%d/%d/%d",&d[i].giorno,&d[i].mese,&d[i].anno);
  while(i<100){
    if(d[i].giorno==0 && d[i].mese==0 && d[i].anno==0){
      break;
    }
    i++;
    scanf("%d/%d/%d",&d[i].giorno,&d[i].mese,&d[i].anno);
  }

  Date fine;
  printf("Inserisci la data finale:");
  scanf("%d/%d/%d",&fine.giorno,&fine.mese,&fine.anno);

  int j=0;
  while(1){
    if(d[j].giorno<fine.giorno && d[j].mese<fine.mese && d[j].anno<fine.anno){
      break;
    }
    printf("%02d/%02d/%d\n",d[j].giorno,d[j].mese,d[j].anno);
    j++;
  }

  return 0;

}
