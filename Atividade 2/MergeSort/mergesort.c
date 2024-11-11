// Gustavo Raasch Müller
// CC4N

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para fazer o merge dos arrays L e R em arr
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Cria arrays temporários
    int L[n1], R[n2];
    
    // Copia os dados para os arrays temporários
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    // Merge dos arrays temporários de volta para arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função para ordenar o vetor com Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
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
    
    mergeSort(arr, 0, 49);
    
    printf("\nVetor ordenado com Merge Sort:\n");
    printArray(arr, 50);
    
    return 0;
}