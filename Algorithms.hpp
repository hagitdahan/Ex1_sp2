

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include "Graph.hpp"
#include "GraphType.hpp"
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <cstddef>
#include <string>
using namespace std;
namespace ariel{
    class Algorithms {
    public:
        //this func chwck that shortest path from one vertex to another one
        static void dfs(Graph&g, int vertex, vector<bool>&visited);

        // Check if the graph is connected
        static bool isConnected(Graph&g);

        // Find the shortest path between two vertices
        static string shortestPath(Graph&g, int source, int destination);

        static string dfsForCycle(int vertex, vector<vector<int>>& graph, vector<string>& colors, vector<int>& parent,vector<int>& visited,GraphType type);

        // Check if the graph contains a cycle
        static string isContainsCycle(Graph& g);

        // Check if the graph is bipartite
        static string isBipartite(Graph& g);

        //Check if the Graph contain Negative Cycle
        static string negativeCycle(Graph& g);

    };
}
#endif /* ALGORITHMS_HPP */


