#ifndef PRIMSALGORITHM_H
#define PRIMSALGORITHM_H

typedef struct Edge
{
    int weight;
    char* name;
} Edge; 


//? Think about (int vertices) in Graph
typedef struct Graph
{
    Edge* edge;
    int** graph;
} Graph;

// Structure for a priority queue Edge
typedef struct PriorityQueueEdge
{
    Edge *edge;
    PriorityQueueEdge *next;
} PriorityQueueEdge;

// Structure for a priority queue
typedef struct PriorityQueue 
{
    PriorityQueueEdge *front;
} PriorityQueue;

PriorityQueueEdge* createPriorityQueueEdge(int weight, char* name);

PriorityQueue* createPriorityQueue(Edge* edge);


#endif