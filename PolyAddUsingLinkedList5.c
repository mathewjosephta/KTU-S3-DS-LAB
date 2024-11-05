/*Exp 5: Write a Program to add Two Polynomials Using Linked List */

#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term (coefficient and exponent)
struct Node {
    int coeff;  // Coefficient
    int exp;    // Exponent
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial linked list (sorted by exponent in descending order)
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    
    if (*head == NULL || (*head)->exp < exp) {
        // Insert at the beginning or in the middle if exponent is larger
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse to find the correct position
        struct Node* current = *head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        // If exponents are equal, just add the coefficients
        if (current->next != NULL && current->next->exp == exp) {
            current->next->coeff += coeff;
            free(newNode);  // No need to insert a new node if exponents are equal
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        if (head->coeff > 0 && head != head) {
            printf("+");
        }
        printf("%dx^%d ", head->coeff, head->exp);
        head = head->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    struct Node *p1Current = p1, *p2Current = p2;

    while (p1Current != NULL || p2Current != NULL) {
        int coeff = 0;
        int exp = 0;

        if (p1Current != NULL && (p2Current == NULL || p1Current->exp > p2Current->exp)) {
            // If only p1 has the higher exponent, add its term to the result
            coeff = p1Current->coeff;
            exp = p1Current->exp;
            p1Current = p1Current->next;
        } else if (p2Current != NULL && (p1Current == NULL || p2Current->exp > p1Current->exp)) {
            // If only p2 has the higher exponent, add its term to the result
            coeff = p2Current->coeff;
            exp = p2Current->exp;
            p2Current = p2Current->next;
        } else if (p1Current != NULL && p2Current != NULL && p1Current->exp == p2Current->exp) {
            // If both polynomials have the same exponent, add their coefficients
            coeff = p1Current->coeff + p2Current->coeff;
            exp = p1Current->exp;
            p1Current = p1Current->next;
            p2Current = p2Current->next;
        }

        // Insert the result term into the result polynomial
        if (coeff != 0) {
            insertTerm(&result, coeff, exp);
        }
    }

    return result;
}

// Function to take user input for a polynomial
void inputPolynomial(struct Node** poly) {
    int coeff, exp;
    char choice;

    do {
        // Get the coefficient and exponent from the user
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);

        // Insert the term into the polynomial
        insertTerm(poly, coeff, exp);

        // Ask if the user wants to add another term
        printf("Do you want to enter another term? (y/n): ");
        scanf(" %c", &choice);  // Notice the space before %c to consume any leftover newline character
    } while (choice == 'y' || choice == 'Y');
}

// Main function to test the polynomial addition
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Input polynomials from the user
    printf("Enter first polynomial:\n");
    inputPolynomial(&poly1);

    printf("Enter second polynomial:\n");
    inputPolynomial(&poly2);

    // Display the polynomials
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add the polynomials
    struct Node* result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Result of addition: ");
    displayPolynomial(result);

    return 0;
}

//SAMPLE OUTPUT
/*
Enter first polynomial:
Enter coefficient: 5
Enter exponent: 3
Do you want to enter another term? (y/n): y
Enter coefficient: 4
Enter exponent: 2
Do you want to enter another term? (y/n): y
Enter coefficient: 2
Enter exponent: 1
Do you want to enter another term? (y/n): n

Enter second polynomial:
Enter coefficient: 3
Enter exponent: 3
Do you want to enter another term? (y/n): y
Enter coefficient: 2
Enter exponent: 2
Do you want to enter another term? (y/n): y
Enter coefficient: 3
Enter exponent: 1
Do you want to enter another term? (y/n): n

Polynomial 1: 5x^3 +4x^2 +2x^1 
Polynomial 2: 3x^3 +2x^2 +3x^1 
Result of addition: 8x^3 +6x^2 +5x^1
*/
