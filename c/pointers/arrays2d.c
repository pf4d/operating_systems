/* arrays2d.c
*  Evan Cummings
*  CSCI 460 - Operating Systems
*  Fall 'll - Doug Raiford
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  int **myArray;
  int numRows;
  int numCols;
  int i, j;
  
  numRows = 3;
  numCols = 4;
  
  myArray = malloc(numRows * sizeof(*myArray));
 
  for(i=0; i<numRows; i++)
  {
    myArray[i] = malloc(numCols * sizeof(int));
    for(j=0; j<numCols; j++)
    {
      myArray[i][j] = (i + 1) * (j + 1);
    }
    
  }
  
  for(i=0; i<numRows; i++)
  {
    for(j=0; j<numCols; j++)
    {
      printf("row %d, column %d holds value %d\n", 
        i + 1, j + 1, myArray[i][j]);
    }
    
  }
  return(0);
}
