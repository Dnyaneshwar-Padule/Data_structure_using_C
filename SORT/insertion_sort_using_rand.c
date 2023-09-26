
/*
    Date : 27-08-2023
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
    
    for ( i = 1; i < cnt ; i++)   
    {                                                       // You can write inner loop like this.
        temp = ptr[i];                                      // for (j = i-1 ; j >= 0 ; j--)
                                                            // {
        for ( j = i-1; (j >= 0) && (temp < ptr[j]); j--)    //      if(temp < ptr[j])
        {                                                   //       {
            ptr[j+1] = ptr[j];                              //          ptr[j+1] = ptr[j];
        } // j-for                                          //       }
                                                            //       else
        ptr[j+1] = temp;                                    //      {
    } // i-for                                              //          break;
                                                            //      }
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

    load_arr(ptr,cnt);

    printf("\nGiven array  :\t");
    display_arr(ptr,cnt);

    sort_arr(ptr,cnt);

    printf("\nSorted array :\t");
    display_arr(ptr,cnt);
    
    return 0;
}