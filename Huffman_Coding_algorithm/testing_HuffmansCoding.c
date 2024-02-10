#include <stdio.h>
#include <limits.h>

#include "HuffmansCoding.h"

int main() 
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size_of_data = sizeof(data) / sizeof(data[0]);

    Node* root = buildHuffmanTree(data, frequency, size_of_data);

    char str[MAX_CODE_LENGTH] = {0};
    char huffmanCodes[UCHAR_MAX][MAX_CODE_LENGTH];
    char encodingData[UCHAR_MAX] = {0};

    encode(root, str, 0, encodingData, huffmanCodes);

    printf("Huffman Codes:\n");
    for(int i = 0; i < size_of_data; ++i) 
    {
        int index = (int)data[i]; // Convert character to integer for array index
        printf("%c : %s\n", data[i], 
                huffmanCodes[index][0] == NULL_CHAR ? "Not Found" : huffmanCodes[index]);
    }

    char encodedString[] = "11011000";
    decode(root, encodedString);
    
    freeTree(root);

    return 0;
}