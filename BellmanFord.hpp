#ifndef BELLMANFORD_HPP
#define BELLMANFORD_HPP
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <string>
using namespace std;
namespace ariel{
    class BellmanFord{
    public:
        static vector<int> ShortestPathB(Graph &g,int start,int end);
        static vector<int> findNegativeCycle(Graph& g);
    };
}
#endif