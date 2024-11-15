#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef, expo;
    struct node *link;
};
struct node *Phead, *Qhead, *Rhead;

// Function to create a new node
struct node* createNode(int coef, int expo) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->link = NULL;
    return newNode;
}

// Read polynomial input
struct node* ReadPoly() {
    struct node *newNode, *ptr, *head = NULL;
    int n, i;

    printf("Enter the total number of terms in the polynomial: ");
    scanf("%d", &n);
    printf("Enter the COEFFICIENTS and EXPONENTS of the polynomial in DESCENDING ORDER\n");
    for (int i = 1; i <= n; i++) {
        printf("Enter (coef%d, expo%d): ", i, i);
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->coef);
        scanf("%d", &newNode->expo);
        newNode->link = NULL;
        if (head == NULL) {
            head = newNode;
            ptr = head;
        } else {
            ptr->link = newNode;
            ptr = newNode;
        }
    }
    return head;
}

// Display polynomial
void DisplayPoly(struct node* head) {
    struct node* ptr;
    if (head == NULL) {
        printf("Polynomial is Empty");
    } else {
        ptr = head;
        while (ptr != NULL) {
            printf("%dx^%d", ptr->coef, ptr->expo);
            if (ptr->link != NULL)
                printf(" + ");
            ptr = ptr->link;
        }
        printf("\n");
    }
}

// Insert term into result polynomial
struct node* InsertTerm(struct node* head, int coef, int expo) {
    struct node *ptr, *newNode;
    if (coef == 0) return head;  // Skip if coefficient is 0

    newNode = createNode(coef, expo);

    if (head == NULL || head->expo < expo) {
        newNode->link = head;
        head = newNode;
    } else {
        ptr = head;
        while (ptr->link != NULL && ptr->link->expo >= expo) {
            if (ptr->link->expo == expo) {
                ptr->link->coef += coef;
                free(newNode);
                return head;
            }
            ptr = ptr->link;
        }
        newNode->link = ptr->link;
        ptr->link = newNode;
    }
    return head;
}

// Multiply two polynomials
struct node* MultiplyPoly(struct node* P, struct node* Q) {
    struct node* result = NULL;
    struct node *ptr1, *ptr2;

    for (ptr1 = P; ptr1 != NULL; ptr1 = ptr1->link) {
        for (ptr2 = Q; ptr2 != NULL; ptr2 = ptr2->link) {
            result = InsertTerm(result, ptr1->coef * ptr2->coef, ptr1->expo + ptr2->expo);
        }
    }
    return result;
}

void main() {
    printf("Enter the details of the First Polynomial\n");
    Phead = ReadPoly();
    printf("\nEnter the details of the Second Polynomial\n");
    Qhead = ReadPoly();

    printf("\nFirst Polynomial: ");
    DisplayPoly(Phead);
    printf("\nSecond Polynomial: ");
    DisplayPoly(Qhead);

    Rhead = MultiplyPoly(Phead, Qhead);
    printf("\nResultant Polynomial (Product): ");
    DisplayPoly(Rhead);
}
