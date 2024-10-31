// Gustavo Raasch Müller
// CC4N

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar o vetor com Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) { // Encontra o menor elemento do vetor
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o elemento encontrado com o primeiro elemento
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int arr[50];
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    
    // Preenche o vetor com números aleatórios entre 1 e 100
    for(int i = 0; i < 50; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    printf("Vetor original:\n");
    printArray(arr, 50);
    
    selectionSort(arr, 50);
    
    printf("\nVetor ordenado com Selection Sort:\n");
    printArray(arr, 50);
    
    return 0;
}