#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "HuffmansCoding.h"

struct Node* createNode(char data, int frequency) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(!newNode)
    {
        perror("Memory allocation failed!");
        exit(1);
    }

    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct PriorityQueueNode* createPriorityQueueNode(struct Node* node) 
{
    struct PriorityQueueNode* newNode = (struct PriorityQueueNode*)malloc(sizeof(struct PriorityQueueNode));

    if(!newNode)
    {
        perror("Memory allocation failed!");
        exit(1);
    }

    newNode->node = node;
    newNode->next = NULL;

    return newNode;
}

struct PriorityQueue* createPriorityQueue() 
{
    struct PriorityQueue* priorityQueue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));

    if(!priorityQueue)
    {
        perror("Memory allocation failed!");
        exit(1);
    }

    priorityQueue->front = NULL;

    return priorityQueue;
}

void push(struct PriorityQueue* priorityQueue, struct Node* node) 
{
    struct PriorityQueueNode* newNode = createPriorityQueueNode(node);

    // If the queue is empty or the new node has a lower frequency
    if(priorityQueue->front == NULL || node->frequency < priorityQueue->front->node->frequency)
    {
        newNode->next = priorityQueue->front;
        priorityQueue->front = newNode;
    } 
    else 
    {
        // Find the correct position to insert the new node
        struct PriorityQueueNode* temp = priorityQueue->front;
        while(temp->next != NULL && temp->next->node->frequency < node->frequency) 
        {
            temp = temp->next;
        }

        // Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

struct Node* pop(struct PriorityQueue* priorityQueue) 
{
    if(priorityQueue->front == NULL) 
    {
        return NULL;
    }

    struct Node* frontNode = priorityQueue->front->node;
    struct PriorityQueueNode* temp = priorityQueue->front;
    priorityQueue->front = priorityQueue->front->next;

    free(temp);
    return frontNode;
}

struct Node* buildHuffmanTree(char data[], int frequency[], int size_of_data) 
{
    struct Node *left, *right, *top;
    struct PriorityQueue* priorityQueue = createPriorityQueue();

    // Create a leaf node for each character and push it into the priority queue
    for(int i = 0; i < size_of_data; ++i) 
    {
        push(priorityQueue, createNode(data[i], frequency[i]));
    }

    // Build the Huffman tree
    while(priorityQueue->front->next != NULL) 
    {
        left = pop(priorityQueue);
        right = pop(priorityQueue);

        top = createNode('\0', left->frequency + right->frequency); // Use a different character, like '\0'
        top->left = left;
        top->right = right;

        push(priorityQueue, top);
    }

    return pop(priorityQueue);
}

void encode(struct Node* root, char str[], int top, char data[], char huffmanCodes[][MAX_CODE_LENGTH]) 
{
    if(root == NULL)
    {
        return;
    }

    // If the node is a leaf node, it contains a character
    if(root->left == NULL && root->right == NULL) 
    {
        data[top] = '\0';
        strcpy(huffmanCodes[(int)root->data], str);
        return;
    }

    // Append '0' to the string and traverse the left subtree
    str[top] = '0';
    encode(root->left, str, top + 1, data, huffmanCodes);

    // Append '1' to the string and traverse the right subtree
    str[top] = '1';
    encode(root->right, str, top + 1, data, huffmanCodes);
}

// Function to decode the encoded string using the Huffman tree
void decode(struct Node* root, char encodedStr[]) 
{
    struct Node* current = root;

    printf("Decoded String: ");
    for (int i = 0; encodedStr[i] != '\0'; ++i) 
    {
        if (encodedStr[i] == '0' && current->left != NULL) 
        {
            current = current->left;
        } 
        else if (encodedStr[i] == '1' && current->right != NULL) 
        {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) 
        {
            printf("%c", current->data);
            current = root; // Reset to the root for the next character
        }
    }

    printf("\n");
}

void freeTree(struct Node* root) 
{
    if(root == NULL) 
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
