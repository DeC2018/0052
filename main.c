#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isSafe(int* positions, int i, int j) {
    for (int k = 0; k < i; k++) {
        if (positions[k] == j || abs(k - i) == abs(positions[k] - j)) {
            return 0;
        }
    }
    return 1;
}

int recursion(int* positions, int N, int i) {
    int total = 0;

    if (i == N) {
        return 1;
    }

    for (int j = 0; j < N; j++) {
        positions[i] = j;
        if (isSafe(positions, i, j)) {
            total += recursion(positions, N, i + 1);
        }
    }
    return total;
}

int totalNQueens(int n) {
    int sum;
    int* positions = (int*)malloc(n * sizeof(int));
    sum = recursion(positions, n, 0);
    free(positions);
    return sum;
}

int main() {
    int n1 = 4;
    printf("Input: n = %d\n", n1);
    printf("Output: %d\n", totalNQueens(n1));

    int n2 = 1;
    printf("Input: n = %d\n", n2);
    printf("Output: %d\n", totalNQueens(n2));

    return 0;
}
