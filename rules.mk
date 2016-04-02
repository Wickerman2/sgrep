
CC=gcc
CFLAGS=-pedantic -std=gnu1x -Wall -Werror -Iparser -Isearcher -I. -I..
DEBUG_FLAGS=-DSGREP_DEBUG -g

OBJS=$(C_FILES:%.c=%.o) $(MAIN:%.c=%.o) 

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS): $(C_FILES) $(MAIN) 

$(PROG): $(OBJS)
	@echo "Compiling $(OBJS) in to $(PROG)"
	$(CC) $(CFLAGS) -o $@ $(OBJS)


