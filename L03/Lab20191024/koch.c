#include <stdio.h>

#include "libpsgraph.h"

void koch(double,int);

int main(void){
  double x;
  int i;

  printf("Inserire x e i: ");
  scanf("%lf %d",&x,&i);

  char filename[]="koch.ps";
  start(filename);

  for(int k=0;k<3;k++){
    koch(x,i);
    turn(120.);
  }

  end();
  return 0;
}

void koch(double x,int i){
  if(i==0){
    draw(x);
  }else{
    x/=3;
    i-=1;
    koch(x,i);
    turn(-60.);
    koch(x,i);
    turn(120.);
    koch(x,i);
    turn(-60);
    koch(x,i);
  }
}
