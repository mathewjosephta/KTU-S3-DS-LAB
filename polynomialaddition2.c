#include <stdio.h>
int main() {
    int poly1[100][2], poly2[100][2], result[100][2];
    int ptr1, ptr2, rptr = 0;

    // Input for Polynomial 1
    printf("Polynomial 1:\n");
    printf("Enter number of terms: ");
    scanf("%d", &ptr1); // ptr1 represents the number of terms for poly1
    printf("Enter the terms (coefficient and exponent):\n");
    for (int i = 0; i < ptr1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly1[i][0], &poly1[i][1]); // poly1[i][0] = coefficient, poly1[i][1] = exponent
    }

    // Input for Polynomial 2
    printf("Polynomial 2:\n");
    printf("Enter number of terms: ");
    scanf("%d", &ptr2); // ptr2 represents the number of terms for poly2
    printf("Enter the terms (coefficient and exponent):\n");
    for (int i = 0; i < ptr2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly2[i][0], &poly2[i][1]); // poly2[i][0] = coefficient, poly2[i][1] = exponent
    }

    // Add Polynomials
    int i = 0, j = 0;
    while (i < ptr1 && j < ptr2) {
        if (poly1[i][1] > poly2[j][1]) {
            result[rptr][0] = poly1[i][0];
            result[rptr][1] = poly1[i][1];
            i++;
        } else if (poly1[i][1] < poly2[j][1]) {
            result[rptr][0] = poly2[j][0];
            result[rptr][1] = poly2[j][1];
            j++;
        } else {
            result[rptr][0] = poly1[i][0] + poly2[j][0];
            result[rptr][1] = poly1[i][1];
            i++;
            j++;
        }
        rptr++;
    }

    // Add remaining terms of poly1
    while (i < ptr1) {
        result[rptr][0] = poly1[i][0];
        result[rptr][1] = poly1[i][1];
        i++;
        rptr++;
    }

    // Add remaining terms of poly2
    while (j < ptr2) {
        result[rptr][0] = poly2[j][0];
        result[rptr][1] = poly2[j][1];
        j++;
        rptr++;
    }

    // Display Resultant Polynomial
    printf("Resultant Polynomial: ");
    for (int k = 0; k < rptr; k++) {
        if (k > 0 && result[k][0] >= 0) {
            printf("+");
        }
        printf("%dx^%d ", result[k][0], result[k][1]);
    }
    printf("\n");

    return 0;
}
