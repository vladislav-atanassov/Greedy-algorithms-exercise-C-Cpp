// C program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "KruskalAlgorithm.h"

Graph* createGraph(int vertices, int numberOfEdges)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices = vertices;
	graph->numberOfEdges = numberOfEdges;

	graph->edge = (Edge*)malloc((size_t)graph->numberOfEdges * sizeof(Edge));

	return graph;
}

// A utility function to find set of an element i
// (uses path compression technique)
int find(Subset subsets[], int i)
{
	// find root and make root as parent of i (path compression)
	if(subsets[i].parent != i)
    {
    	subsets[i].parent = find(subsets, subsets[i].parent);
    }

	return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(Subset subsets[], int x, int y)
{
	int xRoot = find(subsets, x);
	int yRoot = find(subsets, y);

	// Attach smaller rank tree under Root of high rank tree
	// (Union by Rank)
	if(subsets[xRoot].rank < subsets[yRoot].rank)
    {
		subsets[xRoot].parent = yRoot;
    }
	else if(subsets[xRoot].rank > subsets[yRoot].rank)
    {
		subsets[yRoot].parent = xRoot;
    }
	else 
	{    
        // If ranks are same, then make one as Root and
        // increment its rank by one
		subsets[yRoot].parent = xRoot;
		subsets[xRoot].rank++;
	}
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;

	return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph)
{
	int vertices = graph->vertices;
	Edge result[vertices]; // This will store the resultant MST
	int e = 0;      // An index variable, used for result[]
	int i = 0;      // An index variable, used for sorted edges

	// Step 1: Sort all the edges in non-decreasing order of their weight
	// If we are not allowed to change the given graph, we can create a copy of
	// array of edges
	qsort(graph->edge, (size_t)graph->numberOfEdges, sizeof(graph->edge[0]), myComp);

	// Allocate memory for creating vertices subsets
	Subset *subsets = (Subset*)malloc((size_t)vertices * sizeof(Subset));

	// Create vertices subsets with single elements
	for(i = 0; i < vertices; i++)
	{
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}

	// Number of edges to be taken is equal to vertices-1
	while(e < vertices - 1)
	{
		// Step 2: Pick the smallest edge. And increment the index
		// for next iteration
		Edge nextEdge = graph->edge[i++];

		int x = find(subsets, nextEdge.src);
		int y = find(subsets, nextEdge.dest);

		// If including this edge does't cause cycle, include it
		// in result and increment the index of result for next edge
		if(x != y)
		{
			result[e++] = nextEdge;
			Union(subsets, x, y);
		}
		// Else discard the nextEdge
	}

	// print the contents of result[] to display the built MST
	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < e; ++i)
		printf("%d -- %d == %d\n", 
            result[i].src, result[i].dest, result[i].weight);
	
    return;
}

