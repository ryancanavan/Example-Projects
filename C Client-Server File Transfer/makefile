CC = gcc
LIBS = -lpthread  -lrt
INCS = -I./
CCFLAGS = -std=gnu99 -O2

all: client server
server: csapp.o server.c
	$(CC) $(CCFLAGS) $^ -o $@ $(LIBS) $(INCS)
client: csapp.o client.c
	$(CC) $(CCFLAGS) $^ -o $@ $(LIBS) $(INCS)
csapp.o: csapp.c csapp.h
	$(CC) $(CCFLAGS) -c $< -o $@  $(INCS)

clean:
	rm -f client csapp.o
