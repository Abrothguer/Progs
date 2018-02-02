//TIME CONVERTER

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void getdata(int* from, int* to, double* x);

int main(){
  double x;
  int from, to;
  char unit[4][10] = {"Second(s)\0","Minute(s)\0","Hour(s)\0","Day(s)\0"};
  system("clear");
  printf("Time Converter\n");
  getdata(&from, &to, &x);

  if(from == 4 && to == 1) x *= 86400;
  else if(from == 4 && to == 2) x *= 1440;
  else if(from == 4 && to == 3) x *= 24;
  else if(from == 3 && to == 1) x *= 3600;
  else if(from == 3 && to == 2) x *= 60;
  else if(from == 3 && to == 4) x /= 24;
  else if(from == 2 && to == 1) x *= 60;
  else if(from == 2 && to == 3) x /= 60;
  else if(from == 2 && to == 4) x /= 1440;
  else if(from == 1 && to == 2) x /= 60;
  else if(from == 1 && to == 3) x /= 3600;
  else if(from == 1 && to == 4) x /= 86400;

  x == (int) x ? printf("%d", (int) x) : printf("%lf", x);
  printf(" %s\n", unit[to-1]);
  return 0;
}

//Funtion used to get data from the user.

void getdata(int* from, int* to, double* x){
  printf("Convert: ");
  scanf("%lf", x);
  do {
    printf("Convert from:\n");
    printf("[1]. Seconds\n");
    printf("[2]. Minutes\n");
    printf("[3]. Hours\n");
    printf("[4]. Days\n");
    scanf("%d", from);
  } while(*from < 1 || *from > 4);
  do {
    printf("Convert to:\n");
    printf("[1]. Seconds\n");
    printf("[2]. Minutes\n");
    printf("[3]. Hours\n");
    printf("[4]. Days\n");
    scanf("%d", to);
  } while(*to < 1 || *to > 4);
  return;
}
