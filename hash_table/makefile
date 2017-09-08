TARGET = test
SRCS = main.cc

CXX = clang++
CXXFLAGS= -std=c++14 -Wall

OBJS = $(SRCS:.cc=.o)

execute: recompile resetconsole all
	./$(TARGET).exe

recompile:
	make clean

resetconsole:
	reset

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o  $(TARGET).exe

$(OBJS):$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -c -g

clean:
	rm -fr *.o *.exe *.out



