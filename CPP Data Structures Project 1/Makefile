.PHONY:clean

arraylist:
	@g++ -std=c++11 arraylist.cpp arraylistclass.cpp -o arraylist.o
	@./arraylist.o

arraystack:
	@g++ -std=c++11 arraystack.cpp arraystackclass.cpp -o arraystack.o
	@./arraystack.o

pointerlist:
	@g++ -std=c++11 pointerlist.cpp pointerlistclass.cpp -o pointerlist.o
	@./pointerlist.o

pointerstack:
	@g++ -std=c++11 pointerstack.cpp pointerstackclass.cpp -o pointerstack.o
	@./pointerstack.o

timing:
	@g++ -std=c++11 timing.cpp arraylistclass.cpp arraystackclass.cpp pointerlistclass.cpp pointerstackclass.cpp -o timing.o
	@./timing.o

clean:
	@\rm -f *.o
