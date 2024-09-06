#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree{
    struct Node* root;
} Tree;

Node* createNode(int value);
Tree* createTree();
void insert(Tree* tree, int value);
Node* insert2(Node* r, int value);

int main(){
    Tree* tree = createTree();
    insert(tree, 10);
    insert(tree, 9);
    insert(tree, 20);
    insert(tree, 15);
    insert(tree, 40);
    printf("%i", tree->root->right->left->value);
    return 0;
}

Node* createNode(int value){
    Node* newNode = malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Error malloc NODE");
    }

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Tree* createTree(){
    Tree* newTree = malloc(sizeof(Tree));

    if(newTree == NULL){
        printf("Error malloc TREE");
    }

    newTree->root = NULL;

    return newTree;
}

void insert(Tree* tree, int value){
    if(tree->root == NULL)
    {
        tree->root = createNode(value);
    }
    else
    {
        tree->root = insert2(tree->root, value);
    }
}

Node* insert2(Node* r, int value){
    if(r == NULL)
    {
        return createNode(value);
    }
    else if(r->value > value) //vai pra esquerda
    {
        r->left = insert2(r->left, value);
    }
    else //vai pra direita
    {
        r->right = insert2(r->right, value);
    }
    return r;
}