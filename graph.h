#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>

struct Vertex {
	int index;
	int weight;
};

class Graph {
public:
	int& operator() (std::string from, std::string to);
	int at(std::string from, std::string to);
private:
	std::vector<std::vector<Vertex>> graph;
	std::map<std::string, int> indeces;
};

#endif
