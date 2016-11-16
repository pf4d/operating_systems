CFLAGS = -g -Wall -ansi -pedantic 

CC = gcc
OBJECT = addArgs.o
PROJECT = addArgs

%.o : %.c
	$(CC) $(CFLAGS) -c $<

hello:	$(OBJECT)
	$(CC) -o $(PROJECT) $(CFLAGS) $(OBJECT)

clean:
	/bin/rm -fr $(OBJECT) $(PROJECT) *.o *~ core* ; clear


