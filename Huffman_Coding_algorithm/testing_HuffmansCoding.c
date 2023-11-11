#include <stdio.h>
#include <limits.h>

#include "HuffmansCoding.h"

int main() 
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size_of_data = sizeof(data) / sizeof(data[0]);

    struct Node* root = buildHuffmanTree(data, frequency, size_of_data);

    char str[MAX_CODE_LENGTH] = {0};
    char huffmanCodes[UCHAR_MAX][MAX_CODE_LENGTH];
    char encodingData[UCHAR_MAX] = {0};

    encode(root, str, 0, encodingData, huffmanCodes);

    printf("Huffman Codes:\n");
    for(int i = 0; i < size_of_data; ++i) 
    {
        int index = (int)data[i]; // Convert character to integer for array index
        printf("%c : %s\n", data[i], 
                huffmanCodes[index][0] == '\0' ? "Not Found" : huffmanCodes[index]);
    }

    // Example of decoding a string
    char encodedString[] = "111111111100"; // Replace this with your actual encoded string
    decode(root, encodedString);
    
    freeTree(root);

    return 0;
}