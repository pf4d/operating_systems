/****************************************************
** requester.c
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    A program which sends POSIX messages and 
**    is given a reply from supplier.c
*****************************************************/

#include <sys/errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
  struct 
  {
    long priority;
    int number;
  } msgp;

  
  int msqid,status;
  int key,supplierQid,answer,num;
  
  msgp.priority= 2;
  msgp.number = 0;
  key = 763;
  
  printf("key is %i\n",key);
  printf("creating msquid\n");
  
  //--------------------------------------------------
  //~ YOU MUST SUPPLY CODE THAT PERFORMS THE FOLLOWING 
  //--------------------------------------------------
  
  //~ Create a Q for receiving information (you can use 
  //~ the variable key as the unique identifier)
  msqid = msgget(key,0666 | IPC_CREAT);
  //~ Create a Q for sending information to the supplier 
  //~ (you can use key+1 as the unique identifier)
  supplierQid = msgget(key+1,0666 | IPC_CREAT);
  //~ Loop 100 times
  for(int i = 0; i < 100; i++)
  {
    //~ Generate a random number (between 0 and 500)
    num = (rand()%500 + 1);
    msgp.number = num;
    //~ Send the number to the supplier
    status = msgsnd(supplierQid, &msgp, sizeof(msgp)-sizeof(long),0);
    if(status != -1)
      printf("Requester - Message Sent: %d\n", msgp.number);
    else
      printf("Error\n");
    //~ Receive the answer back from the supplier
    status = msgrcv(msqid, &msgp, sizeof(msgp)-sizeof(long),2,0);
    //~ Display the solution to the console
    if(status != -1)
    {
      answer = msgp.number;
      printf("Requester - Message Received: %d\n", answer);
      if(answer == num*num)
        printf("Requester - Message is valid\n");
      else
        printf("Requester - Message is not valid\n");
    }
    else
      printf("Error\n");
  }
  printf("all done\n");
  return(0);
}

