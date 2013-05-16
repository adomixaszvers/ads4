#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <map>
#include <string>
#include <stdexcept>

struct Vertex {
	Vertex(std::string n, int w);
	Vertex();
	std::string name_of_owner;
	int weight;
	Vertex& operator= (const Vertex& v);
};

class Graph {
public:
	Vertex& operator() (std::string from, std::string to);
	Vertex at(std::string from, std::string to);
	std::set<std::string> get_keys_from();
	std::set<std::string> get_keys_to(std::string from);

private:
	std::map<std::string, std::map<std::string, Vertex> > graph;
	std::set<std::string> keys;
};

#endif
