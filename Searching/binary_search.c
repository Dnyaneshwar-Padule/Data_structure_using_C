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

void sort_array(int *ptr,int cnt)
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

int _bin_search(int*ptr,int n,int key)
{
   register unsigned int i;
   int ub,lb,mid;

   lb = 0;
   ub = n-1;

    while(lb>=ub)
    {
        mid = (lb + ub) / 2;

        if (ptr[mid] == key)
        {
            return mid;
        }
        else if (key > ptr[mid])
            lb = mid + 1;
        else
            ub = mid - 1;
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

                if((n = _bin_search(ptr,n,key)) == -1)
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

                sort_array(ptr,n);

                printf("\nEnter key element : ");
                scanf("%d",&key);

                if((n = _bin_search(ptr,n,key)) == -1)
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