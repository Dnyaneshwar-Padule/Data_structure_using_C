
/*
    Date : 27-08-2023
*/
#include<stdio.h>
#include<stdlib.h>

void accept_arr(int*,int);
void sort_arr(int*,int);
void display_arr(int* ,int);

void accept_arr(int *ptr,int cnt)
{
    register int i;

    printf("\n");

    for ( i = 0; i<cnt; i++)
    {
        printf("Enter the number No.%d : ",i+1);
        scanf("%d",&ptr[i]);
    }
     
}

void sort_arr(int *ptr,int cnt)
{   
    register int i,j;
    int temp,great;

    //step 1:Finding greatest element
    great = ptr[0];

    for ( i = 1; i < cnt; i++)
    {
        if(ptr[i] > ptr[i+1])
        {
            great = ptr[i];
        }
    }
    

    //step 2: 
    
}

void display_arr(int *ptr,int cnt)
{
    register int i;

    for ( i = 0; i < cnt; i++)
    {
        printf("%d\t",ptr[i]);
    }
}

int main()
{
    unsigned int cnt;
    int *ptr;

    printf("Enter array length : ");
    scanf("%d",&cnt);

    ptr = (int *) malloc(cnt * sizeof(int));
    if (ptr == NULL)
    {
        printf("Unable to allocate memory !\n");
        exit(0);
    }

    accept_arr(ptr,cnt);

    printf("\nGiven array :\t");
    display_arr(ptr,cnt);

    sort_arr(ptr,cnt);

    printf("\nSorted array :\t");
    display_arr(ptr,cnt);
    
    return 0;
}