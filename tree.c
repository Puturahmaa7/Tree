
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value); 
    }
    if (value < root->data) {
        root->left = insert(root->left, value); 
    } else if (value > root->data) {
        root->right = insert(root->right, value); 
    }
    return root;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left); 
        printf("%d ", root->data); // Cetak data node
        inorder(root->right); 
    }
}

int main() {
    Node* root = NULL;
    int n, value, newElement;

    printf("Berapa banyak elemen awal BST yang ingin Anda masukkan? ");
    scanf("%d", &n);

    printf("Masukkan elemen BST satu per satu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value); 
    }

    printf("BST setelah elemen awal (inorder traversal): ");
    inorder(root);
    printf("\n");
    printf("Masukkan elemen baru untuk disisipkan: ");
    scanf("%d", &newElement);

    root = insert(root, newElement);

    printf("BST setelah penyisipan elemen baru (inorder traversal): ");
    inorder(root);
    printf("\n");

    return 0;
}
