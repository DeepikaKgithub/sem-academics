#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of possible characters (assuming lowercase English letters)
#define ALPHABET_SIZE 26

// Trie Node structure
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord; // Flag to mark the end of a word
};

// Function to create a new Trie Node
struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (node) {
        int i;
 for (i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
        node->isEndOfWord = 0;
    }
    return node;
}

// Function to insert a key into the trie
void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* currentNode = root;
    int level;
    int length = strlen(key);

    for (level = 0; level < length; level++) {
        int index = key[level] - 'a'; // Assuming lowercase English letters

        if (!currentNode->children[index]) {
            currentNode->children[index] = createNode();
        }

        currentNode = currentNode->children[index];
    }

    // Mark the end of the word
    currentNode->isEndOfWord = 1;
}
// Function to search for a key in the trie
int search(struct TrieNode* root, const char* key) {
    struct TrieNode* currentNode = root;
    int level;
    int length = strlen(key);

    for (level = 0; level < length; level++) {
 int index = key[level] - 'a'; // Assuming lowercase English letters

        if (!currentNode->children[index]) {
            return 0; // Key not found
        }

        currentNode = currentNode->children[index];
    }

    return (currentNode != NULL && currentNode->isEndOfWord);
}


// Driver program
int main() {
    struct TrieNode* root = createNode();

    // Insert keys into the trie
    insert(root, "hear");
    insert(root, "heart");
    insert(root, "hen");
    insert(root, "heap");
    insert(root, "trim");
    insert(root, "tree");

    // Example: Search for keys in the trie
    printf("Search for 'hear': %s\n", search(root, "hear") ? "Found" : "Not Found");
    printf("Search for 'trim': %s\n", search(root, "trim") ? "Found" : "Not Found");
    printf("Search for 'orange': %s\n", search(root, "orange") ? "Found" : "Not Found");

}