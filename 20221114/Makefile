SRCS = static_main.c
SRCS1 = dynamic_main.c
LIBSRCS = open.c close.c put.c get.c seek.c
TARG = kvs_static
TARG1 = kvs_dynamic

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

LD_LIBRARY_PATH = .
OBJS = $(SRCS:.c=.o)
OBJS1 = $(SRCS1:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a
LARS1 = ./sysprog/private/2022114/libkvs.so

all:

static: $(TARG)

$(TARG) : $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) 

$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

dynamic: $(TARG1)
$(TARG1) : $(OBJS1) $(LARS1)
	$(CC) -o $(TARG1) $(OBJS1) -ldl

$(LARS1) :
	$(cc) -fPIC -o $(LARS1) $(LIBSRCS)

$.o: $.c
	$(cc) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG) $(OBJS1) $(LARS1) $(TARG1)
