#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>
#include <stdexcept>

class Vertex {
public:
	Vertex(std::string n, int w);
	Vertex();
	std::string name_of_owner;
	int weight;
	Vertex& operator= (const Vertex& v);
	friend class Graph;
private:
	int index;
};

class Graph {
public:
	Vertex& operator() (std::string from, std::string to);
	Vertex at(std::string from, std::string to);
	std::vector<std::string> get_keys();

private:
	Vertex& operator() (int from, int to);
	Vertex at(int from, int to);
	std::map<int, std::map<int, Vertex> > graph;
	std::map<std::string, int> indeces;
	void create_uniq(std::string s);
	bool is_in_indeces(std::string s);
	int find_in_graph(int from, int to); //grąžina neigiamą, jei neranda
};

#endif
