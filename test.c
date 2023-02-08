
//連結リスト
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}node;

node *make_node(int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

int main(void)
{
    node *a = make_node(-1);
    //node *right = make_node(-1);

    //a->next = right;
    node *back = a;

    int i = 1;
    node *tmp;
    while (i < 5)
    {
        tmp = make_node(i);
        //tmp->next = right;
        back->next = tmp;
        back = tmp;
        i++;
    }
    printf("%i %i %i %i", a->value, a->next->value, a->next->next->value, a->next->next->next->value);
}
