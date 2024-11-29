// Gustavo Raasch Müller
// CC4N

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da Árvore AVL
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int altura;
} Node;

// Função para obter a altura de um nó
int altura(Node* N) {
    if (N == NULL)
        return 0;
    return N->altura;
}

// Função para obter o máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->altura = 1;  // Novo nó está inicialmente na altura 1
    return node;
}

// Função para obter o fator de balanceamento de um nó
int getBalanceFactor(Node* N) {
    if (N == NULL)
        return 0;
    return altura(N->left) - altura(N->right);
}

// Rotação para a direita
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    // Realiza a rotação
    x->right = y;
    y->left = T2;
    
    // Atualiza as alturas
    y->altura = max(altura(y->left), altura(y->right)) + 1;
    x->altura = max(altura(x->left), altura(x->right)) + 1;
    
    return x;
}

// Rotação para a esquerda
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    // Realiza a rotação
    y->left = x;
    x->right = T2;
    
    // Atualiza as alturas
    x->altura = max(altura(x->left), altura(x->right)) + 1;
    y->altura = max(altura(y->left), altura(y->right)) + 1;
    
    return y;
}

// Função para inserir um nó na Árvore AVL
Node* insert(Node* node, int value) {
    // 1. Inserção normal de BST
    if (node == NULL)
        return createNode(value);
    
    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else // Valores iguais não são permitidos
        return node;
    
    // 2. Atualiza a altura do nó atual
    node->altura = 1 + max(altura(node->left), altura(node->right));
    
    // 3. Obtém o fator de balanceamento
    int balance = getBalanceFactor(node);
    
    // 4. Balanceamento
    // Caso Esquerda Esquerda
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);
    
    // Caso Direita Direita
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);
    
    // Caso Esquerda Direita
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Caso Direita Esquerda
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

// Função para encontrar o nó com o menor valor
Node* minValueNode(Node* node) {
    Node* current = node;
    
    while (current->left != NULL)
        current = current->left;
    
    return current;
}

// Função para remover um nó da Árvore AVL
Node* removeNode(Node* root, int value) {
    // 1. Remoção padrão de BST
    if (root == NULL)
        return root;
    
    if (value < root->data)
        root->left = removeNode(root->left, value);
    else if (value > root->data)
        root->right = removeNode(root->right, value);
    else {
        // Nó com um ou nenhum filho
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            
            // Caso sem filhos
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // Caso com um filho
                *root = *temp;
            
            free(temp);
        } else {
            // Nó com dois filhos: pega o sucessor in-order
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right, temp->data);
        }
    }
    
    // Se a árvore tinha apenas um nó
    if (root == NULL)
        return root;
    
    // 2. Atualiza a altura
    root->altura = 1 + max(altura(root->left), altura(root->right));
    
    // 3. Obtém o fator de balanceamento
    int balance = getBalanceFactor(root);
    
    // 4. Balanceamento
    // Caso Esquerda Esquerda
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);
    
    // Caso Esquerda Direita
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Caso Direita Direita
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);
    
    // Caso Direita Esquerda
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
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
    printf("Inserindo valores na Árvore AVL:\n");
    for (int i = 0; i < n; i++) {
        root = insert(root, valores[i]);
        printf("Inserido: %d\n", valores[i]);
    }
    
    // Impressão em ordem
    printf("\nÁrvore em ordem: ");
    inorderTraversal(root);
    printf("\n");
    
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