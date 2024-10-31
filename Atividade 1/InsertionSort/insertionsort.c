// Gustavo Raasch Müller
// CC4N

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar o vetor com Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Move os elementos do vetor que são maiores que key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insere key na posição correta
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
    
    insertionSort(arr, 50);
    
    printf("\nVetor ordenado com Insertion Sort:\n");
    printArray(arr, 50);
    
    return 0;
}