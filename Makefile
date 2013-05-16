SOURCE = graph.cpp main.cpp dijkstra.cpp
HEADERS = graph.h dijkstra.h
CXXFLAGS= -std=c++11
CXX=clang++

all: programa

OBJECTS= $(SOURCE:%.cpp=%.o)

$(OBJECTS): $(SOURCE) $(HEADERS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

programa: $(OBJECTS)
	$(CXX) $(OBJECTS) -o programa

debug : $(SOURCE) $(HEADERS) clean
	$(CXX) $(CXXFLAGS) -g -Wall -pedantic $(SOURCE) -o programa

clean:
	$(RM) programa
	$(RM) $(OBJECTS)
