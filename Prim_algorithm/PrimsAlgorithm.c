#include <stdio.h>
#include <stdlib.h>

#include "PrimsAlgorithm.h"

PriorityQueueEdge* createPriorityQueueEdge(int weight, char* name)
{
    PriorityQueueEdge* newEdge = (PriorityQueueEdge*)malloc(sizeof(PriorityQueueEdge));

    if(!newEdge)
    {
        perror("Memory allocation failed!");
        exit(1);
    }

    newEdge->edge->weight = weight;
    newEdge->edge->name = name;
    newEdge->next = NULL;

    return newEdge;
}

PriorityQueue* createPriorityQueue(Edge* edge)
{
    PriorityQueue* newQueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));

    if(!newQueue)
    {
        perror("Memory allocation failed!");
        exit(1);
    }

    newQueue->front->edge = edge;
    newQueue->front->next = NULL;

    return newQueue;
}
