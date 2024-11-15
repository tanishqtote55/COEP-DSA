#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(Graph * gp, int vertices){
    gp->numVertices = vertices;
    gp->adjMatrix = (int **)malloc(sizeof(int *)* vertices);
    for(int  i = 0; i<vertices;i++){
        gp->adjMatrix[i] = (int *)malloc(sizeof(int) * vertices);
        for(int j = 0;j<vertices;j++){
            gp->adjMatrix[i][j] = 0;
        }
    }

}
void addEdge(Graph * gp, int src, int dest){
    gp->adjMatrix[src][dest] = 1;
    gp->adjMatrix[dest][src] = 1;

}
void remoeveEdge(Graph * gp, int src, int dest){
    gp->adjMatrix[src][dest] = 0;
    gp->adjMatrix[dest][src] = 0;

}
void displayGraph(Graph * gp){
    printf("Adjacency Matrix:\n");
    for(int i = 0;i<gp->numVertices;i++){
        for(int j = 0;j<gp->numVertices;j++){
            printf("%d ", gp->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
void freegraph(Graph * gp){
    for(int i = 0;i<gp->numVertices;i++){
        free(gp->adjMatrix[i]);
    }
    free(gp->adjMatrix);
}