/* adderPntr.c
* Evan Cummings
* CSCI 460 - Operating Systems
* Fall 'll - Doug Raiford
*/

#include <stdio.h>

int add(int *a, int *b);

int main(int argc,char *argv[])
{
  int mySum;
  int a;
  int b;
  
  a = 5;
  b = 6;
  
  mySum = add(&a,&b);
  printf("my sum is %d\n", mySum);
  printf("a is now: %d\n", a);
  return(0);
}

int add(int *a, int *b)
{
  int sum;
  sum = *a + *b;
  *a = 999;
  return sum;
}
