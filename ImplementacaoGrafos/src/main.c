/*
===============================================================================================================================================
Nomes: Lucas Tavares e Ricardo Coutinho Cordeiro

Implementar um programa na linguagem de sua escolha, que permita a representação em memória de um grafo.

Este programa deve permitir a entrada dos vértices e os pesos das arestas, considere as seguintes funcionalidades:

Permitir o armazenamento de até 20 vértices

Fazer a leitura dos pesos das arestas de cada vértice

Considerar sempre vértices positivos

Mostrar os dados armazenados

===============================================================================================================================================
*/

#include <stdio.h>
#include <locale.h>

#define MAX_VERTICES 20

int main() {

	setlocale(LC_ALL,"Portuguese");

    int numVertices, i, j;
    int arestas[MAX_VERTICES][MAX_VERTICES];

    printf("Digite o número de vértices do grafo (até 20): ");
    scanf("%d", &numVertices);

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (i != j) {
                printf("Digite o peso da aresta entre o vértice %d e o vértice %d: ", i, j);
                scanf("%d", &arestas[i][j]);
            } else {
                arestas[i][j] = 0;
            }
        }
    }

	printf("\n");
    printf("Matriz de adjacência:\n");
    printf("\n");

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", arestas[i][j]);
        }
        printf("\n");
    }

	system("pause");

    return 0;
}
