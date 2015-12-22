

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


OBJS = items.o main.o

SRCS = items.cpp main.cpp 

HEADERS = items.hpp

PROGS = ex2

#all: ex1

ex2: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ex2

main.o: main.cpp items.hpp
	${CXX} ${CXXFLAGS} -c main.cpp

items.o: items.cpp items.hpp
	${CXX} ${CXXFLAGS} -c items.cpp

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f ex2 *.o *~

