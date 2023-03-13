/*
===============================================================================================================================================
Nomes: Lucas Tavares e Ricardo Coutinho Cordeiro

Implementar um programa na linguagem de sua escolha, que permita a representação em memória de um graph.

Este programa deve permitir a entrada dos vertices e os pesos das arestas, considere as seguintes funcionalidades:

Permitir o armazenamento de até 20 vértices

Fazer a leitura dos pesos das arestas de cada vértice

Considerar sempre vértices positivos

Mostrar os dados armazenados

Mostrar o caminho mínimo entre dois vertices solicitados

===============================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 20
#define INFINITY INT_MAX;

int **createGraph(int *numVertex);
void insertVertex(int **graph, int line, int column, int weight);
void insert(int **graph, int numVertex);
void list(int **graph, int numVertex);
void dijkstra(int **graph, int pFirst, int pLast, int numVertex);
void menu(int **graph, int numVertex);

int main() {
    int **graph = NULL, numVertex, pFirst, pLast;
    
    //Cria o grafo e inicializa
    graph = createGraph(&numVertex);

    
    menu(graph, numVertex);

        printf("Informe o ponto Inicial: ");
        scanf("%d", &pFirst);

        printf("Informe o ponto Final: ");
        scanf("%d", &pLast);
        
        dijkstra(graph, pFirst, pLast, numVertex);
}

int **createGraph(int *numVertex) {
    int **newGraph = NULL, i, j;
    do {
        printf("Informe o numero de vertices: ");
        scanf("%d", numVertex);

    } while (*numVertex < 1 || *numVertex > 20);

    newGraph = (int**)malloc((*numVertex) * sizeof(int*));

    if (!newGraph) {
        printf("Erro ao Alocar memoria\n");
        exit(1);
    }

    for (i = 0; i < *numVertex; i++) {
        newGraph[i] = (int*)malloc(*numVertex * sizeof(int));

        if (!newGraph[i]) {
            printf("Erro ao Alocar memoria\n");
            exit(1);
        }
    }

    for (i = 0; i < *numVertex; i++) 
        for (j = 0; j < *numVertex; j++) 
            newGraph[i][j] = INFINITY;
        
    return newGraph;
}

void insertVertex(int **graph, int line, int column, int weight) {
    graph[line][column] = weight;
}

void dijkstra(int **graph, int pFirst, int pLast, int numVertex) {
    int distance[numVertex], previous[numVertex], visited[numVertex], countVertex = 0, shortDistance, lowestIndex = pLast, i;
    
    //Inicializa os vetores auxiliares
    for (i = 0; i < numVertex; i++) {
        distance[i] = graph[pFirst][i];
        previous[i] = pFirst;
        visited[i] = 0;
    }

    //Estabelece a distância do vértice para ele mesmo é zero e marca como visitado
    distance[pFirst] = 0;
    visited[pFirst] = 1;
    countVertex++;

   while (countVertex < numVertex) {
        shortDistance = INFINITY;
        
        for (i = 0; i < numVertex; i++) {
            if (distance[i] < shortDistance && !visited[i]) {
                shortDistance = distance[i];
                lowestIndex = i;
            }
        }
        
        visited[lowestIndex] = 1;
        
        for (i = 0; i < numVertex; i++) {
            if (!visited[i])
                
                if (shortDistance + graph[lowestIndex][i] < distance[i]) {
                    distance[i] = shortDistance + graph[lowestIndex][i];
                    previous[i] = lowestIndex;
                }
        }

        countVertex++;
    }

    printf("Distancia = %d\n", distance[pLast]);

    do {
        pLast = previous[pLast];
        printf("%d ", pLast);
    } while (pLast != pFirst);

    printf("\n");
}

void list(int **graph, int numVertex) {
    int i, j;

    for (i = 0; i < numVertex; i++) {
        for (j = 0; j < numVertex; j++) 
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

void insert(int **graph, int numVertex) {
    int line, column;

    for (line = 0; line < numVertex; line++) {
        for (column = 0; column < numVertex; column++) {
            if(line == column){
                graph[line][column] = 0;
                column++;
            }
            printf("Aresta (%d) em relacao Aresta (%d): ", line, column);
            scanf("%d", &graph[line][column]);
            while(graph[line][column] < 0){
                printf("Peso invalido, digite um peso maior ou igual a 0:\n");
                scanf("%d", &graph[line][column]);
            }
        }
    }
}

void menu(int **graph, int numVertex) {
    int op;

    do {
        printf("1.) Gerar grafo\nEscolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: insert(graph, numVertex);
                    break;
            
            default: printf("Informe uma opcao valida\n");
                     break;
        }
    } while (op != 1);
}

/*
(0) --2-->(1) -- 1 -> (2)
 \        |            ^
  4       3            |
   \      |            |
    v     v            |
   (3) -- 5  -------- (4)
*/