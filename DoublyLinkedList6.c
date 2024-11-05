/*Exp 6: Write a Menu Driven Program to Perform Insertion, Deletion , and Traversal of nodes in doubly Linked List*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *blink;  // Pointer to previous node
    struct node *flink;  // Pointer to next node
} *head, *tail;

void insert(int val) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->blink = NULL;
    temp->flink = NULL;
    
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->flink = temp;  // Add new node at the end
        temp->blink = tail;  // Set previous pointer of the new node
        tail = temp;          // Update tail to new node
    }
}

void delete(int key) {
    struct node *ptr = head;
    
    // Traverse the list
    while (ptr != NULL) {
        if (ptr->data == key) {  // Node to be deleted found
            if (ptr == head) {  // Deleting the head node
                head = ptr->flink;
                if (head != NULL) {
                    head->blink = NULL;
                }
            } else if (ptr == tail) {  // Deleting the tail node
                tail = ptr->blink;
                if (tail != NULL) {
                    tail->flink = NULL;
                }
            } else {  // Deleting a middle node
                ptr->blink->flink = ptr->flink;
                ptr->flink->blink = ptr->blink;
            }
            free(ptr);  // Free the node memory
            printf("Node with value %d deleted.\n", key);
            return;  // Exit after deleting the node
        }
        ptr = ptr->flink;
    }
    printf("Node with value %d not found.\n", key);
}

void traverse() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Traversal: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->flink;
    }
    printf("\n");
}

int main() {
    int val, ch;
    head = tail = NULL;  // Initialize head and tail as NULL
    
    do {
        printf("1. Insert\t2. Delete\t3. Traverse\t4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("INSERTION\n");
                printf("Enter number to be inserted: ");
                scanf("%d", &val);
                insert(val);
                break;
                
            case 2:
                printf("DELETION\n");
                printf("Enter number to be deleted: ");
                scanf("%d", &val);
                delete(val);
                break;
                
            case 3:
                printf("TRAVERSAL\n");
                traverse();
                break;
                
            case 4:
                printf("EXITING PROGRAM!!!\n");
                break;
                
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 4);
    
    return 0;
}

//SAMPLE OUTPUT
/*
1. Insert    2. Delete    3. Traverse    4. Exit
Enter choice: 1
INSERTION
Enter number to be inserted: 10

1. Insert    2. Delete    3. Traverse    4. Exit
Enter choice: 1
INSERTION
Enter number to be inserted: 20

1. Insert    2. Delete    3. Traverse    4. Exit
Enter choice: 3
TRAVERSAL
Traversal: 10 20 

1. Insert    2. Delete    3. Traverse    4. Exit
Enter choice: 2
DELETION
Enter number to be deleted: 10
Node with value 10 deleted.

1. Insert    2. Delete    3. Traverse    4. Exit
Enter choice: 3
TRAVERSAL
Traversal: 20 

1. Insert    2. Delete    3. Traverse    4. Exit
Enter choice: 4
EXITING PROGRAM!!!
*/
