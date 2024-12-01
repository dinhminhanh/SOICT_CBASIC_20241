#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elementtype;

struct node_t {
    elementtype element;
    struct node_t *next; 
};

typedef struct node_t Node;
Node *root = NULL;

Node *makeNewNode(elementtype e) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->element = e;
    new_node->next = NULL;
    return new_node;
}

int exists(elementtype e) {
    Node *p = root;
    while (p != NULL) {
        if (p->element == e)
            return 1;
        p = p->next;
    }
    return 0;
}

void insertAtTail(elementtype e) {
    if (exists(e)) return;
    Node *new_node = makeNewNode(e);
    if (root == NULL) {
        root = new_node;
        return;
    }
    Node *p = root;
    while (p->next != NULL)
        p = p->next;
    p->next = new_node;
}

void insertAtHead(elementtype e) {
    if (exists(e)) return;
    Node *new_node = makeNewNode(e);
    new_node->next = root;
    root = new_node;
}

void addAfter(elementtype u, elementtype v) {
    if (!exists(v) || exists(u)) return;
    Node *p = root;
    while (p != NULL) {
        if (p->element == v) {
            Node *new_node = makeNewNode(u);
            new_node->next = p->next;
            p->next = new_node;
            return;
        }
        p = p->next;
    }
}

void addBefore(elementtype u, elementtype v) {
    if (!exists(v) || exists(u)) return;
    if (root->element == v) {
        insertAtHead(u);
        return;
    }
    Node *p = root;
    while (p->next != NULL) {
        if (p->next->element == v) {
            Node *new_node = makeNewNode(u);
            new_node->next = p->next;
            p->next = new_node;
            return;
        }
        p = p->next;
    }
}

void removeNode(elementtype k) {
    if (root == NULL) return;
    if (root->element == k) {
        Node *tmp = root;
        root = root->next;
        free(tmp);
        return;
    }
    Node *p = root;
    while (p->next != NULL) {
        if (p->next->element == k) {
            Node *tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            return;
        }
        p = p->next;
    }
}

void reverse() {
    Node *prev = NULL;
    Node *current = root;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    root = prev;
}

void traverseList() {
    Node *p = root;
    while (p != NULL) {
        printf("%d ", p->element);
        p = p->next;
    }
    printf("\n");
}

void freeList() {
    Node *to_free = root;
    while (to_free != NULL) {
        root = root->next;
        free(to_free);
        to_free = root;
    }
}

void solve() {
    int n, k, u, v;
    char command[20];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        insertAtTail(k);
    }
    
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "#") == 0) break;

        if (strcmp(command, "addlast") == 0) {
            scanf("%d", &k);
            insertAtTail(k);
        } else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &k);
            insertAtHead(k);
        } else if (strcmp(command, "addafter") == 0) {
            scanf("%d%d", &u, &v);
            addAfter(u, v);
        } else if (strcmp(command, "addbefore") == 0) {
            scanf("%d%d", &u, &v);
            addBefore(u, v);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &k);
            removeNode(k);
        } else if (strcmp(command, "reverse") == 0) {
            reverse();
        }
    }
}

int main() {
    solve();
    traverseList();
    freeList();
    return 0;
}
