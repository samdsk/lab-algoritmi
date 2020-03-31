int main(void){
  int a[LENGHT];
  int *p;
  for(p=a;p<a+LENGHT;p++){
    scanf("%d",p);
    if(*p==0){
      break;
    }
  }

  while(--p>=a){
    printf("%d ",*p);
  }

  printf("\n");
  return 0;
}
