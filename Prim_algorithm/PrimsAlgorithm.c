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
    
    // Allocate memory for the Edge structure
    newEdge->edge = (Edge*)malloc(sizeof(Edge)); 

    if(!newEdge->edge)
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

    newQueue->front = createPriorityQueueEdge(edge->weight, edge->name); // Initialize front node

    return newQueue;
}


int minDistance(Graph* graph, bool visited[], int dist[])
{
    int min = INFINITY;
	int min_index, i;

    for(i = 0; i < graph->vertices; i++) 
    {
        // If the node is not visited and the current distance
        // is shorter assign it to the new value
        if((!visited[i]) && (dist[i] <= min)) 
        {
            min = dist[i];
            min_index = i; // Get the index of the current nearest node
        }
    }

    return min_index;
}

void primsAlgorithm(Graph* graph, int source)
{
    bool visited[graph->vertices];  // Keeps track of that if the node has been visited or not (0, 1)
    int dist[graph->vertices];      // Keeps the current distances to each point and updates if found shorter path

    // Assigning all the edges as default
    for(int i = 0; i < graph->vertices; i++) 
    {
        dist[i] = INFINITY;
        visited[i] = false;
    }

    // The distance to the source edge is always 0
    dist[source] = 0;

    for(int count = 0; count < graph->vertices - 1; count++) 
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int minDist = minDistance(graph, visited, dist);

        // Mark the picked vertex as processed
        visited[minDist] = true;

        // Update the distance value of the neighboring vertices of the picked vertex.
        for(int i = 0; i < graph->vertices; i++)
        {
            if(!visited[i] && 
                graph->matrix[minDist][i].weight && 
                graph->matrix[minDist][i].weight < dist[i])
            {
                dist[i] = graph->matrix[minDist][i].weight;
            }
        }
    }

    printSolution(graph, dist);
}

// Function that inserts a node into the graph
// The function takes five arguments:
void addEdge(Graph* graph, int position_x, int position_y, char* name, int weight)
{
    // Assignning the weight of the node in the graph
    graph->matrix[position_x][position_y].weight = weight;
    graph->matrix[position_y][position_x].weight = weight;
    
    // Assigning the name of the node in the graph
    graph->matrix[position_x][position_y].name = name;
    graph->matrix[position_y][position_x].name = name;
}

Graph* initializeGraph(int vertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    // Allocate memory for the graph
    graph->matrix = (Edge**)malloc((size_t)vertices * sizeof(Edge*));
    for (int i = 0; i < vertices; i++) 
    {
        graph->matrix[i] = (Edge*)malloc((size_t)vertices * sizeof(Edge));
    }

    graph->vertices = vertices;

    // Initialize the graph with default values
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            graph->matrix[i][j].weight = 0;
            graph->matrix[i][j].name = NULL;
        }
    }

    return graph;
}

char* searching_name(Graph* graph, int index_of_searched_name)
{   
    int i, j, validation_index = 0;

    // Irritating the graph only over the main diagonal
    for(i = 0; i < graph->vertices; i++)
    {
        for(j = i; j < graph->vertices; j++)
        {
            if(graph->matrix[i][j].weight != 0) // If the weight is 0 then there is no node in matrix[i][j]
            {
                if(validation_index == index_of_searched_name)
                {
                    return graph->matrix[i][j].name;
                }

                // If the validation_index is not the searched one continue to the next one
                validation_index++;
            }
        }
    }
    
    // Returning NULL pointer in case there is no such index or empty array
    return NULL; 
}

void printSolution(Graph* graph, int dist[])
{
    for(int index = 0; index < graph->vertices; index++)
    {
        if(index != graph->vertices - 1)
        {
            printf("%s(%d)->", 
                searching_name(graph, index), dist[index]);
            continue;
        }    

        printf("%s(%d)", 
            searching_name(graph, index), dist[index]);
    }
}

void freeGraph(Graph* graph)
{
    for(int i = 0; i < graph->vertices; i++) 
    {
        free(graph->matrix[i]);
    }

    free(graph->matrix);
    free(graph);    
}