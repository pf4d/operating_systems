/* queue.c
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    A queue of PCB structs.
*/

#include "queue.h"

/* Add a node to the queue. */
void enqueue(PCB** head, PCB** tail, PCB passedPCB)
{
  PCB* newNode;
  newNode = (PCB*)malloc(sizeof(PCB));
  *newNode = passedPCB;
  newNode->prev = NULL; /*nothing in behind it*/
  newNode->next = *tail;
  
  if(*tail != NULL)
    (*tail)->prev = newNode;
  
  /* This is the first node to be added so populate head. */
  else
    *head = newNode;
    
  /* The new node is always the tail node. */
  *tail = newNode;
}

/* Dequeue and return the head node. */
PCB dequeue(PCB** head, PCB **tail)
{
  PCB dequeuedNode;
  PCB* newHead;
  
  dequeuedNode = **head;
  
  newHead = (*head)->prev;
  newHead->next = NULL;
  
  free(*head);
  
  *head = newHead;
  
  dequeuedNode.prev = NULL;
  dequeuedNode.next = NULL;
  
  return dequeuedNode;
}

/* Print each node's ID value to screen. */
void print_queue(PCB* head)
{
  int i = 1;
  PCB* nodeIter = head;
  
  printf("\nHead of queue\n");
  printf("=================\n");
  
  while(nodeIter->prev != NULL)
  {
    if(nodeIter->next == NULL)
      printf("Head node ID: \t%d\n", nodeIter->ID);
    
    else
      printf("Node %d ID: \t%d\n", i, nodeIter->ID);
    
    nodeIter = nodeIter->prev;
    i++;
  }
  printf("Tail node ID: \t%d\n", nodeIter->ID);
  printf("=================\n");
  printf("Tail of queue\n\n");
}

/* Clear the queue of all nodes and free their memory. */
void clear_queue(PCB** head, PCB** tail)
{
  PCB dequeuedNode;
  
  while((*head)->prev != NULL)
    dequeuedNode = dequeue(head, tail);
  free(*tail);
  *tail = NULL;
  *head = NULL;
}


/* Return the size of the queue. */
int size_of_queue(PCB* head)
{
  int count;
  PCB* nodeIter;
  
  count = 0;
  nodeIter = head;
  
  while(nodeIter != NULL)
  {
    count++;
    nodeIter = nodeIter->prev;
  }
  return count;
  
}

