/* arrays.c
*  Evan Cummings
*  CSCI 460 - Operating Systems
*  Fall 'll - Doug Raiford
*/

#include <stdio.h>
#include <stdlib.h>

float calcAvg(int *array, int size);

int main(int argc,char *argv[])
{
  int *myArray;
  int size = 50;
  int i;
  float avg;
  myArray = malloc(size * sizeof(int));
  
  for (i=0; i<size; i++)
  {
    myArray[i] =  rand()%30000 + 20001;
  }
  
  avg = calcAvg(myArray, size);
  printf("The average is: %1.2f\n", avg);
  
  return(0);
}

float calcAvg(int *a, int size)
{
  int i;
  int sum = 0;
  float avg;
  
  for (i=0; i<size; i++)
  {
    sum += a[i];
  }
  avg = (float)sum/size;
  return avg;  
}