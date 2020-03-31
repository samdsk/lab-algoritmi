#include <stdio.h>

int main(){
  short ah,am,as,bh,bm,bs,s,m,h;
  printf("Inserire orario A hh:mm:ss\n");
  scanf("%hd:%hd:%hd",&ah,&am,&as);

  printf("Inserire orario B hh:mm:ss\n");
  scanf("%hd:%hd:%hd",&bh,&bm,&bs);

  short oraA = as+am*60+ah*60*60;
  short oraB = bs+bm*60+bh*60*60;

  short ora = oraB-oraA;

  h = ora/3600;
  m = (ora%3600)/60;
  s = ora-(h*60*60+m*60);

  printf("differenza è %hd:%hd:%hd\n",h,m,s);

}
