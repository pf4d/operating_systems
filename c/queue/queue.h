/* queue.h
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    Header file for queue.c.
*/

#ifndef Q_H
#define Q_H

#include "PCB.h"
#include <stdio.h>
#include <stdlib.h>

void enqueue(PCB** head, PCB** tail, PCB passedPCB);
PCB dequeue(PCB** head, PCB** tail);
void print_queue(PCB* head);
void clear_queue(PCB** head, PCB** tail);
int size_of_queue(PCB* head);

#endif

