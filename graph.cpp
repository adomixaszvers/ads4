#include "graph.h"

Vertex::Vertex(std::string n, int w): name_of_owner(n), weight(w) {}
Vertex::Vertex(): name_of_owner("unknown"), weight(0) {}

Vertex& Vertex::operator= (const Vertex& v) {
	name_of_owner = v.name_of_owner;
	weight = v.weight;
	return *this;
}

bool Graph::is_in_indeces(std::string s) {
	try {
		indeces.at(s);
	} catch (std::out_of_range) {
		return false;
	}
	return true;
}

int Graph::find_in_graph(int from, int to) {
	if(from>graph.size())
		return -1;
	for(int i=0; i<graph[from].size(); i++) {
		if(graph[from][i].index == to)
			return i;
	}
	return -1;
}

void Graph::create_uniq(std::string s) {
	if(!is_in_indeces(s)) {
		indeces[s] = indeces.size();
	}
}


Vertex& Graph::operator() (std::string  from, std::string to) {
	create_uniq(from);
	create_uniq(to);
	Vertex& vertex = operator() (indeces[from], indeces[to]);
	return vertex;
}

Vertex& Graph::operator() (int from, int to) {
	int index = find_in_graph(from, to);
	if(index<0) {
		index = graph[from].size()+1;
	}
	Vertex& vertex = graph[from][index];
	vertex.index = to;
	return vertex;
}

Vertex Graph::at(std::string from, std::string to) {
	return at(indeces.at(from), indeces.at(to));	
}

Vertex Graph::at(int from, int to) {
	int index = find_in_graph(from, to);
	if(index<0) {
		throw;
	}
	return graph.at(from).at(index);
}

std::vector<std::string> Graph::get_keys() {
	std::vector<std::string> keys;
	for(std::map<std::string, int>::iterator it=indeces.begin(); it!= indeces.end(); ++it)
		keys.push_back(it->first);
	return keys;
}
