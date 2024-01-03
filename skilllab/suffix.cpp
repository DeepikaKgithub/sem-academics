#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about suffixes
struct Suffix {
    int index;
    char *suffix;
};

// Comparison function for sorting suffixes
int compareSuffixes(const void *a, const void *b) {
    return strcmp(((struct Suffix *)a)->suffix, ((struct Suffix *)b)->suffix);
}

// Construct the suffix array for a given string
int *buildSuffixArray(char *text, int n) {
    // Create an array of suffix structures
    struct Suffix suffixes[n];

    // Fill in the suffix array with indices and corresponding suffixes
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].suffix = text + i;
    }

    // Sort the suffix array using the comparison function
    qsort(suffixes, n, sizeof(struct Suffix), compareSuffixes);

    // Create an array to store the final suffix array
    int *suffixArray = (int *)malloc(n * sizeof(int));

    // Populate the suffix array with sorted indices
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }

    return suffixArray;
}
// Print the constructed suffix array
void printSuffixArray(int *suffixArray, int n) {
    printf("Suffix Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", suffixArray[i]);
    }
    printf("\n");
}

int main() {
    char text[] = "banana";
    int n = strlen(text);

    // Build and print the suffix array
    int *suffixArray = buildSuffixArray(text, n);
    printSuffixArray(suffixArray, n);

    // Free dynamically allocated memory
    free(suffixArray);
}

