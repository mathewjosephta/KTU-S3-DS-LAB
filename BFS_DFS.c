#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef enum boolean { false, true } bool;
int adj[MAX][MAX];
bool visited[MAX];
int n;    /* Denotes number of nodes in the graph */

// Function declarations
void create_graph();
void display();
void dfs_rec(int v);
void dfs(int v);
void bfs(int v);
void adj_nodes(int v);
void components();

int main() {
    int i, v, choice;
    // clrscr(); // Remove this as it's not standard and not needed for modern systems

    create_graph();
    while (1) {
        printf("\n");
        printf("1. Adjacency matrix\n");
        printf("2. Depth First Search using stack\n");
        printf("3. Depth First Search through recursion\n");
        printf("4. Breadth First Search\n");
        printf("5. Adjacent vertices\n");
        printf("6. Components\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Adjacency Matrix\n");
                display();
                break;
            case 2:
                printf("Enter starting node for Depth First Search: ");
                scanf("%d", &v);
                for (i = 1; i <= n; i++)
                    visited[i] = false;
                dfs(v);
                break;
            case 3:
                printf("Enter starting node for Depth First Search: ");
                scanf("%d", &v);
                for (i = 1; i <= n; i++)
                    visited[i] = false;
                dfs_rec(v);
                break;
            case 4:
                printf("Enter starting node for Breadth First Search: ");
                scanf("%d", &v);
                for (i = 1; i <= n; i++)
                    visited[i] = false;
                bfs(v);
                break;
            case 5:
                printf("Enter node to find adjacent vertices: ");
                scanf("%d", &v);
                printf("Adjacent Vertices are: ");
                adj_nodes(v);
                break;
            case 6:
                printf("Connected Components:\n");
                components();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;  // Exit the program gracefully
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }  // End of while loop
}  // End of main()

// Function to create a graph
void create_graph() {
    int i, max_edges, origin, destin;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++) {
        printf("Enter edge %d (origin and destination) (0 0 to quit): ", i);
        scanf("%d %d", &origin, &destin);

        if ((origin == 0) && (destin == 0))
            break;

        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            printf("Invalid edge! Please try again.\n");
            i--;  // Decrease i to retry this edge input
        } else {
            adj[origin][destin] = 1;
        }
    }  // End of for loop
}

// Function to display adjacency matrix
void display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }
}

// Recursive DFS
void dfs_rec(int v) {
    int i;
    visited[v] = true;
    printf("%d ", v);

    for (i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs_rec(i);
        }
    }
}

// DFS using stack
void dfs(int v) {
    int i, stack[MAX], top = -1, pop_v;
    top++;
    stack[top] = v;

    while (top >= 0) {
        pop_v = stack[top];
        top--;  // Pop from stack

        if (!visited[pop_v]) {
            printf("%d ", pop_v);
            visited[pop_v] = true;
        }

        for (i = n; i >= 1; i--) {
            if (adj[pop_v][i] == 1 && !visited[i]) {
                top++;
                stack[top] = i;  // Push unvisited neighbors
            }
        }
    }
}

// BFS using queue
void bfs(int v) {
    int i, front, rear, que[20];
    front = rear = -1;

    printf("%d ", v);
    visited[v] = true;
    rear++;
    front++;
    que[rear] = v;

    while (front <= rear) {
        v = que[front];  // Dequeue
        front++;

        for (i = 1; i <= n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = true;
                rear++;
                que[rear] = i;
            }
        }
    }
}

// Function to print adjacent nodes of a vertex
void adj_nodes(int v) {
    int i;
    for (i = 1; i <= n; i++) {
        if (adj[v][i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

// Function to print connected components
void components() {
    int i;
    for (i = 1; i <= n; i++)
        visited[i] = false;

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs_rec(i);  // Call DFS for each unvisited node
            printf("\n");
        }
    }
}

//SAMPLE OUTPUT
/*
Enter number of nodes: 5
Enter edge 1 (origin and destination) (0 0 to quit): 1 2
Enter edge 2 (origin and destination) (0 0 to quit): 1 3
Enter edge 3 (origin and destination) (0 0 to quit): 2 4
Enter edge 4 (origin and destination) (0 0 to quit): 2 5
Enter edge 5 (origin and destination) (0 0 to quit): 3 4
Enter edge 6 (origin and destination) (0 0 to quit): 4 5
Enter edge 7 (origin and destination) (0 0 to quit): 0 0

Menu:
1. Adjacency matrix
2. Depth First Search using stack
3. Depth First Search through recursion
4. Breadth First Search
5. Adjacent vertices
6. Components
7. Exit
Enter your choice: 1

Adjacency Matrix

   0   1   1   0   0
   0   0   0   1   1
   0   0   0   1   0
   0   0   0   0   1
   0   0   0   0   0

Menu:
1. Adjacency matrix
2. Depth First Search using stack
3. Depth First Search through recursion
4. Breadth First Search
5. Adjacent vertices
6. Components
7. Exit
Enter your choice: 2

Enter starting node for Depth First Search: 1
1 3 4 5 2 

Menu:
1. Adjacency matrix
2. Depth First Search using stack
3. Depth First Search through recursion
4. Breadth First Search
5. Adjacent vertices
6. Components
7. Exit
Enter your choice: 3

Enter starting node for Depth First Search: 1
1 2 4 5 3 

Menu:
1. Adjacency matrix
2. Depth First Search using stack
3. Depth First Search through recursion
4. Breadth First Search
5. Adjacent vertices
6. Components
7. Exit
Enter your choice: 4

Enter starting node for Breadth First Search: 1
1 2 3 4 5 

Menu:
1. Adjacency matrix
2. Depth First Search using stack
3. Depth First Search through recursion
4. Breadth First Search
5. Adjacent vertices
6. Components
7. Exit
Enter your choice: 5

Enter node to find adjacent vertices: 2
Adjacent Vertices are: 1 4 5

Menu:
1. Adjacency matrix
2. Depth First Search using stack
3. Depth First Search through recursion
4. Breadth First Search
5. Adjacent vertices
6. Components
7. Exit
Enter your choice: 6

Connected Components:
1 2 4 5 3 

Menu:
1. Adjacency matrix
2. Depth First Search using stack
3. Depth First Search through recursion
4. Breadth First Search
5. Adjacent vertices
6. Components
7. Exit
Enter your choice: 7

Exiting...
*/
