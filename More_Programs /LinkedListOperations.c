/*
This program implements a singly linked list with basic operations:
1. Insert at the front
2. Insert at the end
3. Insert after a specified node
4. Delete from the front
5. Delete from the end
6. Delete a specified node
7. Display the list
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *head = NULL; // Initialize head to NULL

// Display the linked list
void Display() {
    struct node *ptr;
    if (head == NULL) {
        printf("Linked List is empty\n");
    } else {
        ptr = head;
        printf("Linked List Elements are : ");
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

// Insert at the front of the linked list
void Insert_Front(int x) {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->link = head;
    head = new;
    Display();
}

// Insert at the end of the linked list
void Insert_End(int x) {
    struct node *new, *ptr;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->link = NULL;
    if (head == NULL) {
        head = new;
    } else {
        ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = new;
    }
    Display();
}

// Insert after a specified node
void Insert_After(int key, int x) {
    struct node *new, *ptr;
    if (head == NULL) {
        printf("Search key not found, insertion is not possible\n");
    } else {
        ptr = head;
        while (ptr->data != key && ptr->link != NULL) {
            ptr = ptr->link;
        }
        if (ptr->data != key) {
            printf("Search data not found. Insertion not possible\n");
        } else {
            new = (struct node *)malloc(sizeof(struct node));
            new->data = x;
            new->link = ptr->link;
            ptr->link = new;
            Display();
        }
    }
}

// Delete from the front of the linked list
void Delete_Front() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty. Deletion not possible\n");
    } else {
        temp = head;
        head = head->link;
        free(temp);
        Display();
    }
}

// Delete from the end of the linked list
void Delete_End() {
    struct node *prev, *curr;
    if (head == NULL) {
        printf("List is empty. Deletion not possible\n");
    } else if (head->link == NULL) {
        free(head);
        head = NULL;
        Display();
    } else {
        prev = head;
        curr = head->link;
        while (curr->link != NULL) {
            prev = curr;
            curr = curr->link;
        }
        prev->link = NULL;
        free(curr);
        Display();
    }
}

// Delete a specified node
void Delete_Any(int key) {
    struct node *prev, *curr;
    if (head == NULL) {
        printf("List is empty. Deletion not possible\n");
    } else if (head->data == key) {
        curr = head;
        head = head->link;
        free(curr);
        Display();
    } else {
        prev = head;
        curr = head->link;
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->link;
        }
        if (curr == NULL) {
            printf("Search data not found. Deletion not possible\n");
        } else {
            prev->link = curr->link;
            free(curr);
            Display();
        }
    }
}

// Main method
int main() {
    int choice, x, key;
    do {
        printf("\n*****MENU*****\n1. Insert at Front\n2. Insert at End\n3. Insert after a node\n4. Delete from Front\n5. Delete from End\n6. Delete the Specified node\n7. Display\n8. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the new data: ");
                scanf("%d", &x);
                Insert_Front(x);
                break;
            case 2:
                printf("Enter the new data: ");
                scanf("%d", &x);
                Insert_End(x);
                break;
            case 3:
                printf("Enter the Search Key: ");
                scanf("%d", &key);
                printf("Enter the new data: ");
                scanf("%d", &x);
                Insert_After(key, x);
                break;
            case 4:
                Delete_Front();
                break;
            case 5:
                Delete_End();
                break;
            case 6:
                printf("Enter the node to be deleted: ");
                scanf("%d", &key);
                Delete_Any(key);
                break;
            case 7:
                Display();
                break;
        }
    } while (choice != 8);
    return 0;
}

//SAMPLE OUTPUT
/*

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 1
Enter the new data: 30
Linked List Elements are : 30	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 1
Enter the new data: 20
Linked List Elements are : 20	30	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 1
Enter the new data: 10
Linked List Elements are : 10	20	30	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 2
Enter the new data: 40
Linked List Elements are : 10	20	30	40	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 3
Enter the Search Key: 40
Enter the new data: 50
Linked List Elements are : 10	20	30	40	50	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 4
Linked List Elements are : 20	30	40	50	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 5
Linked List Elements are : 20	30	40	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 6
Enter the node to be deleted: 20
Linked List Elements are : 30	40	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 7
Linked List Elements are : 30	40	

*****MENU*****
1. Insert at Front
2. Insert at End
3. Insert after a node
4. Delete from Front
5. Delete from End
6. Delete the Specified node
7. Display
8. Exit
Enter Your Choice: 8


=== Code Execution Successful ===
*/
