/****************************************************
** myShell.c
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    Shell program takes input and gives output. 
**    
*****************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>


int main()
{
  char* buf;
  char* pch;
  
  buf = malloc(10000 * sizeof(char));
  
  /*Setup an infinite loop */
  while(1)
  {
    int x;
    
    /* Display a prompt */
    write(1, "myShell% ", 9);
    
    /* Read in the user input from standard in */
    x = read(1, buf, sizeof(buf));
    
    /* Tokenize input */
    pch = strtok(buf, " ,.-\t");
    buf = pch;
    buf[x-1] = 0;
    
    /* If first char is '!' Cause Unix to execute the invoked command */
    if(buf[0] == '!')
    {
      system(buf + 1);
    }
    /* Otherwise */
    else
    {      
      /* Run proper command */
      if(strcmp(buf, "uid") == 0)
      {
        printf("userId: %d\n", getuid());
      }
      else if(strcmp(buf, "user") == 0)
      {
        struct passwd* passwd_info;
        passwd_info = getpwuid(getuid());
        printf("%s\n", passwd_info->pw_name);
      }
      else if(strcmp(buf, "quit") == 0  || strcmp(buf, "q") == 0)
      {
        exit(0);
      }
      
      /* If the command was not legal then display the error message */
      else
      {
        printf("\nThe shell has only the following cmds:\n");
        printf("\tuid\n\tuser\n\tquit\n\tq\n");
        printf("Start with '!' to invoke a Unix shell cmd\n");
      }
        
    }
    
  }
  return 0;
}
