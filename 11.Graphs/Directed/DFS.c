#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertices;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjlist;
} Graph;

void init(Graph* g, int vertices) {
    g->adjlist = (Node**)malloc(sizeof(Node*) * vertices);
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->adjlist[i] = NULL;
    }
}

Node* createNode(int vertices, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertices = vertices;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* gp, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = gp->adjlist[src];
    gp->adjlist[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = gp->adjlist[dest];
    gp->adjlist[dest] = newNode;
}

void printgraph(Graph* gp) {
    for (int i = 0; i < gp->numVertices; i++) {
        Node* temp = gp->adjlist[i];
        printf("\n Vertices: %d ", i);
        while (temp) {
            printf("-> %d (weight: %d)", temp->vertices, temp->weight); // Fixed printing issue
            temp = temp->next;
        }
        printf("\n");
    }
}

// BFS
void BFS(Graph* gp, int sIndex) {
    int* visited = malloc(gp->numVertices * sizeof(int));
    for (int i = 0; i < gp->numVertices; i++) {
        visited[i] = 0;
    }
    int queue[100], front = 0, rear = -1;
    visited[sIndex] = 1;
    queue[++rear] = sIndex;
    while (front <= rear) {
        int cur = queue[front++];
        printf("%d ", cur);
        Node* temp = gp->adjlist[cur];
        while (temp) {
            int adj = temp->vertices;
            if (visited[adj] == 0) {
                queue[++rear] = adj;
                visited[adj] = 1;
            }
            temp = temp->next;
        }
    }
    free(visited);
}
void DFS(Graph * gp, int sVertex){
    int * visited  = calloc(gp->numVertices , sizeof(int));
    for(int i = 0;i<gp->numVertices;i++){
        visited[i] = 0;
    }
    int stack[100];
    int top = -1;
    stack[++top] = sVertex;
    while(top>=0){
        int i = stack[top--];
        if(!visited[i]){
            printf("%d ", i);
            visited[i] = 1;
        }

        Node * temp = gp->adjlist[i];
        while(temp){
            int adj = temp->vertices;
            if(visited[adj] ==0){
                stack[++top] = adj;
            }
            temp = temp->next;
        }
    }
free(visited);
}

int cyclic(Graph *gp, int sVertex) {
    int *visited = calloc(gp->numVertices, sizeof(int));
    int *parent = calloc(gp->numVertices, sizeof(int));
    int stack[100];
    int top = -1;
    stack[++top] = sVertex; // Start with the source vertex
    
    while (top >= 0) {
        int k = stack[top--];
        
        if (!visited[k]) {
            visited[k] = 1;
        }
        
        Node *temp = gp->adjlist[k];
        while (temp) {
            int adj = temp->vertices;
            
            if (!visited[adj]) {
                stack[++top] = adj;
                parent[adj] = k;
            } else if (adj != parent[k]) {
                free(visited);
                free(parent);
                return 1; // Cycle detected
            }
            temp = temp->next;
        }
    }
    
    free(visited);
    free(parent);
    return 0; // No cycle detected
}

int main() {
    // Allocate memory for the Graph structure
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    init(graph, 9);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 3, 5, 3);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 7, 4);
    addEdge(graph, 6, 7, 5);
    addEdge(graph, 6, 8, 4);
    addEdge(graph, 7, 8, 4);
    // Adding a cycle
    addEdge(graph, 8, 0, 2);


    printf("Adjacency list of the graph:\n");
    printgraph(graph);

    printf("\nBFS starting from vertex 0:\n");
    BFS(graph, 0);
    printf("\nDFS starting from vertex 0:\n");
    DFS(graph, 0);
    printf("\n is cyclic or not %d ",cyclic(graph,0));

    // Free memory allocated for the graph
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjlist[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjlist);
    free(graph);

    return 0;
}