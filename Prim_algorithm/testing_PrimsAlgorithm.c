#include <stdio.h>

#include "PrimsAlgorithm.h"

int main()
{
    int vertices = 4;

    Graph* graph = initializeGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1, "A", 1);
    addEdge(graph, 0, 2, "B", 2);
    addEdge(graph, 1, 2, "C", 3);
    addEdge(graph, 1, 3, "D", 4);

    printf("Minimum Spanning Tree Distances:\n");
    primsAlgorithm(graph, 0);

    freeGraph(graph);

    return 0;
}
