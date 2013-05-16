#include "graph.h"

Vertex::Vertex(std::string n, double w): name_of_owner(n), weight(w) {}
Vertex::Vertex(): name_of_owner(UNDEFINED), weight(Infinity) {}

Vertex& Vertex::operator= (const Vertex& v) {
	name_of_owner = v.name_of_owner;
	weight = v.weight;
	return *this;
}

void Vertex::operator() (std::string n, double w) {
	name_of_owner = n;
	weight = w;
}

Vertex& Graph::operator() (std::string  from, std::string to) {
	Vertex& vertex=graph[from][to];
	return vertex;
}

Vertex Graph::at(std::string from, std::string to) {
	Vertex vertex;
	if(graph.find(from) == graph.end())
		return vertex;
	if(graph[from].find(to) == graph[from].end())
		return vertex;
	return graph.at(from).at(to);	
}

std::set<std::string> Graph::get_keys_from() {
	std::set<std::string> k;
	std::map<std::string, std::map<std::string, Vertex> >::iterator it;
	for(it=graph.begin(); it!= graph.end(); ++it)
		k.insert(it->first);
	return k;
}

std::set<std::string> Graph::get_keys_to(std::string from) {
	std::set<std::string> k;
	std::map<std::string, Vertex>::iterator it;
	if(graph.find(from) == graph.end())
		return k;
	for(it=graph.at(from).begin(); it!=graph.at(from).end(); ++it)
		k.insert(it->first);
	return k;
}
