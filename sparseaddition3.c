#include <stdio.h>
int main() {
    int A[10][10], B[10][10];
    int TUPLE1[100][3], TUPLE2[100][3], SUM[100][3];
    int sparseSum[10][10] = {0};  // To store the sparse matrix after addition
    int r, c, k1 = 1, k2 = 1, count1 = 0, count2 = 0;

    // Input for Sparse Matrix A
    printf("Enter the number of rows and columns for the sparse matrices: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements for Sparse Matrix A:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input for Sparse Matrix B
    printf("Enter elements for Sparse Matrix B:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Convert Sparse Matrix A to Tuple Matrix TUPLE1
    int i = 0, j = 0;
    while (i < r) {
        while (j < c) {
            if (A[i][j] != 0) {
                TUPLE1[k1][0] = i; // Row
                TUPLE1[k1][1] = j; // Column
                TUPLE1[k1][2] = A[i][j]; // Value
                k1++;
                count1++;
            }
            j++;
        }
        j = 0;
        i++;
    }

    // Set the size and count for TUPLE1
    TUPLE1[0][0] = r;
    TUPLE1[0][1] = c;
    TUPLE1[0][2] = count1;

    // Convert Sparse Matrix B to Tuple Matrix TUPLE2
    i = 0; j = 0;
    while (i < r) {
        while (j < c) {
            if (B[i][j] != 0) {
                TUPLE2[k2][0] = i; // Row
                TUPLE2[k2][1] = j; // Column
                TUPLE2[k2][2] = B[i][j]; // Value
                k2++;
                count2++;
            }
            j++;
        }
        j = 0;
        i++;
    }

    // Set the size and count for TUPLE2
    TUPLE2[0][0] = r;
    TUPLE2[0][1] = c;
    TUPLE2[0][2] = count2;

    // Display TUPLE1
    printf("\nTuple Representation of Sparse Matrix A (TUPLE1):\n");
    for (int i = 0; i <= count1; i++) {
        printf("%d %d %d\n", TUPLE1[i][0], TUPLE1[i][1], TUPLE1[i][2]);
    }

    // Display TUPLE2
    printf("\nTuple Representation of Sparse Matrix B (TUPLE2):\n");
    for (int i = 0; i <= count2; i++) {
        printf("%d %d %d\n", TUPLE2[i][0], TUPLE2[i][1], TUPLE2[i][2]);
    }

    // Sum Tuple Matrices
    int ptr = 1;
    i = 1; j = 1;

    // Start adding tuples based on the cases you mentioned
    while (i <= count1 && j <= count2) {
        // Case 1: TUPLE1[i][0] < TUPLE2[j][0]
        if (TUPLE1[i][0] < TUPLE2[j][0]) {
            SUM[ptr][0] = TUPLE1[i][0];
            SUM[ptr][1] = TUPLE1[i][1];
            SUM[ptr][2] = TUPLE1[i][2];
            i++;

        // Case 2: TUPLE1[i][0] > TUPLE2[j][0]
        } else if (TUPLE1[i][0] > TUPLE2[j][0]) {
            SUM[ptr][0] = TUPLE2[j][0];
            SUM[ptr][1] = TUPLE2[j][1];
            SUM[ptr][2] = TUPLE2[j][2];
            j++;

        // Case 3: TUPLE1[i][0] == TUPLE2[j][0] && TUPLE1[i][1] == TUPLE2[j][1]
        } else if (TUPLE1[i][0] == TUPLE2[j][0] && TUPLE1[i][1] == TUPLE2[j][1]) {
            SUM[ptr][0] = TUPLE1[i][0];
            SUM[ptr][1] = TUPLE1[i][1];
            SUM[ptr][2] = TUPLE1[i][2] + TUPLE2[j][2]; // Add values
            i++;
            j++;

        // Case 4: TUPLE1[i][0] == TUPLE2[j][0] && TUPLE1[i][1] < TUPLE2[j][1]
        } else if (TUPLE1[i][0] == TUPLE2[j][0] && TUPLE1[i][1] < TUPLE2[j][1]) {
            SUM[ptr][0] = TUPLE1[i][0];
            SUM[ptr][1] = TUPLE1[i][1];
            SUM[ptr][2] = TUPLE1[i][2];
            i++;

        // Case 5: TUPLE1[i][0] == TUPLE2[j][0] && TUPLE1[i][1] > TUPLE2[j][1]
        } else if (TUPLE1[i][0] == TUPLE2[j][0] && TUPLE1[i][1] > TUPLE2[j][1]) {
            SUM[ptr][0] = TUPLE2[j][0];
            SUM[ptr][1] = TUPLE2[j][1];
            SUM[ptr][2] = TUPLE2[j][2];
            j++;
        }
        ptr++;
    }

    // Case 6a: Add remaining terms from TUPLE1
    while (i <= count1) {
        SUM[ptr][0] = TUPLE1[i][0];
        SUM[ptr][1] = TUPLE1[i][1];
        SUM[ptr][2] = TUPLE1[i][2];
        i++;
        ptr++;
    }

    // Case 6b: Add remaining terms from TUPLE2
    while (j <= count2) {
        SUM[ptr][0] = TUPLE2[j][0];
        SUM[ptr][1] = TUPLE2[j][1];
        SUM[ptr][2] = TUPLE2[j][2];
        j++;
        ptr++;
    }

    // Set size and count for SUM
    SUM[0][0] = r;
    SUM[0][1] = c;
    SUM[0][2] = ptr - 1;

    // Display SUM Tuple Matrix
    printf("\nResultant SUM Tuple Matrix:\n");
    for (int i = 0; i < ptr; i++) {
        printf("%d %d %d\n", SUM[i][0], SUM[i][1], SUM[i][2]);
    }

    // Convert SUM Tuple Matrix back to Sparse Matrix
    for (int i = 1; i <= SUM[0][2]; i++) {
        int row = SUM[i][0];
        int col = SUM[i][1];
        int value = SUM[i][2];
        sparseSum[row][col] = value;
    }

    // Display the Sparse Matrix obtained from the SUM tuple
    printf("\nSparse Matrix obtained from the SUM Tuple Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", sparseSum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
