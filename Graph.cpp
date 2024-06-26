//hagitdahan101@gmail.com
//315158568
#include "Graph.hpp"
#include "GraphType.hpp"
using namespace std;
namespace ariel{

    Graph::Graph(): numOfVertices(0), numEdges(0), adjancencyMatrix(), graphType(GraphType::UNDIRECTED), weightType(WeightType::UNWEIGHTED), edgeType(EdgeType::NON_NEGATIVE) {}

    const vector<vector<int>> Graph::getAdjancencyMatrix(){return adjancencyMatrix;}
    bool Graph::isValid(const vector<vector<int>>& matrix){
        // Check if the matrix is square
        size_t size = matrix.size();
        for(size_t j=0;j<size;j++) {
            {
                if (matrix[j].size() != size) {
                    return false;
                }
            }
        }
        //check if there is edge in adj[i][i]
        for(size_t i=0;i<size;i++){
            for(size_t j=0;j<size;j++){
                if(matrix[i][j]!=0 && i==j) return false;
            }
        }
        if(size==1) return false;
        return true;

    }
    //this func create new object Graph and copy the given graph into the object
    void Graph::loadGraph(const vector<vector<int>> &matrix) {
        // Check if the graph is a square matrix
        if (!isValid(matrix)) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        // Load the graph data
        try {
            numOfVertices = matrix.size();
            adjancencyMatrix = matrix;

            // Count the number of edges if needed
            numEdges = 0;
            for (size_t i = 0; i < numOfVertices; ++i) {
                for (size_t j = 0; j < numOfVertices; ++j) {
                    if (adjancencyMatrix[i][j] != 0) {
                        ++numEdges;
                    }
                }
            }
            graphType = GraphType::UNDIRECTED;
            // Check if the graph is directed
            for (size_t i = 0; i < numOfVertices; ++i) {
                for (size_t j = 0; j < numOfVertices; ++j) {
                    if (adjancencyMatrix[i][j] != adjancencyMatrix[j][i]) {
                        graphType = GraphType::DIRECTED;
                        break;
                    }
                }
            }
            if(graphType==GraphType::UNDIRECTED) this->numEdges=this->numEdges/2;
            edgeType = EdgeType::NON_NEGATIVE;
            // Check if there are negative edges
            for (size_t i = 0; i < numOfVertices; ++i) {
                for (size_t j = 0; j < numOfVertices; ++j) {
                    if (adjancencyMatrix[i][j] < 0) {
                        edgeType = EdgeType::ALLOW_NEGATIVE;
                        break;
                    }
                }
            }
            weightType = WeightType::UNWEIGHTED;
            // Check if the edges are weighted
            for (size_t i = 0; i < numOfVertices; ++i) {
                for (size_t j = 0; j < numOfVertices; ++j) {
                    if (adjancencyMatrix[i][j] != 1 && adjancencyMatrix[i][j] != 0) {
                        weightType = WeightType::WEIGHTED;
                        break;
                    }
                }
            }
        } catch (const exception& e) {
            // Handle any exceptions thrown during graph loading
            cerr << "Error loading graph: " << e.what() << endl;
            throw; // Re-throw the exception
        }

    }
    void Graph::printGraph(){
        cout << "Adjacency Matrix:" << endl;
        for (const auto& row : adjancencyMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

    }
    size_t Graph::getNumVertices(){return this->numOfVertices;}
    vector<int> Graph::getNeighbors(int vertex){
        vector<int> neighbors;
        for (size_t i = 0; i < adjancencyMatrix[size_t(vertex)].size(); ++i) {
            if (adjancencyMatrix[size_t(vertex)][i] != 0) {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }
    GraphType Graph::getGraphType(){return this->graphType;}
    WeightType Graph::getWeightType(){return this->weightType;}
    EdgeType Graph::getEdgeType(){return this->edgeType;}
    int Graph::getWeight(int u,int v){return adjancencyMatrix[size_t(u)][size_t(v)];}
    int Graph::getNumEdges() {return this->numEdges;}



}
