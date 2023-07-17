#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to find the minimum value node in a given BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform an in-order traversal of the BST (for testing)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    srand(time(NULL));

    int numNumbers;
    printf("Enter the number of random numbers to generate and insert: ");
    scanf("%d", &numNumbers);

    // Generate and insert random numbers into the BST
    printf("Random numbers: ");
    for (int i = 0; i < numNumbers; i++) {
        int randomNumber = rand() % 100 + 1;
        printf("%d ", randomNumber);
        root = insertNode(root, randomNumber);
    }
    printf("\n");

    // Prompt the user to choose a node value to delete
    int valueToDelete;
    printf("Enter the node value to delete: ");
    scanf("%d", &valueToDelete);

    // Perform deletion of the chosen node from the BST
    root = deleteNode(root, valueToDelete);

    // In-order traversal to display the updated BST
    printf("Updated BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
