#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main()
{
    unsigned int i = 0;
    char str[30];

    printf("Enter the string :");
    gets(str);

    for ( i = 0; str[i] ; i++)
    {
        if ( ! isfull() )
            push(str[i]); 
    }

    printf("Reverse by word : ");
    while( ! isempty()  )
    {
        str[i] = pop();

        if ( ! isempty() && peek() == ' ' )
        {
            for ( int j = i ; j >= 0 ; j--)
                printf("%c",str[j]);

            printf("%c",pop());
            i = 0;
        }
        else if ( top == -1 )
        {
            for (int j = i ; j >= 0 ; j--)
                printf("%c",str[j]);
        }
        else
        {
            i++;
        }  
    }
    return 0;
}