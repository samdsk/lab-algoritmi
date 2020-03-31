#include <stdio.h>
#include <limits.h>


int main(){
  short s;
  unsigned short us;
  int n;
  unsigned int un;
  long l;
  unsigned long ul;

  float f;
  //unsigned float uf;
  double d;
  //unsigned double ud;
  long double ld;
  //unsigned long double ulb;



  printf("short:%ld min: %d max: %d\n",sizeof(s),SHRT_MIN,SHRT_MAX);
  printf("unsigned short:%ld max: %d\n",sizeof(us),USHRT_MAX);
  printf("int:%ld min: %d max: %d",sizeof(n),INT_MIN,INT_MAX);
  printf("unsigned int:%ld max: %d\n",sizeof(un),UINT_MAX);
  printf("long:%ld min: %ld max: %ld",sizeof(l),LONG_MIN,LONG_MAX);
  printf("unsigned long:%ld max: %ld\n",sizeof(ul),ULONG_MAX);


  printf("float:%ld\n",sizeof(f));
  //printf("unsigned float:%f",sizeof(us));
  printf("double:%ld\n",sizeof(d));
  //printf("unsigned double:%f",sizeof(ud));
  printf("long double:%ld\n",sizeof(ld));
  //printf("unsigned long double:%f",sizeof(uld));
}
