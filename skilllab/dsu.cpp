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
        parent[x] = find(parent[x]);
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
    int edges[][2] = {{1, 2}, {2, 3}, {4, 5}, {6, 7}, {5, 6}, {3, 7}};
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    int maxNode = 7; // Assuming the maximum node value is 7

    initialize(maxNode);

    printf("Connected components:\n");

    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(u) != find(v)) {
            printf("%d and %d are in different sets. Performing union.\n", u, v);
            unionSets(u, v);
        } else {
            printf("%d and %d are already in the same set. No union needed.\n", u, v);
        }
    }

    return 0;
}
