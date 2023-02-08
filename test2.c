
//双方向循環リスト
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
    struct node *prev;
}node;

node *make_node(int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

int main(void)
{
    node *a = make_node(-1);
    node *p = make_node(-1);

    a->next = p;
    p->prev = a;

    int i = 1;
    node *tmp;
    while (i < 5)
    {
        tmp = make_node(i);
        tmp->next = p;
        tmp->prev = p->prev;
        p->prev->next = tmp;
        p->prev = tmp;
        i++;
    }
    printf("%i %i %i %i", a->value, a->next->value, a->next->next->value, a->next->next->next->value);
}