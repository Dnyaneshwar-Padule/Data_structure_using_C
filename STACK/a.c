#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main()
{
    int temp;
    
    push(10);
    push(11);
    push(12);
    push(13);
    push(14);
    push(15);
    push(16);
    push(17);

    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());

    return 0;
}