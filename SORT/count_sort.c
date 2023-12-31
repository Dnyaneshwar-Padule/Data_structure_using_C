
/*
    Date : 27-08-2023
*/
#include<stdio.h>
#include<stdlib.h>

void accept_arr(int*,int);
void sort_arr(int*,int);
void display_arr(int* ,int);

void accept_arr(int *a,int n)
{
    register int i;

    printf("\n");

    for ( i = 0; i<n; i++)
    {
        printf("Enter the number No.%d : ",i+1);
        scanf("%d",&a[i]);
    }
     
}

void sort_arr(int *a,int n)
{   
    register int i;
    int *count,*b;
    int max;

    //step 1 : Finding maximum element

    max = a[0];
    for ( i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    count = (int *)calloc(max+1,sizeof(int));
   
    //step 2: Counting frequency of elements

    for ( i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    //step 3: Addition of closest elements

    for ( i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i -1];
    }

    b = (int *)malloc(n*sizeof(int));
    // step 4: sorting

    for ( i = 0; i < n; i++)
    {
        b[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    
    // step 5:Copying sorted array

    for ( i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    
    free(count);
    free(b);
}

void display_arr(int *a,int n)
{
    register int i;

    for ( i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
}

int main()
{
    unsigned int n;
    int *a;

    printf("Enter array length : ");
    scanf("%d",&n);
    if ( n < 1 )
    {
        printf("\nInvalid Input !\n");
        exit(0);
    }

    a = (int *) malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Unable to allocate memory !\n");
        exit(0);
    }

    accept_arr(a,n);

    printf("\nGiven array :\t");
    display_arr(a,n);

    sort_arr(a,n);

    printf("\nSorted array :\t");
    display_arr(a,n);
    
    return 0;
} // We can't use it for negative values !!