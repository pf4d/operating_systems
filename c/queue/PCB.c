/* PCB.c
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    A PCB struct initialization.
*/

#include "PCB.h"

void initializePCB(PCB *passedPCB)
{
  passedPCB->ID = 0;
  passedPCB->PC = 0;
  passedPCB->base = 0;
  passedPCB->limit = 0;
  passedPCB->register1 = 0;
  passedPCB->register2 = 0;
  passedPCB->register3 = 0;
  passedPCB->register4 = 0;
  passedPCB->register5 = 0;
  passedPCB->next = 0;
  passedPCB->prev = 0;
}

