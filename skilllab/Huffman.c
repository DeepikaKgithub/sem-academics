#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Huffman tree node
struct Node {
    char data;
    unsigned frequency;
    struct Node *left, *right;
};

// Create a new node with given data and frequency
struct Node* createNode(char data, unsigned frequency) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char data[], unsigned frequency[], int size) {
    struct Node *left, *right, *top;
    struct Node* priorityQueue[size];
    int rear = 0;
    for (int i = 0; i < size; ++i) {
        priorityQueue[rear++] = createNode(data[i], frequency[i]);
         for (int j = rear - 1; j > 0; j--) {
            if (priorityQueue[j]->frequency < priorityQueue[j - 1]->frequency) {
                struct Node* temp = priorityQueue[j];
                priorityQueue[j] = priorityQueue[j - 1];
                priorityQueue[j - 1] = temp;
            } else {
                // If the current element is greater than or equal to the previous one,
                // it is in the correct position, so break out of the loop
                break;
            }
        }
    }

    // Build the Huffman tree
    while (rear > 1) {
        // Extract the two nodes with the lowest frequency
        left = priorityQueue[0];
        right = priorityQueue[1];
        // Remove the two nodes from the priority queue
        for (int i = 0; i < rear - 2; ++i) {
            priorityQueue[i] = priorityQueue[i + 2];
        }
        rear -= 2;

        // Create a new internal node with the sum of frequencies
        top = createNode('$', left->frequency + right->frequency);

        // Make the extracted nodes as the children of the new internal node
        top->left = left;
        top->right = right;

        // Insert the new internal node back into the priority queue
        // Find the correct position to insert the new node
        int i;
        for (i = rear - 1; i >= 0; --i) {
            if (top->frequency >= priorityQueue[i]->frequency) {
                break;
            }
            priorityQueue[i + 1] = priorityQueue[i];
        }
        priorityQueue[i + 1] = top;
        rear++;
    }

    // The root of the Huffman tree is the last node in the priority queue
    return priorityQueue[0];
}

// Function to print the Huffman codes from the root of the Huffman tree
void printHuffmanCodes(struct Node* root, int arr[], int top) {
    // Assign 0 to the left edge and 1 to the right edge in the code array
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    // If it's a leaf node, print the character and its code
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char inputString[] = "blackboard";

    // Count frequencies of characters in the input string
    int frequencies[256] = {0};
    int len = strlen(inputString);
    for (int i = 0; i < len; i++) {
        frequencies[(int)inputString[i]]++;
    }

    // Remove characters with zero frequency
    int validCharacters = 0;
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            validCharacters++;
        }
    }

    // Create arrays to store the characters and their frequencies
    char data[validCharacters];
    int freq[validCharacters];
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            data[index] = (char)i;
            freq[index] = frequencies[i];
            index++;
        }
    }

    // Build the Huffman tree
    struct Node* root = buildHuffmanTree(data, freq, validCharacters);

    // Print the Huffman codes
    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);

    return 0;
}