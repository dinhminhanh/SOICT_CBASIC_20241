#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POLY 10001

typedef struct TNode
{
    int coef;
    int exp;
    struct TNode *next;
} Node;

Node *P[MAX_POLY];

Node *makeNode(int c, int e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    p->coef = c;
    p->exp = e;
    p->next = NULL;
    return p;
}

void createPoly(int id)
{
    if (P[id] == NULL)
    {
        P[id] = NULL;
    }
}

Node *addTerm(int c, int e, Node *p)
{
    if (p == NULL)
        return makeNode(c, e);
    if (e > p->exp)
    {
        Node *q = makeNode(c, e);
        q->next = p;
        return q;
    }
    if (e == p->exp)
    {
        p->coef += c;
        return p;
    }
    p->next = addTerm(c, e, p->next);
    return p;
}

void processAddTerm(int id, int c, int e)
{
    if (P[id] == NULL)
        createPoly(id);
    P[id] = addTerm(c, e, P[id]);
}

void printPoly(Node *p)
{
    for (Node *q = p; q != NULL; q = q->next)
    {
        printf("%d %d ", q->coef, q->exp);
    }
    printf("\n");
}

Node *addPoly(Node *p1, Node *p2)
{
    Node *prs = NULL;
    Node *last = prs;

    for (Node *q = p1; q != NULL; q = q->next)
    {
        Node *newNode = makeNode(q->coef, q->exp);
        if (prs == NULL)
            prs = newNode;
        else
            last->next = newNode;
        last = newNode;
    }

    for (Node *q = p2; q != NULL; q = q->next)
    {
        prs = addTerm(q->coef, q->exp, prs);
    }

    return prs;
}

void processAddPoly(int id1, int id2, int idrs)
{
    if (P[idrs] != NULL)
    {
        freePoly(P[idrs]);
        P[idrs] = NULL;
    }
    P[idrs] = addPoly(P[id1], P[id2]);
}

void processEvaluatePoly(int id, int x)
{
    long long rs = 0;
    if (P[id] == NULL)
    {
        printf("0\n");
        return;
    }
    for (Node *q = P[id]; q != NULL; q = q->next)
    {
        rs += (long long)q->coef * (long long)pow(x, q->exp);
    }
    printf("%lld\n", rs);
}

void freePoly(Node *p)
{
    while (p != NULL)
    {
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

void processDestroy(int id)
{
    if (P[id] != NULL)
    {
        freePoly(P[id]);
        P[id] = NULL;
    }
}

int main()
{
    char cmd[50];
    int id, c, e, x, id1, id2, idrs;

    for (int i = 0; i < MAX_POLY; i++)
    {
        P[i] = NULL;
    }

    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0)
        {
            break;
        }
        else if (strcmp(cmd, "Create") == 0)
        {
            scanf("%d", &id);
            createPoly(id);
        }
        else if (strcmp(cmd, "AddTerm") == 0)
        {
            scanf("%d%d%d", &id, &c, &e);
            processAddTerm(id, c, e);
        }
        else if (strcmp(cmd, "EvaluatePoly") == 0)
        {
            scanf("%d%d", &id, &x);
            processEvaluatePoly(id, x);
        }
        else if (strcmp(cmd, "AddPoly") == 0)
        {
            scanf("%d%d%d", &id1, &id2, &idrs);
            processAddPoly(id1, id2, idrs);
        }
        else if (strcmp(cmd, "PrintPoly") == 0)
        {
            scanf("%d", &id);
            if (P[id] != NULL)
            {
                printPoly(P[id]);
            }
        }
        else if (strcmp(cmd, "Destroy") == 0)
        {
            scanf("%d", &id);
            processDestroy(id);
        }
    }
    for (int i = 0; i < MAX_POLY; i++)
    {
        if (P[i] != NULL)
        {
            freePoly(P[i]);
        }
    }

    return 0;
}
