/*
===============================================================================================================================================
Nomes: Ricardo Coutinho Cordeiro

Implementar um programa na linguagem de sua escolha, que permita a representação em memória de um grafo.

Este programa deve permitir a entrada dos vértices e os pesos das arestas, considere as seguintes funcionalidades:

Permitir o armazenamento de até 20 vértices

Fazer a leitura dos pesos das arestas de cada vértice

Considerar sempre vértices positivos

Mostrar os dados armazenados

Mostrar o caminho mínimo entre dois vértices solicitados

===============================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define INFINITY 999999

// Função para encontrar o vértice com a menor distância
int dijkstra(int *distancia, int *visitado, int n) {
    int min = INFINITY;
    int ind_min;
    for (int i = 0; i < n; i++) {
        if (!visitado[i] && distancia[i] <= min) {
            min = distancia[i];
            ind_min = i;
        }
    }
    return ind_min;
}

// Função para imprimir a solução
void imprime_caminho(int *caminho, int j) {
    if (caminho[j] == -1) {
        printf("%d ", j);
        return;
    }
    imprime_caminho(caminho, caminho[j]);
    printf("%d ", j);
}

// Função principal
int main() {
    int n, matriz_adjacente[MAX_VERTICES][MAX_VERTICES], origem;
    int distancia[MAX_VERTICES], visitado[MAX_VERTICES], caminho[MAX_VERTICES];

    printf("Digite o número de vértices (até 20): \n");
    scanf("%d", &n);

    // Leitura da matriz de adjacência
    printf("Digite os pesos das arestas: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz_adjacente[i][j]);
        }
    }

    // Leitura do vértice de origem
    printf("Digite o vértice de origem (de 0 a %d): ", n - 1);
    scanf("%d", &origem);

    // Inicialização das variáveis
    for (int i = 0; i < n; i++) {
        distancia[i] = INFINITY;
        visitado[i] = 0;
        caminho[i] = -1;
    }
    distancia[origem] = 0;

    // Execução do algoritmo de Dijkstra
    for (int i = 0; i < n - 1; i++) {
        int u = dijkstra(distancia, visitado, n);
        visitado[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visitado[v] && matriz_adjacente[u][v] && distancia[u] != INFINITY && distancia[u] + matriz_adjacente[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + matriz_adjacente[u][v];
                caminho[v] = u;
            }
        }
    }

    // Impressão das distâncias e dos caminho mínimos
    printf("Distâncias mínimas:\n");
    for (int i = 0; i < n; i++) {
        printf("Vértice %d: %d\n", i, distancia[i]);
    }
    printf("caminho mínimos:\n");
    for (int i = 0; i < n; i++) {
        printf("Caminho para o vértice %d: ", i);
        imprime_caminho(caminho, i);
        printf("\n");
    }

    return 0;
}
