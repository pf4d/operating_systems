/* PCB.h
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    A PCB struct.
*/

#ifndef PCB_H
#define PCB_H

struct PCB
{
  /*various data fields within the PCB structure*/
  /*in this implementation just ID is included*/
  int ID;
  int PC;
  int base;
  int limit;
  int register1;
  int register2;
  int register3;
  int register4;
  int register5;
  struct PCB* next;
  struct PCB* prev;
} typedef PCB;

void initializePCB(PCB *passedPCB);

#endif

