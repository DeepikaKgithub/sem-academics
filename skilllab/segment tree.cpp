#include <stdio.h>
#include <stdlib.h>

// Function to find the next power of 2 greater than or equal to n
int nextPowerOf2(int n) {
    int count = 0;

    // Handle the case when n is already a power of 2
    if (n && !(n & (n - 1)))
        return n;

    while (n != 0) {
        count++;
        n >>= 1;
    }

    return (1 << count);
}

// Function to construct the segment tree
void constructSegmentTree(int arr[], int segmentTree[], int low, int high, int pos) {
    if (low == high) {
        segmentTree[pos] = arr[low];
        return;
    }

    int mid = (low + high) / 2;

    // Recursively build the left and right segments
    constructSegmentTree(arr, segmentTree, low, mid, 2 * pos + 1);
    constructSegmentTree(arr, segmentTree, mid + 1, high, 2 * pos + 2);

    // Combine the results of left and right segments
 segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
}

// Function to print the constructed segment tree
void printSegmentTree(int segmentTree[], int n) {
    printf("Constructed Segment Tree:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", segmentTree[i]);
    }
    printf("\n");
}

// Driver program
int main() {
    int arr[] = {3, 4, 1, 5, 8, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Size of the segment tree
    int treeSize = nextPowerOf2(n) * 2 - 1;

    // Allocate memory for the segment tree and initialize to zero
    int* segmentTree = (int*)calloc(treeSize, sizeof(int));

    // Construct the segment tree
    constructSegmentTree(arr, segmentTree, 0, n - 1, 0);

    // Print the constructed segment tree
    printSegmentTree(segmentTree, treeSize);

    // Free allocated memory
    free(segmentTree);

}