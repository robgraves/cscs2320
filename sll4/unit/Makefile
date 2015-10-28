SHELL = /bin/bash -e
INC = -I ../inc/
CFLAGS = -Wall 
OPTS =
CC = gcc $(CFLAGS) $(OPTS) $(INC)
PARTS = $(shell /bin/ls -1Ad * | grep -v 'Makefile')
DEBUG = 
default: bins

debug: CC += -DDEBUG -g
debug: DEBUG = debug
debug: bins

bins:
	@for i in $(PARTS); do make -C $$i $(DEBUG); done

clean:
	@for i in $(PARTS); do make -C $$i clean; done
