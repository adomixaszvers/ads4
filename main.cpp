#include <iostream>
#include "graph.h"

int main() {
	Graph graph;
	Vertex a;
	a.name_of_owner = "Nzn";
	a.weight = 5;
	graph("what", "lol") = a;
	a.weight = 88;
	std::cout << graph("what", "lol").name_of_owner << ' ' << graph("what", "lol").weight << std::endl;
	return 0;
}
