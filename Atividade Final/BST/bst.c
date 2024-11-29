// Gustavo Raasch Müller
// CC4N

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na BST
Node* insert(Node* root, int value) {
    // Se a árvore está vazia, cria um novo nó
    if (root == NULL) {
        return createNode(value);
    }
    
    // Caso contrário, recorre para a posição correta
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Função para buscar um valor na BST
Node* search(Node* root, int value) {
    // Se a raiz é nula ou o valor está na raiz
    if (root == NULL || root->data == value) {
        return root;
    }
    
    // Se o valor é menor que a raiz, busca na subárvore esquerda
    if (value < root->data) {
        return search(root->left, value);
    }
    
    // Se o valor é maior que a raiz, busca na subárvore direita
    return search(root->right, value);
}

// Função para encontrar o nó com o menor valor
Node* minValueNode(Node* node) {
    Node* current = node;
    
    // Percorre até o nó mais à esquerda
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Função para remover um nó
Node* removeNode(Node* root, int value) {
    // Se a árvore está vazia
    if (root == NULL) return root;
    
    // Procura o nó a ser removido
    if (value < root->data) {
        root->left = removeNode(root->left, value);
    } else if (value > root->data) {
        root->right = removeNode(root->right, value);
    } else {
        // Nó com apenas um filho ou sem filhos
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Nó com dois filhos: pega o sucessor in-order (menor da subárvore direita)
        Node* temp = minValueNode(root->right);
        
        // Copia o valor do sucessor para este nó
        root->data = temp->data;
        
        // Remove o sucessor
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

// Função para imprimir em-ordem (in-order traversal)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Função principal para demonstração
int main() {
    Node* root = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    // Inserindo valores
    printf("Inserindo valores na BST:\n");
    for (int i = 0; i < n; i++) {
        root = insert(root, valores[i]);
        printf("Inserido: %d\n", valores[i]);
    }
    
    // Impressão em ordem
    printf("\nÁrvore em ordem: ");
    inorderTraversal(root);
    printf("\n");
    
    // Busca de um valor
    int valorBusca = 40;
    Node* encontrado = search(root, valorBusca);
    printf("\nBuscando %d: %s\n", 
           valorBusca, 
           encontrado ? "Encontrado" : "Não encontrado");
    
    // Remoção de um valor
    int valorRemover = 30;
    printf("\nRemovendo %d\n", valorRemover);
    root = removeNode(root, valorRemover);
    
    // Impressão após remoção
    printf("Árvore após remoção em ordem: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}