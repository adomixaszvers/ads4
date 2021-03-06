#include "dijkstra.h"
double& distance_map::operator[] (const std::string index) {
    double& value = map[index];
    return value;
}

double distance_map::at(const std::string index) {
    if (map.find(index) != map.end())
        return map[index];
    else
        return Infinity;
}

previous_map& previous_map::operator= (previous_map& p) {
	p.map = map;
	return *this;
}

std::string& previous_map::operator[] (const std::string index) {
    std::string& value = map[index];
    return value;
}

std::string previous_map::at(const std::string index) {
    if (map.find(index) != map.end())
        return map[index];
    else
        return UNDEFINED;
}

void DijkstraComputePaths(std::string source,
                          Graph &graph,
                          distance_map &min_distance,
			 previous_map &previous)
{
    min_distance[source] = 0;
    std::set<std::pair<double, std::string> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance.at(source), source));

    while (!vertex_queue.empty())
    {
        double dist = vertex_queue.begin()->first;
        std::string u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        // Visit each edge exiting u
        std::set<std::string> keys = graph.get_keys_to(u);
        for (std::set<std::string>::iterator it=keys.begin();
                it!=keys.end();
                ++it)
        {
            std::string v = *it;
            double weight = graph.at(u, v).weight;
            if(graph.at(u, v).name_of_owner == source)
                weight /= 2;
            double distance_through_u = dist + weight;
            if (distance_through_u < min_distance.at(v)) {
                vertex_queue.erase(std::make_pair(min_distance.at(v), v));

                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.insert(std::make_pair(min_distance.at(v), v));

            }
        }
    }
}


std::list<std::string> DijkstraGetShortestPathTo(
    std::string vertex, previous_map &previous)
{
    std::list<std::string> path;
    for ( ; vertex != UNDEFINED; vertex = previous.at(vertex))
        path.push_front(vertex);
    return path;
}
