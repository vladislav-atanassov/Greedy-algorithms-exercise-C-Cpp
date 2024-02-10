#include <stdio.h>

#include "KruskalAlgorithm.h"

// Driver program to test above functions
int main()
{
	/* Let us create following weighted graph
			10
		0--------1
		| \	     |
	    6    5   15
		|	   \ |
		2--------3
			4	 
	*/

	int vertices = 4; // Number of vertices in graph
	int numberOfEdges = 5; // Number of edges in graph
	Graph* graph = createGraph(vertices, numberOfEdges);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	KruskalMST(graph);

	return 0;
}