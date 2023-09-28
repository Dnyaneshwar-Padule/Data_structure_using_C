#include<stdio.h>
#include<stdlib.h>

#define NEWNODE (struct node*)malloc(sizeof(struct node))
#define BOTTOM NULL

struct node
{
    int data;
    struct node *next;
};

struct node *top;

void isempty()
{
    if (top == BOTTOM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int item)
{
    struct node *t=NULL;

    t = NEWNODE;
    t->data = item;

    top->next = t;

    

}



