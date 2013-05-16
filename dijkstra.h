#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <list>
#include <utility> // for pair
#include <algorithm>
#include <iterator>

#include "graph.h"

class distance_map {
public:
	double& operator[] (const std::string index);
	double at(const std::string index);
private:
	std::map<std::string, double> map;
};

class previous_map {
public:
	std::string& operator[] (const std::string index);
	previous_map& operator= (previous_map& p);
	std::string at(const std::string index);
private:
	std::map<std::string, std::string> map;
};


void DijkstraComputePaths(std::string from,
                          Graph &graph,
                          distance_map &min_distance,
                          std::map<int, std::map<std::string, std::string> > &previous,
			  int number_of_paths);
 
 
std::list<std::string> DijkstraGetShortestPathTo(
    std::string to, std::map<std::string, std::string> &previous);

#endif
