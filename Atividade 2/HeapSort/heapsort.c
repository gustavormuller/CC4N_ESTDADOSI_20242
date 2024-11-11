// Gustavo Raasch Müller
// CC4N

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para construir o heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Função para ordenar o vetor com Heap Sort
void heapSort(int arr[], int n) {
    // Constrói o heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[50];
    srand(time(NULL));
    
    // Preenche o vetor com números aleatórios entre 1 e 100
    for(int i = 0; i < 50; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    printf("Vetor original:\n");
    printArray(arr, 50);
    
    heapSort(arr, 50);
    
    printf("\nVetor ordenado com Heap Sort:\n");
    printArray(arr, 50);
    
    return 0;
}