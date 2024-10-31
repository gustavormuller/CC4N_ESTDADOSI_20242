// Gustavo Raasch Müller
// CC4N

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar o vetor com Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    srand(time(NULL));
    
    // Preenche o vetor com números aleatórios de 1 a 100
    for(int i = 0; i < 50; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    printf("Vetor original:\n");
    printArray(arr, 50);
    
    bubbleSort(arr, 50);
    
    printf("\nVetor ordenado com Bubble Sort:\n");
    printArray(arr, 50);
    
    return 0;
}