#ifndef HUFFMANSCODING_H
#define HUFFMANSCODING_H

#include <limits.h>

#define MAX_CODE_LENGTH UCHAR_MAX + 1
#define NULL_CHAR '\0'

// Node structure for the Huffman tree
typedef struct Node 
{
    char data;
    int frequency;
    struct Node *left, *right;
} Node;

// Structure for a priority queue node
typedef struct PriorityQueueNode
{
    struct Node *node;
    struct PriorityQueueNode *next;
} PriorityQueueNode;

// Structure for a priority queue
typedef struct PriorityQueue 
{
    struct PriorityQueueNode *front;
} PriorityQueue;

// Function to create a new node
Node* createNode(char data, int frequency);

// Function to create a new priority queue node
PriorityQueueNode* createPriorityQueueNode(Node* node);

// Function to create a new priority queue
PriorityQueue* createPriorityQueue();

// Function to push a node into the priority queue
void push(PriorityQueue* priorityQueue, Node* node);

// Function to pop the front node from the priority queue
Node* pop(PriorityQueue* priorityQueue);

// Function to build the Huffman tree
Node* buildHuffmanTree(char data[], int frequency[], int size_of_data);

// Function to encode characters using the Huffman tree
void encode(Node* root, char str[], int top, char data[], char huffmanCodes[][MAX_CODE_LENGTH]);

// Function to decode the encoded string using the Huffman tree
void decode(Node* root, char encodedStr[]);

// Function to free the allocated memory
void freeTree(Node* root);

#endif