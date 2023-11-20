#ifndef KRUSKALALGORITHM
#define KRUSKALALGORITHM

// a structure to represent a weighted edge in graph
typedef struct Edge
{
	int src;
    int dest;
    int weight;
} Edge;

// a structure to represent a connected, undirected and weighted graph
typedef struct Graph
{
	int vertices, numberOfEdges;

	// graph is represented as an array of edges. Since the graph is
	// undirected, the edge from src to dest is also edge from dest
	// to src. Both are counted as 1 edge here.
	struct Edge* edge;
} Graph;

// A structure to represent a subset for union-find
typedef struct Subset
{
	int parent;
	int rank;
} Subset;

Graph* createGraph(int vertices, int numberOfEdges);

int find(Subset subsets[], int i);

void Union(Subset subsets[], int x, int y);

int myComp(const void* a, const void* b);

void KruskalMST(Graph* graph);

#endif