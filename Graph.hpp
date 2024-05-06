
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <cstddef>
#include <iostream>
#include "GraphType.hpp"
using namespace std;
namespace ariel{
    class Graph{
    public:
        Graph();
        bool isValid(const vector<vector<int>>& matrix);
        void loadGraph(const vector<vector<int>>& matrix);
        void printGraph();
        vector<int> getNeighbors(int vertex);
        const vector<vector<int>> getAdjancencyMatrix();
        size_t getNumVertices();
        GraphType getGraphType();
        WeightType getWeightType();
        EdgeType getEdgeTyoe();
        int getWeight(int u,int v);
        //~Graph();

    private:
        vector <vector<int>> adjancencyMatrix;
        size_t numOfVertices;
        int numEdges;
        GraphType graphType;
        WeightType weightType;
        EdgeType edgeType;


    };
}
#endif
