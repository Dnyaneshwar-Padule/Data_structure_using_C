
/*
    Date : 24-08-2023
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct word
{
    char word[12];
};
void accept_word(struct word*,int);
void sort_word(struct word*,int);
void display_sorted_str(struct word* ,int);

void accept_word(struct word *ptr,int cnt)
{
    register int i;

    printf("\n");

    for ( i = 0; i<cnt; i++)
    {
        printf("Enter the word No.%d :",i+1);
        gets(ptr[i].word);
    }
     
}

void sort_word(struct word *ptr,int cnt)
{
    register int i,j;
    char temp[12];

    for ( i = 1; i < cnt; i++)
    {
        for ( j = 0; j < cnt-i; j++)
        {
            if (strcmp(ptr[j].word , ptr[j+1].word) == 1)       // temp = a
            {                                                  // a = b 
                strcpy(temp,ptr[j].word);                     // b = temp
                strcpy(ptr[j].word,ptr[j+1].word);
                strcpy(ptr[j+1].word,temp);
            }
            
        }
        
    }
    
}

void display_sorted_str(struct word *ptr,int cnt)
{
    register int i;
    printf("\nSorted array : ");

    for ( i = 0; i < cnt; i++)
    {
        printf("%s\t",ptr[i].word);
    }
}

int main()
{
    unsigned int cnt;
    struct word *ptr;

    printf("How many words : ");
    scanf("%d",&cnt);
    getchar();

    ptr = (struct word *) malloc(cnt * sizeof(struct word));
    if (ptr == NULL)
    {
        printf("Unable to allocate memory !\n");
        exit(0);
    }

    accept_word(ptr,cnt);
    sort_word(ptr,cnt);
    display_sorted_str(ptr,cnt);
    
    return 0;
}