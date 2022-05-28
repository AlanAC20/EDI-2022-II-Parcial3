//
// Created by carca on 18/05/2022.
//
//GRAFOS
//  Estructura de datos compleja
//  Vertices - Elementos que queremos relacionar
//      Aristas - Indican cuando un elemento está relacionado con otro

//  Dos tipos de grafos:
//      Dirigidos - Sus aristas tienen dirección
//      No Dirigidos - Sus aristas son bidireccionales

//  Operaciones
//  - Inicializar --- YAP
//  - Insertar vértices --- YAP
//  - Insertar aristas (edges) / relaciones  --- YAP
//  - Eliminar vértices --- TAREA
//  - Eliminar relacionesF
//  - Si existe una relación entre dos vértices
//  - Imprimir - en formato de tabla
//  - Dos tipos de recorrido:
//      - Recorrido en profundidad
//      - Recorrido en ampitud



#include <stdio.h>
#include <string.h>

#include "COLAA.h"
#define GRAPH_CAPACITY 32

typedef struct graph{
    int edges[GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY][20];
    int flag[GRAPH_CAPACITY];
    int size;

}Graph;

void initGraph(Graph *g);
void addVertice(Graph *g, char vertice[20]);
int findVertice(Graph graph, char vertice[20]);
int addEdge(Graph *g, char verticeSource[20], char verticeDestiny[20]);
void printGraph(Graph graph);
void bfs(Graph *graph, char vertice[50]);
void createGraph(Graph *g);
void resetFlags(Graph *g);

int main(){

    Graph graph;
    int relacion;

    initGraph(&graph);

    createGraph(&graph);
    printGraph(graph);

    bfs(&graph, "A");
    resetFlags(&graph);
    printf("\n");
    bfs(&graph, "B");

//    addVertice(&graph, "San Luis potosi");
//    addVertice(&graph, "Queretaro");
//    addVertice(&graph, "Nuevo Leon");
//    addVertice(&graph, "Jalisco");


//    for (int r = 0; r < graph.size; ++r) {
//      for (int c = r; c < graph.size; ++c) {
//
//            printf("%s tiene relacion con %s? (1 -SI, 0 -NO)", graph.vertices[r], graph.vertices[c]);
//            scanf("%d", &relacion);

//            if(relacion == 1)
//                addEdge(&graph, graph.vertices[r], graph.vertices[c]);
//        }
//    }

//    printGraph(graph);

    return 0;
}

void initGraph(Graph *g){
    g->size = 0;

    resetFlags(g);
}

void resetFlags(Graph *g){
    for (int i = 0; i < GRAPH_CAPACITY; ++i) {
        g->flag[i] = 0;
    }
}

void addVertice(Graph *g, char vertice[20]){

    //Posibles validaciones:
    //      1. Revisar que existe espacio
    //      2. Revisar que el vertice no exista ---- TAREA

    if(g->size < GRAPH_CAPACITY){ //Todavía puedo insertar

        //Debería validar que el vertice no existe
        strcpy(g->vertices[g->size], vertice);

        for (int r = 0; r < GRAPH_CAPACITY; ++r) {
            g->edges[r][g->size] = 0;
        }

        for (int c = 0; c < GRAPH_CAPACITY; ++c) {
            g->edges[g->size][c] = 0;
        }

        g->size++;
    }
}

int findVertice(Graph graph, char vertice[20]){
    int i;
    int result = -1; /// Que el valor no va a estar en el arreglo

    for (i = 0; i < graph.size && result == -1; ++i) {
        if (strcmp(graph.vertices[i], vertice) == 0)
            result = i;
    }
    return result;
    
}

// SLP, QTO
int addEdge(Graph *g, char verticeSource[20], char verticeDestiny[20]){

    int posSource = findVertice(*g, verticeSource);  // 0
    int posDestiny = findVertice(*g, verticeDestiny);  //  1

    if(posSource != -1 && posDestiny != -1){ //Encontró los dos vertices

        g->edges[posSource][posDestiny] = 1;
        g->edges[posDestiny][posSource] = 1;

        return 1;
    }
    return 0;

}

void printGraph(Graph graph){

    printf("\t");
    for (int i = 0; i < graph.size; ++i) {

        printf("[%s]\t", graph.vertices[i]);
    }
    printf("\n");

    printf("\n");
    for (int r = 0; r < graph.size; ++r) {

        printf("[%s]\t", graph.vertices[r]);
        for (int c = 0; c < graph.size; ++c) {

            printf("%d\t", graph.edges[r][c]);
        }
        printf("\n");

    }
}
void createGraph(Graph *g){

    addVertice(g, "A");
    addVertice(g, "B");
    addVertice(g, "C");
    addVertice(g, "D");
    addVertice(g, "E");
    addVertice(g, "F");
    addVertice(g, "G");
    addVertice(g, "H");

    addEdge(g, "A", "B");
    addEdge(g, "A", "D");
    addEdge(g, "A", "E");
    addEdge(g, "A", "G");
    addEdge(g, "B", "C");
    addEdge(g, "B", "E");
    addEdge(g, "D", "H");
    addEdge(g, "G", "H");
}




//Recorrido en amplitud - BFS - Breath First Search
void bfs(Graph *graph, char vertice[70]){

    Cola colaVertice;
    int posVertice = findVertice(*graph, vertice);
    char verticeActual[70];

    inicializaCola(&colaVertice);

    graph->flag[posVertice] = 1; // Marcando el vertice como visitado
    insertar(&colaVertice, vertice);

    while (!estaVacia(colaVertice)){

        eliminar(&colaVertice, verticeActual);
        posVertice = findVertice(*graph, verticeActual);
        printf("%s  ", verticeActual);

        //Meter las relaciones de ese vertice
        for (int i = 0; i < graph->size; ++i) {

            if(posVertice != i && graph->edges[posVertice][i] == 1 && graph->flag[i] == 0){

                graph->flag[i] = 1;
                insertar(&colaVertice, graph->vertices[i]);

            }
        }
    }
}























