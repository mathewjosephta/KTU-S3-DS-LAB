/*Exp 7 : Write a C Program to implement a binary search tree(BST) that support dynamic node insertion and traversal in
          IN-ORDER , PRE-ORDER and POSTORDER to efficiently organize and manage data*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return createNode(data);
    }
    
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in left subtree
    } else {
        root->right = insert(root->right, data); // Insert in right subtree
    }
    
    // Return the (unchanged) node pointer
    return root;
}

// Function for in-order traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left); // Visit left subtree
        printf("%d ", root->data); // Print node data
        inorder(root->right); // Visit right subtree
    }
}

// Function for pre-order traversal of the BST
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print node data
        preorder(root->left); // Visit left subtree
        preorder(root->right); // Visit right subtree
    }
}

// Function for post-order traversal of the BST
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left); // Visit left subtree
        postorder(root->right); // Visit right subtree
        printf("%d ", root->data); // Print node data
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data;
    
    // Display menu options and handle user input
    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;  // Return success
}

//SAMPLE OUTPUT
/*
Menu:
1. Insert Node
2. In-order Traversal
3. Pre-order Traversal
4. Post-order Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 50

Menu:
1. Insert Node
2. In-order Traversal
3. Pre-order Traversal
4. Post-order Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 30

Menu:
1. Insert Node
2. In-order Traversal
3. Pre-order Traversal
4. Post-order Traversal
5. Exit
Enter your choice: 2
In-order Traversal: 30 50 

Menu:
1. Insert Node
2. In-order Traversal
3. Pre-order Traversal
4. Post-order Traversal
5. Exit
Enter your choice: 5
Exiting...
*/
