#include <stdio.h>

#define N 12

// Function to update the Fenwick Tree (Binary Indexed Tree)
void updateFenwickTree(int BIT[], int index, int value) {
    index++;  // Convert 0-based index to 1-based index
    while (index <= N) {
        BIT[index] += value;
        index += index & -index;  // Move to the next node in the binary indexed tree
    }
}

// Function to construct the Fenwick Tree using the given elements
void constructFenwickTree(int arr[], int BIT[]) {
    for (int i = 0; i < N; i++) {
        updateFenwickTree(BIT, i, arr[i]);
    }
}

// Function to query the prefix sum up to a given index
int query(int BIT[], int index) {
    index++;  // Convert 0-based index to 1-based index
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;  // Move to the parent node in the binary indexed tree
    }
    return sum;
}

// Function to print the Fenwick Tree
void printFenwickTree(int BIT[]) {
 printf("Fenwick Tree (Binary Indexed Tree):\n");
    for (int i = 1; i <= N; i++) {
        printf("%d ", BIT[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

    // Create and initialize the Fenwick Tree (BIT) with zeros
    int BIT[N + 1] = {0};

    // Construct the Fenwick Tree using the given elements
    constructFenwickTree(arr, BIT);

    // Print the Fenwick Tree
    printFenwickTree(BIT);

    // Example queries:
    printf("Prefix sum up to index 5: %d\n", query(BIT, 5));
    printf("Prefix sum up to index 9: %d\n", query(BIT, 9));

}