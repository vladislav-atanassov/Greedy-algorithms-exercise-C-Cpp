#ifndef PRIMSALGORITHM_H
#define PRIMSALGORITHM_H

#include <stdbool.h>
#include <limits.h>

#define INFINITY INT_MAX

typedef struct Edge
{
    int weight;
    char* name;
} Edge; 


//? Think about (int vertices) in Graph
typedef struct Graph
{
    Edge** matrix;
    int vertices;
} Graph;

// Structure for a priority queue Edge
typedef struct PriorityQueueEdge
{
    Edge *edge;
    struct PriorityQueueEdge *next;
} PriorityQueueEdge;

// Structure for a priority queue
typedef struct PriorityQueue 
{
    PriorityQueueEdge *front;
} PriorityQueue;

PriorityQueueEdge* createPriorityQueueEdge(int weight, char* name);

PriorityQueue* createPriorityQueue(Edge* edge);

int minDistance(Graph* graph, bool visited[], int dist[]);

void primsAlgorithm(Graph* graph, int source);

void addEdge(Graph* graph, int position_x, int position_y, char* name, int weight);

Graph* initializeGraph(int vertices);

char* searching_name(Graph* graph, int index_of_searched_name);

void printSolution(Graph* graph, int dist[]);

void freeGraph(Graph* graph);

#endif