/****************************************************
** supplier.c
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    A program which accepts POSIX messages and 
**    returns a reply to requester.c
*****************************************************/

#include <stdio.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
  struct 
  {
    long priority;
    int number;
  } msgp;

  msgp.priority= 2;
  msgp.number = 0;
  int key = 764;
  int msqid;
  int supplierQid;
  int returnSol = 0;
  int status;
  
  
  //--------------------------------------------------
  //~ YOU MUST SUPPLY CODE THAT PERFORMS THE FOLLOWING 
  //--------------------------------------------------
  
  //~ Create a Q for receiving information (you can use key
  //~ as unique identifier)
  msqid = msgget(key,0666 | IPC_CREAT);
  //~ Create a Q for sending information to the requester
  //~ (you can use key-1 as the unique identifier)
  supplierQid = msgget(key-1,0666 | IPC_CREAT);
  //~ Loop
  while(1)
  {
    //~ Receive number from requester
    status = msgrcv(msqid, &msgp, sizeof(msgp)-sizeof(long),2,0);
    if(status != -1)
      printf("Supplier - Message Received: %d\n", msgp.number);
    else
      printf("Error\n");
    //~ Calculate square of that number
    returnSol = msgp.number * msgp.number;
    msgp.number = returnSol;
    //~ Send that calculated number back to the requester
    status = msgsnd(supplierQid, &msgp, sizeof(msgp)-sizeof(long),0);
    if(status != -1)
      printf("Supplier - Message Sent: %d\n", msgp.number);
    else
      printf("Error\n");
  }
  return 0;
}