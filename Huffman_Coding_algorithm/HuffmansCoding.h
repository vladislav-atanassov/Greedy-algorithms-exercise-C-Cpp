#ifndef HUFFMANSCODING_H
#define HUFFMANSCODING_H

#define MAX_CODE_LENGTH 100

// Node structure for the Huffman tree
struct Node 
{
    char data;
    int frequency;
    struct Node *left, *right;
};

// Structure for a priority queue node
struct PriorityQueueNode
{
    struct Node *node;
    struct PriorityQueueNode *next;
};

// Structure for a priority queue
struct PriorityQueue 
{
    struct PriorityQueueNode *front;
};

// Function to create a new node
struct Node* createNode(char data, int frequency);

// Function to create a new priority queue node
struct PriorityQueueNode* createPriorityQueueNode(struct Node* node);

// Function to create a new priority queue
struct PriorityQueue* createPriorityQueue();

// Function to push a node into the priority queue
void push(struct PriorityQueue* priorityQueue, struct Node* node);

// Function to pop the front node from the priority queue
struct Node* pop(struct PriorityQueue* priorityQueue);

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char data[], int frequency[], int size_of_data);

// Function to encode characters using the Huffman tree
void encode(struct Node* root, char str[], int top, char data[], char huffmanCodes[][MAX_CODE_LENGTH]);

// Function to decode the encoded string using the Huffman tree
void decode(struct Node* root, char encodedStr[]);

// Function to free the allocated memory
void freeTree(struct Node* root);

#endif