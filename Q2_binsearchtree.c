#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new item to the BST
// BST 
struct Node* BSTInsert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = BSTInsert(root->left, data);
    } else if (data > root->data) {
        root->right = BSTInsert(root->right, data);
    }
    return root;
}

// Function to search for an item in the BST
//  
//
struct Node* BSTSearch(struct Node* root, int data, struct Node** parent) {
    struct Node* current = root;
    *parent = NULL;
    while (current != NULL && current->data != data) {
        *parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

// Function to find the minimum element in the BST
// key - check both root and root left
// similarly for findmax also check both root and root right
struct Node* BST_Findmin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum element in the BST
struct Node* BST_findmax(struct Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to find the inorder successor of a node
struct Node* BST_Successor(struct Node* root, struct Node* node) {
    if (node->right != NULL) {
        return BST_Findmin(node->right);
    }
    struct Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

// To find successor in binary search tree
// 

// Function to find the inorder predecessor of a node
struct Node* BST_Predecessor(struct Node* root, struct Node* node) {
    if (node->left != NULL) {
        return BST_findmax(node->left);
    }
    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            root = root->left;
        } else if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            break;
        }
    }
    return predecessor;
}

// Function to delete a node from the BST
struct Node* BSTDelete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = BSTDelete(root->left, data);
    } else if (data > root->data) {
        root->right = BSTDelete(root->right, data);
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
        struct Node* temp = BST_Findmin(root->right);
        root->data = temp->data;
        root->right = BSTDelete(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal using a stack
void BSTInorderStack(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    struct Node* parent = NULL;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Inorder Traversal (Stack)\n4. Delete\n5. Find Successor\n6. Find Predecessor\n7. Find Min\n8. Find Max\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = BSTInsert(root, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                struct Node* found = BSTSearch(root, data, &parent);
                if (found != NULL) {
                    printf("Node found with data %d\n", found->data);
                    if (parent != NULL) {
                        printf("Parent node data: %d\n", parent->data);
                    } else {
                        printf("Node is the root\n");
                    }
                } else {
                    printf("Node not found\n");
                }
                break;
            case 3:
                printf("Inorder traversal: ");
                BSTInorderStack(root);
                printf("\n");
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = BSTDelete(root, data);
                break;
            case 5:
                printf("Enter data to find successor: ");
                scanf("%d", &data);
                struct Node* node = BSTSearch(root, data, &parent);
                if (node != NULL) {
                    struct Node* successor = BST_Successor(root, node);
                    if (successor != NULL) {
                        printf("Successor of %d is %d\n", data, successor->data);
                    } else {
                        printf("No successor found\n");
                    }
                } else {
                    printf("Node not found\n");
                }
                break;
            case 6:
                printf("Enter data to find predecessor: ");
                scanf("%d", &data);
                node = BSTSearch(root, data, &parent);
                if (node != NULL) {
                    struct Node* predecessor = BST_Predecessor(root, node);
                    if (predecessor != NULL) {
                        printf("Predecessor of %d is %d\n", data, predecessor->data);
                    } else {
                        printf("No predecessor found\n");
                    }
                } else {
                    printf("Node not found\n");
                }
                break;
            case 7: {
                struct Node* minNode = BST_Findmin(root);
                if (minNode != NULL) {
                    printf("Minimum element is %d\n", minNode->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            }
            case 8: {
                struct Node* maxNode = BST_findmax(root);
                if (maxNode != NULL) {
                    printf("Maximum element is %d\n", maxNode->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            }
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}