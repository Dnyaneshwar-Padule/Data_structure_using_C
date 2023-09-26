
// Date : 20-08-2023

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void load(int [],int);
void display(int [],int);

void load(int a[],int n)
{
    register int i;
    int num;

    srand(time(NULL));

    for ( i = 0; i < n; i++)
    {
       while(1)
       {
            num = rand() % 10000;

            if( num >= 1000 && num <= 9999)
            {
                a[i]= num;
                break;
            }
       }
    }
    
}

void display(int a[],int n)
{
    register int i;

    for ( i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
    

}

int main()
{
    int a[10];
    int n;

    printf("Enter the number of element in between 10 : ");
    scanf("%d",&n);

    load(a,n);
    display(a,n);

    return 0;
}