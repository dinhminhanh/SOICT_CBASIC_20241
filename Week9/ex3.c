#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char value;
    struct Node *next;
} Node;

Node *top = NULL;

Node *makeNode(char ch)
{
    Node *p = (Node *)malloc(sizeof(Node));

    p->value = ch;
    p->next = NULL;
    return p;
}

int stackEmpty()
{
    return top == NULL;
}

void push(char ch)
{
    Node *p = makeNode(ch);
    p->next = top;
    top = p;
}

char topLibrary()
{
    if (stackEmpty()) 
        return '\0';
    return top->value;
}

void popLibrary()
{
    if (top == NULL)
        return;
    Node *p = top;
    top = top->next;
    free(p);
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}

int check(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else
        {
            if (stackEmpty())
                return 0;

            char a = topLibrary();
            popLibrary();

            if (!match(a, s[i]))
                return 0;
        }
    }
    return stackEmpty();
}

int main()
{
    char str[100000];
    scanf("%s", str);
    int result = check(str);
    printf("%d\n", result);
    return 0;
}
