/* TestQueue.c
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    Demonstration of a PCB queue.
*/

#include "queue.h"

/* main method. */
int main(int argc, char * argv[])
{
  PCB** headOfQueue;
  PCB** tailOfQueue;
  PCB pcbNode;
  int i;
 
  headOfQueue = (PCB*)malloc(sizeof(PCB*));
  tailOfQueue = (PCB*)malloc(sizeof(PCB*));
  *headOfQueue = NULL;
  *tailOfQueue = NULL;
  i = 0;

  for(i=0; i<100; i++)
  {
    pcbNode.ID = rand()%10000 + 1;
    enqueue(headOfQueue, tailOfQueue, pcbNode);
  }
  
  print_queue(*headOfQueue);
  printf("number of nodes: %d\n", size_of_queue(*headOfQueue));
  printf("\nClearing Queue:\n");
  clear_queue(headOfQueue, tailOfQueue);
  printf("number of nodes: %d\n", size_of_queue(*headOfQueue));
  
  return(0);
}

