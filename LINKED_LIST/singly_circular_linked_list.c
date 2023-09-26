#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node*)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *next;
};

struct node* create(unsigned int n)
{
    struct node *f=NULL,*t=NULL,*l=NULL;

    f = NEWNODE;
    printf("Enter the data : ");
    scanf("%d",&f->data);
    f->next = NULL;
    l = f;

    for (int i = 2; i <= n; i++)
    {
        t = NEWNODE;
        printf("Enter the data : ");
        scanf("%d",&t->data);

        t->next = NULL;
        l->next = t;
        l = l->next;
    }

    l->next = f;
    return f;   
}

void display(struct node* f)
{
    struct node* t=NULL;

    t = f;

    printf("\nCIRCULAR LINKED LIST : ");
    do
    {
        printf("%d -> ",t->data);
        t = t->next;
    } while (t != f);
    
}

struct node* free_all(struct node* f)
{
    struct node *t=NULL;

    t = f;

    t = f;
    f = f->next;
    free(t);

    while (f != NULL)
    {
        t = f;
        f = f->next;
        free(t);
    }

    return f;
}

struct node* add_first(struct node* f)
{
    struct node *t=NULL,*s=NULL;

    t = NEWNODE;
    printf("Enter the data : ");
    scanf("%d",&t->data);

    s = f;
    while (s->next != f)
    {
        s = s->next;
    }

    s->next = t;
    t->next = f;

    f = t;

    return f;
} 

struct node* add_last(struct node* f)
{//Has a problem !!!!!!!!!!
    struct node * t=NULL,*s=NULL;

    t = NEWNODE;
    printf("\nEnter the data : ");
    scanf("%d",&t->data);
    t->next = f;

    s = f;
    while (s->next != f)
    {
        s = s->next;
    }

    s->next = t;

    return f;
}

struct node* del_first(struct node *f)
{
    struct node *t=NULL,*s=NULL;

    s = f;
    while (s->next != f)
    {
        s = s->next;
    }

    t = f;
    f = f->next;
    free(t);
    s = f;

    return f;
}

struct node* del_last(struct node* f)
{
    struct node *t=NULL,*s=NULL;

    s = f;
    while (s->next->next != f)
    {
        s = s->next;
    }
    
    t = s->next;
    free(t);
    s->next = f;

    return f;
}

struct node* insert(struct node* f,unsigned int pos)
{
    struct node *t=NULL,*s=NULL;

    if ( pos == 1)
    {
        t = NEWNODE;
        printf("Enter the data : ");
        scanf("%d",&t->data);

        s = f;
        while (s->next != f)
        {
            s = s->next;
        }

        s->next = t;
        t->next = f;

        f = t;

        return f;
    }
    else if(pos == 2)
    {
        t = NEWNODE;
        printf("Enter the data : ");
        scanf("%d",&t->data);

        s = f;

        t->next = f->next;
        f->next = t;

        return f;                  
    }
    else
    {
        t = NEWNODE;
        printf("Enter the data : ");
        scanf("%d",&t->data);

        s = f;
        s = s->next;

        for (int i = 1; i <= (pos - 1) && s != f; i++)
        {
            s = s->next;
        }
        
        if (s == f)
        {
            printf("\nInvalid position ! \n");
            free(t);
            return f;
        }
        else
        {
            t->next = s->next;
            s->next = t;

            return f;
        }
    }

}

struct node* delete(struct node* f,unsigned int pos)
{
    struct node *t=NULL,*s=NULL;

    if ( pos == 1)
    {
    
        s = f;
        while (s->next != f)
        {
            s = s->next;
        }
        
        t = f;
        f = f->next;
        free(t);

        s->next = f;
        return f;
    }
    else if(pos == 2)
    {
        s = f;
        t = s->next;

        s->next = t->next;
        free(t);

        return f;                  
    }
    else
    {
        s = f;
        s = s->next;

        for (int i = 1; i <= (pos - 1) && s != f; i++)
        {
            s = s->next;
        }
        
        if (s == f || s->next == f)
        {
            printf("\nInvalid position ! \n");
            return f;
        }
        else
        {
            t = s->next;
            s->next = t->next;
            free(t);

            return f;
        }
    }
}

int main()
{
    struct node *head=NULL;
    int n;

    printf("\nHow nodes do you want to create : ");
    scanf("%d",&n);

    if (n<1)
    {
        printf("Invalid Number , Number is smaller than 1 Can't create nodes !\n");
        exit(0);
    }

    head = create(n);
    display(head);
    head = add_first(head);
    display(head);
    head = del_first(head);
    display(head);
    head = del_last(head);
    display(head);
    head = add_last(head);
    display(head);
    head = insert(head ,3);
    display(head);
    head = delete(head ,3);
    display(head);
    free_all(head);

    return 0;
}