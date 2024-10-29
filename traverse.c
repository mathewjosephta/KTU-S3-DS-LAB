/*Implementation of BFS and DFS for each graph representations.***/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef enum { false, true } bool;

int adj[MAX][MAX];   // Adjacency matrix
bool visited[MAX];   // Visited nodes
int n;               // Number of nodes in the graph

void create_graph();
void display();
void dfs(int v);
void dfs_rec(int v);
void bfs(int v);
void adj_nodes(int v);
void components();

int main() {
    int choice, v;

    create_graph();

    while (1) {
        printf("\n1. Adjacency matrix\n");
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
                for (int i = 1; i <= n; i++)
                    visited[i] = false;
                dfs(v);
                break;
            case 3:
                printf("Enter starting node for Depth First Search: ");
                scanf("%d", &v);
                for (int i = 1; i <= n; i++)
                    visited[i] = false;
                dfs_rec(v);
                break;
            case 4:
                printf("Enter starting node for Breadth First Search: ");
                scanf("%d", &v);
                for (int i = 1; i <= n; i++)
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
                components();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice\n");
                break;
        }
    }
}

void create_graph() {
    int origin, destin;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0; // Initialize adjacency matrix
        }
    }

    printf("Enter edges (0 0 to quit):\n");
    while (1) {
        printf("Enter edge (origin destination): ");
        scanf("%d %d", &origin, &destin);

        if (origin == 0 && destin == 0) break;

        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            printf("Invalid edge!\n");
        } else {
            adj[origin][destin] = 1;
            // Uncomment the next line if you want to create an undirected graph
            // adj[destin][origin] = 1; 
        }
    }
}

void display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }
}

void dfs_rec(int v) {
    visited[v] = true;
    printf("%d ", v);
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs_rec(i);
        }
    }
}

void dfs(int v) {
    int stack[MAX], top = -1;
    top++;
    stack[top] = v;

    while (top >= 0) {
        int pop_v = stack[top--]; // Pop from stack
        if (!visited[pop_v]) {
            printf("%d ", pop_v);
            visited[pop_v] = true;
        }

        for (int i = n; i >= 1; i--) {
            if (adj[pop_v][i] == 1 && !visited[i]) {
                stack[++top] = i; // Push unvisited neighbors
            }
        }
    }
}

void bfs(int v) {
    int queue[MAX], front = -1, rear = -1;
    queue[++rear] = v;
    visited[v] = true;
    printf("%d ", v);

    while (front < rear) {
        v = queue[++front]; // Dequeue
        for (int i = 1; i <= n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = true;
                queue[++rear] = i; // Enqueue
            }
        }
    }
}

void adj_nodes(int v) {
    printf("Adjacent Vertices: ");
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void components() {
    printf("Components:\n");
    for (int i = 1; i <= n; i++)
        visited[i] = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs_rec(i);
            printf("\n");
        }
    }
}

//SAMPLE OUTPUT
/*
Enter number of nodes: 5
Enter edge 1 (0 0 to quit): 1 2
Enter edge 2 (0 0 to quit): 1 3
Enter edge 3 (0 0 to quit): 2 4
Enter edge 4 (0 0 to quit): 3 5
Enter edge 5 (0 0 to quit): 0 0

1. Adjacency matrix
2. Depth First Search using stack
3. Depth First Search through recursion
4. Breadth First Search
5. Adjacent vertices
6. Components
7. Exit
Enter your choice: 1

Adjacency Matrix
   0   1   2   3   4   5
0   0   0   0   0   0   0
1   0   0   1   1   0   0
2   0   1   0   0   1   0
3   0   1   0   0   0   1
4   0   0   0   0   0   0
5   0   0   0   0   0   0

Enter your choice: 2
Enter starting node for Depth First Search: 1

1 3 5 2 4 

Enter your choice: 3
Enter starting node for Depth First Search: 1

1 2 4 3 5 

Enter your choice: 4
Enter starting node for Breadth First Search: 1

1 2 3 4 5 

Enter your choice: 5
Enter node to find adjacent vertices: 2

Adjacent Vertices are: 1 4 
Enter your choice: 6

1 2 3 4 5 

Enter your choice: 7
*/
