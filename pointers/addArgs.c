/* addArgs.c
*  Evan Cummings
*  CSCI 460 - Operating Systems
*  Fall 'll - Doug Raiford
*
*  Returns a -1 if not enough args, 1 if there are too many!
*/
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
  return a + b;
}

int main(int argc,char *argv[])
{
  int arg1, arg2, sum;

  if (argc == 3)
  {
    printf("Good Work, 2 args!\n");
  }
  
  else if (argc < 3)
  {
    printf("Too few args!\n");
    exit(-1);
  }
  
  else
  {
    printf("Too many args!\n");
    exit(1);
  }
  
  arg1 = atoi(argv[1]);
  arg2 = atoi(argv[2]);
  
  sum = add(arg1, arg2);
  printf("The sum is: %d\n", sum);
  
  return(0);
}
