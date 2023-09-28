#include<time.h>
#define NEWNODE (struct node*)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *next;
};

struct node* create_manually(int n)
{
    struct node *f=NULL,*t=NULL,*l=NULL;

    f = NEWNODE;
    if (f==NULL)
    {
        printf("unable to allocate memory !\n");
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
            printf("Unable to allocate memory !\n");
            free(f);
            return f;
        }
        
        printf("Enter the data : ");
        scanf("%d",&t->data);
        t->next = NULL;

        l->next = t ;
        l = l->next ;
    }
    
    return f;
}

struct node* create_auto(int n)
{
    struct node *f=NULL,*t=NULL,*l=NULL;
    int temp;

    f = NEWNODE;
    if (f==NULL)
    {
        printf("unable to allocate memory !\n");
        exit(0);
    }
    
    srand(time(NULL));

    while (1)
    {
        temp = rand() % 100;
        if (temp > 0)
            break;
    }
    
    f->data = temp;
    f->next = NULL;
    l = f;

    for (int i = 2; i <= n; i++)
    {
        t = NEWNODE;
        if (t == NULL)
        {
            printf("Unable to allocate memory !\n");
            free(f);
            return f;
        }
    
        while (1)
        {
            temp = rand() % 100;
            if (temp > 0)
                break;
        }
        t->data = temp;
        t->next = NULL;

        l->next = t ;
        l = l->next ;
    }
    
    return f;
}

void display(struct node* f)
{
    struct node *t=NULL;

    printf("\nLinked List : ");
    for (t = f; t != NULL ; t = t->next )
    {
        printf("%d -> ",t->data);
    }
    printf(" NULL\n");
}

struct node* free_all(struct node *f)
{
    struct node* t=NULL;

    while (f!=NULL)
    {
        t = f;
        f = f->next;
        free(t);
    }
    return f; 
}

struct node* add_first(struct node* f)
{
    struct node *t = NEWNODE;
    printf("\nEnter the data : ");
    scanf("%d",&t->data);
    
    t->next = f;
    f = t;
    return f;
}

struct node* add_last(struct node* f)
{
    struct node *t=NULL,*s=NULL;

    t = NEWNODE;
    printf("\nEnter the data : ");
    scanf("%d",&t->data);
    t->next = NULL;

    for (s = f ; s->next != NULL ; s = s->next);

    s->next = t;
    return f;
}

struct node* del_first(struct node* f)
{
    struct node *t;

    t = f;
    f = f->next;
    free(t);
    return f;
}

struct node* del_last(struct node* f)
{
    struct node *t=NULL,*s=NULL;

    for ( s = f ; s->next != NULL ; s = s->next)
    {
        t = s;
    }

    free(s);
    t->next = NULL;

    return f;
}

struct node* insert(struct node* f,int pos)
{
    struct node *t=NULL,*s=NULL;

    t = NEWNODE;
    printf("\nEnter the data : ");
    scanf("%d",&t->data);
    t->next = NULL;

    if (pos == 1)
    {
        t->next  = f;
        f = t;
        printf("\nNode is added successfully !\n");
        return t;
    }
    else
    {
        s = f;
        for (int i = 1; i <= (pos-2) && s != NULL; i++)
            s = s->next;

        if (s == NULL)
        {
            printf("\nInvalid Position !\n");
            free(t);
            return f;
        }
        else
        {
            t->next = s->next;
            s->next = t;
            printf("\nNode is added successfully !\n");
            return f;
        }
        
    }
    
}

struct node* delete(struct node*f,int pos)
{
    struct node *t=NULL,*s=NULL;

    if (pos == 1)
    {
        t = f;
        f = f->next;
        free(t);
        printf("\nNode is deleted successfully !\n");
        return f;
    }
    else
    {
        s = f;
        for (int i = 1; i <= (pos-2) && s != NULL; i++)
            s = s->next;

        if ((s == NULL) || (s->next == NULL))
        {
            printf("\nInvalid position for deletion !\n");
            return f;
        }
        else
        {
            t = s->next;
            s->next = t->next;
            free(t);
            printf("\nNode is deleted successfully !\n");
            return f;
        }    
    }  
}

unsigned int llength(struct node* f)
{
    struct node *t = NULL;
    unsigned int cnt=0;

    for (t = f ; t != NULL ; t = t->next)
        cnt++;

    return cnt;   
}

void odd_even(struct node* f)
{
    struct node *t=NULL;
    unsigned int even_cnt = 0 , odd_cnt = 0; 

    for ( t = f; t!=NULL;t = t->next)
    {
        if ((t->data % 2 ) == 0 )
            even_cnt++;
        else
           odd_cnt++;
    }

    printf("\nEven data values : ",even_cnt);
    printf("\nOdd data values  : ",odd_cnt);
}

void positive_negative(struct node*f)
{
    struct node *t=NULL;
    unsigned int positv_cnt = 0 , negatv_cnt = 0; 

    for ( t = f; t!=NULL;t = t->next)
    {
        if ((t->data % 2 ) == 0 )
            positv_cnt++;
        else
           negatv_cnt++;
    }

    printf("\nPositive data values : ",positv_cnt);
    printf("\nNegative data values : ",negatv_cnt);
}

int search(struct node *f,int key)
{
    struct node *t=NULL;
    t=f;
    for (unsigned int i = 1; t!=NULL; i++)
    {
        if(t->data == key)
            return i;

        t = t->next;
    }
    return -1;
}

struct node* append(struct node* f)
{
    struct node *t=NULL,*s=NULL;

    {
        int n=0;
           printf("\nHow many nodes do you want to apppend : ");
           scanf("%d",&n);
           if (n>1)
           {
                printf("\nNumber is smaller than 1 ,Can't create nodes !\n");
                return f;
           }
           
           t = create_manually(n);
    }

    for ( s = f ;s->next != NULL;s = s->next);
    
    s->next = t;

    return f;   
}

void display_reverse(struct node* f)
{
    struct node *t=NULL;
    unsigned int cnt=0;
    cnt = llength(f); // counting length of lined list
    
    printf("\nNULL <- ");
    for (int i = cnt; i > 1 ; i--)
    {
        t = f;
        for (int j = 1; j < i; j++)
        {
            t = t->next;
        }

        printf("%d <- ",t->data); 
    }
    printf("%d",f->data);
    printf("\n");
}

struct node* reverse(struct node* f)
{
    struct node *p=NULL,*n=NULL,*s=NULL;
    s = f ; 
    while (s!=NULL)
    {
        n = s->next;
        s->next = p;
        p = s;
        s = n; 
    }
    f = p;
    printf("\nLinked list is reversed successfully !\n");
    return f;  
}

struct node* swap(struct node* f,unsigned int a_pos,unsigned int b_pos)
{
    struct node *t=NULL;
    struct node *a_pre = NULL, *b_pre = NULL ,*a=NULL , *b=NULL , *imp = NULL;

    if (a_pos == b_pos)
    {
        printf("\nCan not swap a single node !\n");
        return f;
    }

    unsigned int count=0;
    count = (a_pos > b_pos) ? a_pos :  b_pos ;
    
    a=f;
    b=f;
    for (int i = 1; i <= (count-1) && a != NULL && b != NULL; i++)
    {
        if ( i<= (a_pos-1))
        {
            a_pre = a;
            a = a->next;
        }
        if ( i <= (b_pos -1 ))
        {
            b_pre = b;
            b = b->next;
        }
    }

    if ( (a == NULL) || (b == NULL))
    {
        printf("\nInvalid position !\n");
        return f;
    }
    
    if (a_pre== NULL)
    {
        a_pre = a;
        f = b;
    }
    if (b_pre== NULL)
    {
        b_pre = b;
        f = a;
    }
    
    a_pre->next = b;
    b_pre->next = a;

    imp = a->next;
    a->next = b->next;
    b->next = imp;

    printf("\nNodes are swapped successfully !\n");
    return f;
    
}

int getfirst(struct node* f)
{
    struct node *t = f;
    return t->data;
}

int getlast(struct node* f)
{
    struct node *t=NULL;

    for (t = f;t->next!=NULL;t = t->next);
    
    return t->data;  
}

struct node* get(struct node* f,unsigned int pos) 
{
    struct node *t=NULL;
    int i;
    for (i=1,t=f; i <= (pos-1) && t != NULL ; i++,t=t->next);
    
    if ( t == NULL)
    {
        return NULL;
    }
    else
    {
        return t;
    }
}

unsigned int indexof(struct node* f,int data)
{
    struct node* t=NULL;
    unsigned int index=1;
    for (t=f; (t != NULL) &&(t->data != data) ; t = t->next )
            index++;
    
    if ( t == NULL)
    {
        return 0;
    }
    else
    {
       return index;
    }   
}

struct node* swap_pairwise(struct node* f)
{
    if (f->next == NULL)
    {
        printf("\nLess number of nodes top swap !\n");
        return f;
    }

    if ( f == NULL )
    {
        printf("\nLinked list is empty !\n");
        return f;
    }
    
    
    struct node *imp=NULL,*a_pre = NULL,*a=NULL,*b=NULL,*b_pre = NULL;

    a=f;
    a_pre = a;
    b_pre = a;
    b = a->next;
    f = b;

    while ( b != NULL && b->next != NULL)
    {
        a_pre->next = b;
        b_pre->next = a;

        imp = a->next;
        a->next = b->next;
        b->next = imp;

        a_pre = a;
        a = a->next;
        b_pre = a;
        b = a->next;
    }
    printf("\nNodes are swapped pairwise !\n");
    return f;
}

struct node* SWAP(struct node* f,unsigned int a_pos,unsigned int b_pos)
{
    struct node *t=NULL;
    struct node *a_pre = NULL, *b_pre = NULL ,*a=NULL , *b=NULL , *imp = NULL;

    if (a_pos == b_pos)
    {
        return f;
    }

    if(a_pos>b_pos)
    {
        a_pos = a_pos + b_pos;
        b_pos = a_pos - b_pos;
        a_pos = a_pos - b_pos;
    }
    
    a=f;
    b=f;

    for (int i = 1; i <= (a_pos-1); i++)
    {
        a_pre = a;
        a = a->next;
    }
    for (int i = 1; i <= (b_pos-1); i++)
    {
        b_pre = b;
        b = b->next;
    }
    

    if ( (a == NULL) || (b == NULL))
    {
        return f;
    }
    
    if (a_pre== NULL)
    {
        a_pre = a;
        f = b;
    }
    if (b_pre== NULL)
    {
        b_pre = b;
        f = a;
    }
    if (a_pos - b_pos == 1 || b_pos - a_pos == 1)
    {
        a_pre->next = b;
        b_pre->next = a;

        imp = a->next;
        a->next = b->next;
        b->next = imp;
    }
    else
    {    imp = a->next;
        a_pre->next = b;
        b_pre->next = a;

        a->next = b->next;
        b->next = imp;
    }
    return f;
    
}

struct node* shuffle(struct node *f)
{
    struct node *t=NULL,*s=NULL;
    unsigned int cnt=0;
    int temp;

    for ( t = f; t != NULL ; t = t->next)
    {
        cnt++;
    }
    
    srand(time(NULL));

    s=f;
    for (int i = 1; i <= cnt; i++)
    {
        while (1)
        {
            temp = rand() % cnt;
            if (temp >= 1)
                break;
        }
        s = SWAP(s,i,temp);
    }

    f = s;

    return f;
}

struct node* sort_by_bubble_sort(struct node *f)
{
    struct node *t=NULL,*s=NULL;
    unsigned int cnt=1;
    register int i ,j;
    int k=1,p=2;

    for ( t = f; t->next != NULL ; t = t->next)
    {
        cnt++;
    }
    t = f;
    s = f;
    for ( i = cnt-1; i > 0 ; i--)
    {
        s = t;
        k = 1,p = 2;

        for ( j = 1; j <= i ; j++)
        {
            if ( s->data > s->next->data)
            {
                s = SWAP(t,k,p);
                t = s;
                for (int a = 1; a < j; a++)
                {
                    s = s->next;
                }
            }
            s = s->next;
            k++;
            p++;
        }
        
    }
    f = t;
    return f;
}
