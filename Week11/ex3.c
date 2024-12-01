#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000

typedef struct Node {
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* nodes[MAX_NODES]; // Array to store the nodes
Node* root = NULL;

Node* makeNode(int u) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node* find(Node* r, int u) {
    if (r == NULL) return NULL;
    if (r->id == u) return r;
    Node* p = find(r->leftChild, u);
    if (p != NULL) return p;
    return find(r->rightChild, u);
}

void addLeft(int u, int v, Node* r) {
    Node* p = find(r, v);
    if (p == NULL || p->leftChild != NULL) return;
    p->leftChild = makeNode(u);
    nodes[u] = p->leftChild; // Store the new node in the array
}

void addRight(int u, int v, Node* r) {
    Node* p = find(r, v);
    if (p == NULL || p->rightChild != NULL) return;
    p->rightChild = makeNode(u);
    nodes[u] = p->rightChild; // Store the new node in the array
}

int isMaxHeapHelper(Node* r) {
    if (r == NULL) return 1;
    if (r->leftChild && r->id <= r->leftChild->id) return 0;
    if (r->rightChild && r->id <= r->rightChild->id) return 0;
    return isMaxHeapHelper(r->leftChild) && isMaxHeapHelper(r->rightChild);
}

int isMaxHeap(int u) {
    if (u >= MAX_NODES || nodes[u] == NULL) return 1;
    return isMaxHeapHelper(nodes[u]);
}

int countNodesWithTwoChildrenHelper(Node* r) {
    if (r == NULL) return 0;
    int count = 0;
    // Count if both left and right children exist
    if (r->leftChild && r->rightChild) {
        count = 1;
    }
    // Recursive calls for left and right children
    return count + countNodesWithTwoChildrenHelper(r->leftChild) + countNodesWithTwoChildrenHelper(r->rightChild);
}

int countNodesWithTwoChildren(int u) {
    if (u >= MAX_NODES || nodes[u] == NULL) return 0;
    return countNodesWithTwoChildrenHelper(nodes[u]);
}

int main() {
    char command[50];
    int v, u;
    root = NULL;

    // First set of commands
    while (1) {
        scanf("%s", command);

        if (strcmp(command, "make-root") == 0) {
            scanf("%d", &u);
            root = makeNode(u);
            nodes[u] = root;
        } else if (strcmp(command, "add-left") == 0) {
            scanf("%d %d", &u, &v);
            addLeft(u, v, root);
        } else if (strcmp(command, "add-right") == 0) {
            scanf("%d %d", &u, &v);
            addRight(u, v, root);
        } else if (strcmp(command, "*") == 0) {
            break;
        }
    }

    // Second set of commands
    while (1) {
        scanf("%s", command);

        if (strcmp(command, "is-max-heap") == 0) {
            scanf("%d", &u);
            printf("%d\n", isMaxHeap(u));
        } else if (strcmp(command, "count-nodes-having-2-children") == 0) {
            scanf("%d", &u);
            printf("%d\n", countNodesWithTwoChildren(u));
        } else if (strcmp(command, "***") == 0) {
            break;
        }
    }

    return 0;
}
