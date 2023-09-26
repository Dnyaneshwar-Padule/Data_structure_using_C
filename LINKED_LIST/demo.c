#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct friend
{
    char name[12];
    struct friend *next_node;
};

int main(void)
{
    struct friend *P;
    struct friend *Q;

    P = (struct friend* ) malloc(sizeof(struct friend));
    Q = (struct friend* ) malloc(sizeof(struct friend));

    strcpy(P->name,"Me");

    P->next_node = Q;
    Q->next_node = NULL;

    strcpy(Q->name,"Ram");

    printf("\n%s\t%s\n",P->name,P->next_node);

         
    free(P);
    free(Q);
    return 0;
}