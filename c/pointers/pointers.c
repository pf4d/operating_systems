/* pointers.c
* Evan Cummings
* CSCI 460 - Operating Systems
* Fall 'll - Doug Raiford
*/

#include <stdio.h>
#include <stdlib.h>
 
int main(int argc,char *argv[])
{
  /* create a pointer to an integer */
  int * myInt;

  /* must initialize value, the `nil` pointer */
  myInt = 0;

  /* print the value of the pointer */
  printf("the pointer is %p\n", (void*)myInt);

  /* allocate space for an integer pointed to by myInt */
  myInt = malloc(sizeof(int));

  /* initialize the value of this integer to 2 */  
  *myInt = 2;

  /* print the info to the screen */
  printf("size of int is %li\n", sizeof(int));
  printf("the pointer is %p\n", (void*)myInt);
  printf("myInt has the following value %d\n", *myInt);

  /* de-allocate the memory */
  free(myInt);

  /* return successfully */
  return(0);
}
