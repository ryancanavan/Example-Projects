.PHONY:clean

pointerqueue:
	@g++ -std=c++11 pointerqueue.cpp pointerqueueclass.cpp -o pointerqueue.o
	@./pointerqueue.o

loctree:
	@g++ -std=c++11 loctree.cpp loctreeclass.cpp -o loctree.o
	@./loctree.o

lcrstree:
	@g++ -std=c++11 lcrstree.cpp lcrstreeclass.cpp -o lcrstree.o
	@./lcrstree.o

timing:
	@g++ -std=c++11 timing.cpp loctreeclass.cpp lcrstreeclass.cpp -o timing.o
	@./timing.o

mergelists:
	@g++ -std=c++11 mergelists.cpp arraylistclass.cpp pointerlistclass.cpp -o mergelists.o
	@./mergelists.o

traversalconvert:
	@g++ -std=c++11 traversalconvert.cpp -o traversalconvert.o
	@./traversalconvert.o

preorder:
	@g++ -std=c++11 preorder.cpp -o preorder.o
	@./preorder.o

postorder:
	@g++ -std=c++11 postorder.cpp -o postorder.o
	@./postorder.o

clean:
	@\rm -f *.o
