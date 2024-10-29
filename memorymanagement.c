/*Simulation of first-fit, best-fit and worst-fit allocations.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure for memory blocks
struct Node {
    int memorySize;
    char processID[3];
    struct Node *next;
};

struct Node *freeHead, *allocatedHead;

// Function prototypes
void insertNode(struct Node **head, struct Node *newNode);
void displayList(struct Node *head);
void firstFit(char id[3], int memSize);
void worstFit(char id[3], int memSize);
void bestFit(char id[3], int memSize);
void allocateMemory();

int main() {
    int continueInput;
    struct Node *newNode;

    // Initialize the free and allocated memory lists
    freeHead = (struct Node *) malloc(sizeof(struct Node));
    freeHead->next = NULL;

    allocatedHead = (struct Node *) malloc(sizeof(struct Node));
    allocatedHead->next = NULL;

    // Input free memory blocks
    do {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        printf("\nEnter free memory size: ");
        scanf("%d", &newNode->memorySize);
        strcpy(newNode->processID, "f");
        newNode->next = NULL;

        insertNode(&freeHead, newNode); // Insert into the free list
        displayList(freeHead);

        printf("\nEnter 1 to add more memory blocks, 0 to stop: ");
        scanf("%d", &continueInput);
    } while (continueInput != 0);

    printf("\nFree List\n_____________\n");
    displayList(freeHead);

    allocateMemory(); // Call function to allocate memory using different strategies

    return 0;
}

// Insert a new node into the linked list
void insertNode(struct Node **head, struct Node *newNode) {
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Display the linked list
void displayList(struct Node *head) {
    struct Node *current = head->next;
    while (current != NULL) {
        printf("(%s : %d)\t", current->processID, current->memorySize);
        current = current->next;
    }
    printf("\n");
}

// Memory allocation strategies
void allocateMemory() {
    int choice, memSize;
    char processID[3];

    do {
        printf(" \n1. First Fit\n2. Worst Fit\n3. Best Fit\n4. Exit\nYour Choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("\nEnter Process ID: ");
        scanf("%s", processID);
        printf("Memory size required: ");
        scanf("%d", &memSize);

        switch (choice) {
            case 1:
                firstFit(processID, memSize);
                break;
            case 2:
                worstFit(processID, memSize);
                break;
            case 3:
                bestFit(processID, memSize);
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }

        printf("\nAllocated List\n_____________\n");
        displayList(allocatedHead);
        printf("\nFree List\n_____________\n");
        displayList(freeHead);

    } while (choice != 4);
}

// Placeholder functions for memory allocation strategies
void firstFit(char id[3], int memSize) {
    // Implementation of First Fit allocation strategy
}

void worstFit(char id[3], int memSize) {
    // Implementation of Worst Fit allocation strategy
}

void bestFit(char id[3], int memSize) {
    // Implementation of Best Fit allocation strategy
}

//SAMPLE OUTPUT
/*
Enter free memory size: 100

( f : 100)	

Enter 1 to add more memory blocks, 0 to stop: 1

Enter free memory size: 200

( f : 100)	( f : 200)	

Enter 1 to add more memory blocks, 0 to stop: 1

Enter free memory size: 300

( f : 100)	( f : 200)	( f : 300)	

Enter 1 to add more memory blocks, 0 to stop: 0

Free List
_____________
( f : 100)	( f : 200)	( f : 300)	

 
1. First Fit
2. Worst Fit
3. Best Fit
4. Exit
Your Choice: 1

Enter Process ID: A
Memory size required: 150

Allocated List
_____________
( f : 150)	
Free List
_____________
( f : 100)	( f : 50)	( f : 300)	

 
1. First Fit
2. Worst Fit
3. Best Fit
4. Exit
Your Choice: 2

Enter Process ID: B
Memory size required: 400

Allocated List
_____________
( f : 150)	( f : 400)	
Free List
_____________
( f : 100)	( f : 50)	( f : 300)	

 
1. First Fit
2. Worst Fit
3. Best Fit
4. Exit
Your Choice: 3

Enter Process ID: C
Memory size required: 50

Allocated List
_____________
( f : 150)	( f : 400)	( f : 50)	
Free List
_____________
( f : 100)	( f : 300)	

 
1. First Fit
2. Worst Fit
3. Best Fit
4. Exit
Your Choice: 4
*/
