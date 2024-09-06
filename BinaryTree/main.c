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
void delete(Tree* tree, int value);
Node* delete2(Node* r, int value);
void inOrder(Tree* tree);
void inOrder2(Node* r);

int main(){
    Tree* tree = createTree();
    insert(tree, 10);
    insert(tree, 9);
    insert(tree, 20);
    insert(tree, 15);
    insert(tree, 40);
    delete(tree, 40);
    inOrder(tree);
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
    else if(r->value < value) //vai pra direita
    {
        r->right = insert2(r->right, value);
    }
    else
    {
        printf("Number %i is already inserted inside the tree.\n", value);
    }
    return r;
}

void delete(Tree* tree, int value){
    if(tree->root != NULL)
    {
        tree->root = delete2(tree->root, value);
    }
    else
    {
        printf("The tree is empty.\n");
    }
}

Node* delete2(Node* r, int value){
    if(r == NULL)
    {
        printf("Value is not inserted inside the tree.\n");
    }
    else if(r->value == value)
    {
        if(r->left == NULL && r->right == NULL)
        {
            free(r);
            r = NULL;
        }
        else if(r->left == NULL)
        {
            r = r->right;
        }
        else if(r->right == NULL)
        {
            r = r->left;
        }
        else //if r has left and right
        {
            //r = r->right;
        }
    }
    else if(r->value > value) //vai pra esquerda
    {
        r->left = delete2(r->left, value);
    }
    else //vai pra direita
    {
        r->right = delete2(r->right, value);
    }
    return r;
}

void inOrder(Tree* tree){
    inOrder2(tree->root);
}

void inOrder2(Node* r){
    if(r->left != NULL)
    {
        inOrder2(r->left);
    }

    printf("%i, ", r->value);

    if(r->right != NULL)
    {
        inOrder2(r->right);
    }
}