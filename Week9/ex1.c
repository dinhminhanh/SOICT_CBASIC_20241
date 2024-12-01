#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *top; // pointer to the top of the stack

Node *makeNode(int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
   
    p->value = x;
    p->next = NULL;
    return p;
}

void initStack()
{
    top = NULL;
}

int stackEmpty()
{
    return top == NULL;
}

int Pop()
{
    if (stackEmpty())
        return -1;

    Node *p = top;
    top = top->next;
    int x = p->value;
    free(p);
    return x;
}

void Push(int x)
{
    Node *p = makeNode(x);
    p->next = top;
    top = p;
}

int main()
{
    initStack();

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
            if (stackEmpty())
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
