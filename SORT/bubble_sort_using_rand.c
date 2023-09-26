
/*
    Date : 27-08-2023
    UPDATE ON = [09-09-2023] // added a fuction that finds , time required for running program
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void load_arr(int*,int);
void sort_arr(int*,int);
void display_arr(int* ,int);

void load_arr(int *ptr,int cnt)
{
    register int i;
    int temp;

    srand(time(NULL));

    for ( i = 0; i<cnt; i++)
    {
        while (1)
        {
            temp = rand() % 1000;
            if (temp >=50 && temp< 1000)
            {
                ptr[i] = temp;
                break;
            }
            
        }
        
    }
     
}

void sort_arr(int *ptr,int cnt)
{   
    register int i,j;
    int temp;

    for ( i = cnt-1; i >= 0; i--)
    {
        for ( j = 0; j < i; j++)
        {
            if (ptr[j] > ptr[j+1])  
            {                                          
                temp = ptr[j];                     
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        } // j-for

    } // i-for
    
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
    clock_t t;
    int *ptr;

    printf("Enter array length : ");
    scanf("%d",&cnt);

    t = clock();

    ptr = (int *) malloc(cnt * sizeof(int));
    if (ptr == NULL)
    {
        printf("Unable to allocate memory !\n");
        exit(0);
    }

    load_arr(ptr,cnt);

    printf("\nGiven array  :\t");
    display_arr(ptr,cnt);

    sort_arr(ptr,cnt);

    printf("\nSorted array :\t");
    display_arr(ptr,cnt);


    t =clock() - t;

    printf("\n[ No. of clock ticks [%ld] and ( %f seconds) ]\n",t, ((double) t) / CLOCKS_PER_SEC);
    
    return 0;
}