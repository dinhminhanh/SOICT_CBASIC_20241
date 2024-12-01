#include <stdio.h>
#include <stdlib.h>

typedef struct State {
    int x;
    int y;
} State;

typedef struct Node {
    State t;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

int mark[900][900] = {0};
int num[900][900] = {0};
int a, b, c;
int r[6][2];

Node *makeNode(State t) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p != NULL) {
        p->t = t;
        p->next = NULL;
    }
    return p;
}

void push(State t) {
    Node *p = makeNode(t);
    if (queueEmpty()) {
        head = p;
        tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

int queueEmpty() {
    return head == NULL;
}

State pop() {
    State errorState = {-1, -1};
    if (queueEmpty())
        return errorState;
    
    Node *tmp = head;
    State v = head->t;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    free(tmp);
    return v;
}

void markVisited(int x, int y) {
    mark[x][y] = 1;
}

int isTarget(State t) {
    return t.x == c || t.y == c;
}

int isMarked(State t) {
    return mark[t.x][t.y] == 1;
}

void updateNumSteps(State t, int r) {
    num[t.x][t.y] = r + 1;
}

void nextSteps(State t) {
    // Empty jug A
    r[0][0] = 0;
    r[0][1] = t.y;

    // Fill jug A
    r[1][0] = a;
    r[1][1] = t.y;

    // Empty jug B
    r[2][0] = t.x;
    r[2][1] = 0;

    // Fill jug B
    r[3][0] = t.x;
    r[3][1] = b;

    // Pour water from A to B
    if (t.x + t.y < b) {
        r[4][0] = 0;
        r[4][1] = t.x + t.y;
    } else {
        r[4][0] = t.x + t.y - b;
        r[4][1] = b;
    }

    // Pour water from B to A
    if (t.x + t.y < a) {
        r[5][0] = t.x + t.y;
        r[5][1] = 0;
    } else {
        r[5][0] = a;
        r[5][1] = t.x + t.y - a;
    }
}

int check(int a, int b, int c) {
    State start = {0, 0};
    markVisited(0, 0);
    push(start);

    while (!queueEmpty()) {
        State t = pop();
        nextSteps(t);

        for (int i = 0; i < 6; i++) {
            State next = {r[i][0], r[i][1]};
            if (isTarget(next)) {
                return num[t.x][t.y] + 1;
            }
            if (!isMarked(next)) {
                push(next);
                markVisited(next.x, next.y);
                updateNumSteps(next, num[t.x][t.y]);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &a, &b, &c);
    int result = check(a, b, c);
    printf("%d\n", result);
    return 0;
}
