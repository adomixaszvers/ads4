#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <map>
#include <string>
#include <stdexcept>
#include <limits>

const double Infinity = std::numeric_limits<double>::infinity();

const std::string UNDEFINED ("UNDEFINED");

struct Vertex {
	Vertex(std::string n, double w);
	Vertex();
	std::string name_of_owner;
	double weight;
	Vertex& operator= (const Vertex& v);
	void operator() (std::string n, double w);
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
