CC = gcc
CFLAGS = -Wall -c
AR = ar
LIBNAME = data.a
SRC = lib.c
OBJS = $(SRC:.c=.o)

all: $(LIBNAME)

$(LIBNAME): $(OBJS)
    $(AR) rcs $(LIBNAME) $(OBJS)

%.o: %.c data.h
    $(CC) $(CFLAGS) $< -o $@

clean:
    rm -f $(OBJS) $(LIBNAME)
