
TARGET = test
SRCS = main.cc

CXX = clang++
CXXFLAGS= -std=c++11 -Wall

OBJS = $(SRCS:.cc=.o)

execute: resetconsole all
	./$(TARGET).exe

resetconsole:
	reset

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o  $(TARGET).exe

$(OBJS):$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -c -g

clean:
	rm -fr *.o *.exe *.out



