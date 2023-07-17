#include <stdio.h>
#include <stdlib.h>

// AVL tree node
struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

// Function to calculate the height of a node
int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with the given data
struct AVLNode* newNode(int data) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to right rotate subtree rooted with y
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return the new root
    return x;
}

// Function to left rotate subtree rooted with x
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return the new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
struct AVLNode* insert(struct AVLNode* node, int data) {
    // Perform the normal BST insertion
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Duplicate keys are not allowed
        return node;

    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Check the balance factor and perform necessary rotations
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to print the AVL tree in in-order traversal
void inOrder(struct AVLNode* node) {
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

// Function to free the memory allocated for the AVL tree
void freeAVLTree(struct AVLNode* node) {
    if (node == NULL)
        return;

    freeAVLTree(node->left);
    freeAVLTree(node->right);
    free(node);
}

int main() {
    struct AVLNode* root = NULL;
    int data;
    char command;

    printf("AVL Tree Runtime Execution\n");
    printf("Enter 'I' to insert a node or 'Q' to quit:\n");

    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        if (command == 'Q' || command == 'q') {
            break;
        } else if (command == 'I' || command == 'i') {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    printf("In-order traversal of the AVL tree: ");
    inOrder(root);
    printf("\n");

    freeAVLTree(root);

    return 0;
}
