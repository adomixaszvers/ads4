#include <iostream>
#include <fstream>
#include <iomanip>
#include "dijkstra.h"

const char DFPav[] = "duom.txt";

int main() {
    Graph graph;
    /* Vertex a ("what", 90.5);
    graph("what", "lol") = a;
    graph("what", "ma") = a;
    graph("empty", "kl");
    a.weight = 88;
    std::cout << std::setprecision(3) << graph("what", "lol").name_of_owner << ' ' << graph("what", "lol").weight << std::endl;
    auto keys_from = graph.get_keys_from();
    for(auto it_from=keys_from.begin(); it_from!=keys_from.end(); ++it_from) {
    	std::cout << "Neighbors of " << *it_from << std::endl;
    	auto keys_to = graph.get_keys_to(*it_from);
    	for(auto it_to=keys_to.begin(); it_to!=keys_to.end(); ++it_to)
    		std::cout << '\t' << *it_to << std::endl;
    }
    */
    int n;
    std::string from, to;
    std::string f, t, owner;
    std::map<int, previous_map> previous;
    int number_of_paths;
    double weight;
    distance_map min_distance;

    std::ifstream df(DFPav);

    df >> n >> from >> to;
    df.ignore();

    for(int i=0; i<n; i++) {
        df >> f >> t >> owner >> weight;
	std::cout << f << ' ' << t << ' ' << owner << ' ' << weight << " Nuskaite" << std::endl;
        df.ignore();
        graph(f, t).name_of_owner = n;
        graph(f, t).weight = weight;
	graph(t, f).name_of_owner = n;
	graph(t, f).weight = weight;
    }

    df.close();

    auto keys_from = graph.get_keys_from();
    for(auto it_from=keys_from.begin(); it_from!=keys_from.end(); it_from++) {
    	std::cout << "Neighbors of " << *it_from << std::endl;
    	auto keys_to = graph.get_keys_to(*it_from);
    	for(auto it_to=keys_to.begin(); it_to!=keys_to.end(); it_to++)
    		std::cout << '\t' << *it_to << std::endl;
    }


    DijkstraComputePaths(from, graph, min_distance, previous, number_of_paths);

    std::cout << "Kaina " << min_distance.at(to) << std::endl;
    for(int i=0; i<number_of_paths; i++) {
    	std::list<std::string> path = DijkstraGetShortestPathTo(to, previous[i]);
    	std::cout << "Kelias : ";
    	std::copy(path.begin(), path.end(), std::ostream_iterator<std::string>(std::cout, " "));
    	std::cout << std::endl;
    }

    return 0;
}
