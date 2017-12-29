#include <stdio.h>
#include <stdlib.h>

struct adjListNode {
    int data;
    struct adjListNode* next;
};

struct adjList{
    struct adjListNode* head;
};

struct graph {
    int v;
    struct adjList* array;
};

struct adjListNode* newAdjListNode (int data) {
    struct adjListNode* newNode = (struct adjListNode*)malloc(sizeof(struct adjListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct graph* createGraph (int vertices) {
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->v = vertices;
    
    graph->array = (struct adjList*)malloc(vertices * sizeof(struct adjList));
    
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

void addEdge (struct graph* graph, int src, int dest) {
    struct adjListNode* newnode = newAdjListNode(dest);
    newnode->next = graph->array[src].head;
    graph->array[src].head = newnode;
    
    newnode = newAdjListNode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;
}

void printGraph (struct graph* graph) {
    for(int i = 0; i < graph->v; i++) {
        struct adjListNode* current = graph->array[i].head;
        
        printf("List for vertice %d: ", i);
        while(current) {
            printf("->%d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main(void){
    struct graph* graph = NULL;
    while(1) {
        int option, vertices, src, dest;
        printf("Menu\n");
        printf("1) Create graph\n");
        printf("2) Add edge\n");
        printf("3) Print graph\n");
        printf("4) Exit\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);
                break;
            case 2:
                printf("Enter source: ");
                scanf("%d", &src);
                printf("Enter destination: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                break;
            case 3:
                printGraph(graph);
                break;
            case 4:
                exit(1);
            default:
                printf("Enter valid number!\n");
        }
    }
}
