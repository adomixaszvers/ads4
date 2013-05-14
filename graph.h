#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <forward_list>
#include <map>
#include <string>

struct Vertex {
	int index;
	int weight;
};

class Graph {
public:
	int& operator() (std::string from, std::string to);
private:
	std::vector<std::forward_list<Vertex>> graph;
	std::map<std::string, int> indeces;
};

#endif
