CXXFLAGS=-Wall -O3 -ggdb
CC=g++
SOURCES=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SOURCES))

assign:$(OBJS)
	$(CC) -o assign $(OBJS)
depends:$(SOURCES)
	$(CC) -MM $(SOURCES) > depends
include depends
clean:
	rm -f *.o
veryclean:
	rm -f depends *.o assign
