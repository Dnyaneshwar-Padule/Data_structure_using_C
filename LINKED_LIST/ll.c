#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node*)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *next;
};

struct node* create_linked_list(int n)
{
    struct node *f=NULL,*l=NULL,*t=NULL;

    f = NEWNODE;
    if (f == NULL)
    {
        printf("Unable to allocate memory ! ");
        exit(0);
    }
    

    printf("Enter the data : ");
    scanf("%d",&f->data);
    f->next = NULL; 
    l = f;

    for (int i = 2; i <= n; i++)
    {
        t = NEWNODE;
        if (t == NULL)
        {
            printf("Unable to allocate memory !");
            exit(0);
        }

        printf("Enter the data : ");
        scanf("%d",&t->data);

        l->next = t;

        l = l->next;
        l->next = NULL;
    }
     
    return f;

}

void display_linked_list(struct node* f)
{
    struct node *t;

    printf("Linked List : ");   
    for (t = f ; t != NULL ; t = t->next)
    {
        printf(" %d ->",t->data); 

    }
    printf("NULL");
    printf("\n");
}

struct node* free_all(struct node* f)
{
    struct node *t;
    t=f;
    
    while ( f != NULL )
    {
        f = f->next;
        free(t);
        t = f;
    }

    return f;
    
} 

struct node* add_linked_list(struct node* f,int pos)
{
    struct node *t=NULL,*s=NULL;
    int i;

    t = f;
    s = NEWNODE;

    printf("Enter the data : ");
    scanf("%d",&s->data);
    s->next = NULL;

    for ( i = 2; i <= (pos-1); i++)
   {
        t = t->next;
   }
   
   s->next = t->next;
   t->next = s;

   return f;
    

}

struct node* delete_node(struct node* f,int pos)
{
    struct node *t,*s;

    s = f;
    
    for (int  i = 2; i <= (pos-1); i++)
    {
        s = s->next;
    }

    t = s->next;
    s->next= s->next->next;

    free(t);

    return f;
    
}

struct node* delete_node_by_data(struct node* f,int key_data)
{
    struct node *t,*s;

    s = f;

    while (s->next->data != key_data )
    {
        s = s->next;
        if (s == NULL)
        {
            break;
        }
        
    }

    if (s == NULL)
    {
        printf("Data NOT found !");
        exit(0);
    }

    t = s->next;
    s->next= s->next->next;

    free(t);

    return f; 

}
int main()
{
    struct node *head;
    int n,pos;

    printf("How many numbers : ");
    scanf("%d",&n);

    head = create_linked_list(n);

    display_linked_list(head);

   printf("Enter the position to add : ");
   scanf("%d",&pos);
   if(pos < 1 || pos > n)
    {
        printf("Invalid Position !");
        exit(0);
    }

    head =  add_linked_list(head,pos);
    display_linked_list(head);

   printf("Enter the position to delete a node : ");
   scanf("%d",&pos);
    head = delete_node(head,pos);
    printf("\n");

    display_linked_list(head);

    {  
        int data;

        printf("\nEnter the data to delete : ");
        scanf("%d",&data);

        head = delete_node_by_data(head,data);
         display_linked_list(head);
    }


    free_all(head);

    return 0;
}