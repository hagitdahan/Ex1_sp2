#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include "Graph.hpp"
#include <iostream>
#include <cstddef>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
namespace ariel{
    class Dijkstra{
    public:
        static string shortestPathDijkstra(Graph& g, int source, int destination);
    };
}
#endif