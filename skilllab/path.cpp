#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000 // Change this value based on the maximum number of nodes

int parent[MAX_NODES];
int rank[MAX_NODES];

// Function to initialize the DSU data structure
void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Function to find the representative of a set using path compression
int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]); // Path compression: update parent to the root
    }
    return parent[x];
}

// Function to perform union of two sets using rank to optimize the union operation
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }
}

int main() {
    int maxNode = 10; // Assuming the maximum node value is 10
    initialize(maxNode);

    // Perform some union operations
    unionSets(1, 2);
    unionSets(2, 3);
    unionSets(4, 5);
    unionSets(6, 7);
    unionSets(5, 6);
    unionSets(3, 7);

    // Find and print the representatives (parents) of some elements
    printf("The representative of %d is %d\n", 1, find(1));
    printf("The representative of %d is %d\n", 3, find(3));
    printf("The representative of %d is %d\n", 5, find(5));

    return 0;
