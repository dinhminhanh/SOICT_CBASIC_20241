#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 50000  

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* nodes[MAX_NODES];
Node* root;

typedef struct TINFO {
    int balanced;
    int hl;  
    int hr;
    int h
} INFO;

Node* makeNode(int id) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void addLeft(int u, int v) {
    if (u >= MAX_NODES || v >= MAX_NODES || nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->left != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->left = p;
    nodes[u] = p;
}

void addRight(int u, int v) {
    if (u >= MAX_NODES || v >= MAX_NODES || nodes[u] != NULL || nodes[v] == NULL) return;
    if (nodes[v]->right != NULL) return;
    Node* p = makeNode(u);
    nodes[v]->right = p;
    nodes[u] = p;
}

INFO visit(Node* r) {
    if (r == NULL) {
        INFO i;
        i.balanced = 1;
        i.h = 0;
        return i;
    }

    INFO i1 = visit(r->left);
    INFO i2 = visit(r->right);
    INFO i;

    i.h = fmax(i1.h, i2.h) + 1;

    if (!i1.balanced || !i2.balanced) {
        i.balanced = 0;
        return i;
    }

    if (abs(i1.h - i2.h) > 1) {
        i.balanced = 0;
    } else {
        i.balanced = 1;
    }

    return i;
}

int main() {
    char command[20];
    int v, u;
    root = NULL;

    memset(nodes, 0, sizeof(nodes));

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = makeNode(u);
            nodes[u] = root;
        } else if (strcmp(command, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            addLeft(u, v);
        } else if (strcmp(command, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            addRight(u, v);
        } else if (strcmp(command, "*") == 0) {
            break;
        }
    }

    INFO result = visit(root);
    printf("%d\n", result.balanced);
    printf("%d\n", result.h);       

    return 0;
}
