#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head;
Node *tail;

Node *makeNode(int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = x;
    p->next = NULL;
    return p;
}
int queueEmpty()
{
    return head == NULL && tail == NULL;
}
int Pop()
{
    if (queueEmpty())
        return -1;
    Node *tmp = head;
    int v = head->value;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    free(tmp);
    return v;
}
void Push(int v)
{
    Node *p = makeNode(v);
    if (queueEmpty())
    {
        head = p;
        tail = p;
        return;
    }
    tail->next = p;
    tail = p;
}

int main()
{
    head = NULL;
    tail = NULL;
    char c[10];
    do
    {
        scanf("%s", c);
        if (strcmp(c, "#") == 0)
        {
            break;
        }
        else if (strcmp(c, "PUSH") == 0)
        {
            int v;
            scanf("%d", &v);
            Push(v);
        }
        else if (strcmp(c, "POP") == 0)
        {
            if (queueEmpty())
            {
                printf("NULL\n");
            }
            else
            {
                int v = Pop();
                printf("%d\n", v);
            }
        }
    } while (1);
    return 0;
}