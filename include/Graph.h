#ifndef GRAPH_H
#define GRAPH_H
using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	int* result;
	list<int> *adj; // A dynamic array of adjacency lists
public:
	// Constructor and destructor
	 Graph(int V) { this->V= V; result = new int[V]; adj = new list<int>[V]; }
	~Graph()	 { delete [] adj; }

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Prints greedy coloring of the vertices
	void greedyColoring();

	// Returns the appropriate color that should be used for the vertex.
	int whatColor(int u);
};

#endif // GRAPH_H
