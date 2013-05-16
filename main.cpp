#include <iostream>
#include "graph.h"

int main() {
	Graph graph;
	Vertex a ("what", 90);
	graph("what", "lol") = a;
	graph("what", "ma") = a;
	graph("empty", "kl");
	a.weight = 88;
	std::cout << graph("what", "lol").name_of_owner << ' ' << graph("what", "lol").weight << std::endl;
	auto keys_from = graph.get_keys_from();
	for(auto it_from=keys_from.begin(); it_from!=keys_from.end(); ++it_from) {
		std::cout << "Neighbors of " << *it_from << std::endl;
		auto keys_to = graph.get_keys_to(*it_from);
		for(auto it_to=keys_to.begin(); it_to!=keys_to.end(); ++it_to)
			std::cout << '\t' << *it_to << std::endl;
	}
	return 0;
}
