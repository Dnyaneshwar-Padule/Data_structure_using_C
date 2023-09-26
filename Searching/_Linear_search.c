/*
    Date :- 02-09-2023
*/

#include<stdio.h>
#include<stdlib.h>

char select_arr_type(void)
{
    char a;

    printf("\n1) Enter 1 if your array is sorted .\n");
    printf("2) Enter 2 if your array is not sorted \n");
    printf("       \nEnter : ");
    
    scanf("%c",&a);

    return a;

}

 void load_elements(int* ptr,int n)
 {
    register unsigned int i;
    printf("Enter the elements :\n");

    for ( i = 0; i < n; i++)
    {
        printf("Enter element No.%d  : ",i);
        scanf("%d",&ptr[i]);
    }
    
 }

    int imp_lin_search(int* ptr,int n,int key)
    {
        register unsigned int i;

        for ( i = 0; i < n; i++)
        {
            if (ptr[i] == key)
            {
                return i;
            }

            if(ptr[i] > key)
            {
                return -1;
            }
            
        }

        return -1;
        
    }

int _lin_search(int*ptr,int n,int key)
{
   register unsigned int i;

   for ( i = 0; i < n; i++)
   {
        if(ptr[i] == key)
        {
            return i;
        }
   }

   return -1;
   
}

int main()
{
    int n,key; 
    int *ptr;
    char check; 

    check = select_arr_type();

   /* printf("\n1) Enter 1 if your array is sorted .\n"); 
    printf("2) Enter 2 if your array is not sorted \n");
    printf("       \nEnter : ");
    scanf("%c",&check);*/                                 // Can use this instead of select_arr_type()

    switch(check)
    {
        case '1':       
                printf("Enter your array length : ");
                scanf("%d",&n);

                ptr = (int* ) malloc(n*sizeof(int));
                if(ptr == NULL)
                {
                    printf("Unable to allocate memory \n");
                    exit(0);
                }

                load_elements(ptr,n); 

                printf("Enter key element : ");
                scanf("%d",&key);

                if((n = imp_lin_search(ptr,n,key)) == -1)
                {
                    printf("\nKey is not found ");
                }
                else
                {
                    printf("Key is found at index %d",n);
                }
                break;

        case '2':
    
    
                printf("Enter your array length : ");
                scanf("%d",&n);

                ptr = (int* ) malloc(n*sizeof(int));
                if(ptr == NULL)
                {
                    printf("Unable to allocate memory \n");
                    exit(0);
                }

                load_elements(ptr,n); 

                printf("\nEnter key element : ");
                scanf("%d",&key);

                if((n = _lin_search(ptr,n,key)) == -1)
                {
                    printf("Key is not found ");
                }
                else
                {
                    printf("Key is found at index %d",n);
                }

                break;
      
        default :        
                printf("\n*** Invalid Input ***\n");
                printf("Please enter a valid number \n");
    }
    
    return 0;
    
}