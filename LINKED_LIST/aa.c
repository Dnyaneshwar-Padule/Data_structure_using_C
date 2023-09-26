#include<stdio.h>
#include<stdlib.h>
#include"myll.h"

int main()
{
    struct node *head;
    unsigned int n=0;

    printf("\nHow many nodes do you want to create : ");
    scanf("%d",&n);
    if (n<1)
    {
        printf("Value given for creating nodes is less than 1 !\n");
        exit(0);
    }
    head = create(n);
    

    while (1)
    {
        short int choice=0; 
        unsigned int pos=0;
      
        printf("\n***_MENU_***\n");
        printf("1~>Display Linked List\n2~>Add node at first\n3~>Add node at last\n4~>Delete first node\n5~>Delete last node\n6~>Insert node\n7~>Delete node\n8~>Count odd & even Data\n9~>Count positive & negative Data\n10~>Search an element\n11~>Count length of linked list\n12~>Append linked list \n13~>Display reverse\n14~>Reversing a linked list\n");
        printf("15~>Swapping two nodes\n16~>Get data at first node\n17~>Get data at last node\n18~>Get data at any node\n19~>Get index of data\n20~>Swap Nodes Pairwise ");
        printf("\n21~>Exit\n");
        printf("         ...NOTE :- PRESS 21 TO END THE PROGRAM \n");
        printf("\nChoose one of above : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                    display(head);
                    break;
            case 2:
                    head = add_first(head);
                    printf("\nNode is added successfully !\n");
                    break;
            case 3:
                    head = add_last(head);
                    printf("\nNode is added successfully !\n");
                    break;
            case 4:
                    head = del_first(head);
                    printf("\nNode is deleted successfully !\n");
                    break;
            case 5:
                    head = del_last(head);
                    printf("\nNode is deleted successfully !\n");
                    break;
            case 6:
                    printf("\nEnter the position to insert : ");
                    scanf("%d",&pos);
                    if (pos>1)
                    {
                        printf("Invalid position !\n");
                        break;
                    }
                    head = insert(head,pos);
                    break;
            case 7:
                    printf("\nEnter the position to delete : ");
                    scanf("%d",&pos);
                    if (pos<1)
                    {
                        printf("Invalid position !\n");
                        break;
                    }
                    head = delete(head,pos);
                    break;
            case 8:
                    odd_even(head);
                    break;
            case 9:
                    positive_negative(head);
                    break;
            case 10:
                    {
                        int key;
                        printf("\nEnter the element to search :");
                        scanf("%d",&key);
                        pos = search(head,key);
                        if (pos == -1)
                        {
                            printf("Element not found !\n");
                            break;
                        }
                        else
                        {
                            printf("%d is found at node No. %d \n",key,pos);
                            break;
                        }
                    }
            case 11:
                    {
                        int length = 0;
                        length = llength(head);
                        printf("\nThe length of the linked list is %d\n",length);
                    }
                    break;
            case 12:
                        head = append(head);
                        break;
            case 13:
                    display_reverse(head);
                    break;
            case 14:
                    head = reverse(head);
                    break;
            case 15:
                    {
                        unsigned int a_pos = 0, b_pos = 0;
                        printf("\nEnter the position of first node  : ");
                        scanf("%d",&a_pos);
                        printf("Enter the position of second node : ");
                        scanf("%d",&b_pos);
                    
                        if ( (a_pos < 1) || (b_pos < 1) )
                        {
                            printf("\nNumber is smaller than 1,Invalid Position !\n");
                            break;
                        }
                    
                        head = swap(head,a_pos,b_pos);
                    }
                        break;
            case 16:
                    printf("\nData at first node is %d\n",getfirst(head));
                    break;
            case 17:
                    printf("\nData at last node is %d \n",getlast(head));
                    break;
            case 18:
                    {
                        unsigned int pos;
                        struct node* temp;

                        printf("\nEnter the position of node :");
                        scanf("%d",&pos);
                        if (pos < 1)
                        {
                            printf("\nPositionis smaller tha one , Invalid position\n");
                            break;
                        }
                        temp = get(head,pos);
                        if (temp == NULL)
                        {
                            printf("\nInvalid position of node !\n");
                        }
                        else
                        {
                            printf("\nData at node No. %d is %d\n",pos,temp->data);
                        }
                        break;
                    }

            case 19:
                    {
                        unsigned int index = 0;
                        int data;
                        printf("\nEnter the data : ");
                        scanf("%d",&data);
                        index =  indexof(head,data);
                        if ( index == 0)
                        {
                            printf("\nData not found !\n");
                        }
                        else
                        {
                            printf("\nIndex of %d is %d \n",data,index);
                        }   
                        break;
                    }

            case 20:
                    head = swap_pairwise(head);
                    break;
            case 21:
                    head = free_all(head);
                    exit(0);        
        default:
            printf("Invalid option is selected !\n");
        }  // Switch
    } // While
    
    free_all(head);
    return 0;
} 