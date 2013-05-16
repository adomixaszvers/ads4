#include <iostream>
#include "graph.h"

int main() {
	Graph graph;
	Vertex a ("what", 90);
	graph("what", "lol") = a;
	a.weight = 88;
	std::cout << graph("what", "lol").name_of_owner << ' ' << graph("what", "lol").weight << std::endl;
	std::vector<std::string> keys = graph.get_keys();
	for(int i=0; i<keys.size(); i++) {
		std::cout << keys[i] << std::endl;
	}
	return 0;
}
