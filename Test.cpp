#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
ariel::Graph g;
vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
g.loadGraph(graph);
CHECK(ariel::Algorithms::isConnected(g) == true);

vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
g.loadGraph(graph2);
CHECK(ariel::Algorithms::isConnected(g) == false);
vector<vector<int>> graph3={{0, 1, 0, 0, 0}, 
                {0, 0, -5, 0, 0}, 
                {2, 0, 0, 0, 0}, 
                {0, 0, 0, 0, 2}, 
                {0, 0, 0, 0, 0}};
g.loadGraph(graph3);
CHECK(ariel::Algorithms::isConnected(g)==false);
}

TEST_CASE("Test shortestPath")
{
ariel::Graph g;
vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
g.loadGraph(graph);
CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0 -> 1 -> 2");

vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
g.loadGraph(graph2);
CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "No path exists from source to destination.");

vector<vector<int>> graph3={
            {0, -5, 2, 0},
            {0, 0, 0, 3},
            {0, 0, 0, 0},
            {1, 0, 0, 0}};
g.loadGraph(graph3);
CHECK(ariel::Algorithms::shortestPath(g, 0, 4) =="-1");
vector<vector<int>> graph4={{0, 1, 0, 0, 0}, 
                {0, 0, -5, 0, 0}, 
                {2, 0, 0, 0, 0}, 
                {0, 0, 0, 0, 2}, 
                {0, 0, 0, 0, 0}};
g.loadGraph(graph4);
CHECK(ariel::Algorithms::shortestPath(g,0,2)=="-1");
CHECK(ariel::Algorithms::shortestPath(g,3,4)=="3->4");


}
TEST_CASE("Test isContainsCycle")
{
ariel::Graph g;
vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
g.loadGraph(graph);
CHECK(ariel::Algorithms::isContainsCycle(g) == "No cycle exsist");

vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
g.loadGraph(graph2);
CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0 -> 1 -> 2 -> 0");
}
TEST_CASE("Test isBipartite")
{
ariel::Graph g;
vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
g.loadGraph(graph);
CHECK(ariel::Algorithms::isBipartite(g) == "The Graph is bipartite: A={0 2 }, B={1 }");

vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
g.loadGraph(graph2);
CHECK(ariel::Algorithms::isBipartite(g) == "Graph is not bipartite");

vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
g.loadGraph(graph3);
CHECK(ariel::Algorithms::isBipartite(g) == "The Graph is bipartite: A={0 2 4 }, B={1 3 }");
}
TEST_CASE("Test invalid graph")
{
ariel::Graph g;
vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
CHECK_THROWS(g.loadGraph(graph));
vector<vector<int>> graph2 = {
            {1, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
CHECK_THROWS(g.loadGraph(graph));
}
vector<vector<int>> graph3 = {
            {1}};
TEST_CASE("Negative Cycle"){
ariel::Graph g;
vector<vector<int>> graph={{0, 1, 0, 0, 0}, 
                {0, 0, -5, 0, 0}, 
                {2, 0, 0, 0, 0}, 
                {0, 0, 0, 0, 2}, 
                {0, 0, 0, 0, 0}};
g.loadGraph(graph);
CHECK(ariel::Algorithms::negativeCycle(g)=="the Negative Cycle is:1 2 0 1 ");


}

