#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HashTable.h"

int main()
{
    clock_t start,end;
    int ielement[10]={0, 1, 4, 9, 16, 25, 36, 49, 64, 81},i,j;
    int isearchfor[5]={64,67,25,1,5};
    int idelete[5]={77,78,55,1,4};

    HashTable myHt;
    //printf("Let us start Creating Table of size 10\n");

////////////////////////////////////////////////////////////////'
    // Illustration of Creating HashTable
    myHt = CreateHashTable(4000);
////////////////////////////////////////////////////////////////'


////////////////////////////////////////////////////////////////'
start = clock();
    // Illustration of Inserting Elements in the HashTable
    for (i=0;i<2001;i++)
    {
       // printf("Enter the element to insert \n");
       // scanf("%d", &ielement );
     //  printf("%d",i);
        InsertElement(i,myHt);   
    }
end= clock();
printf("\n ************ \n %f \n**********",((double) (end-start))/CLOCKS_PER_SEC);
////////////////////////////////////////////////////////////////'
////////////////////////////////////////////////////////////////'
start = clock();
    // Illustration of Inserting Elements in the HashTable
    for (i=0;i<2001;i++)
    {
       // printf("Enter the element to insert \n");
       // scanf("%d", &ielement );
       j = rand();
       //printf("%d\n",j);
        InsertElement(j,myHt);   
    }
end= clock();
printf("\n ************ \n %f \n**********",((double) (end-start))/CLOCKS_PER_SEC);

////////////////////////////////////////////////////////////////'
    // Illustration fo Search/Find operation
    printf("Now illustration fo Search Operation \n");
    for (i=0;i<5;i++)
    {
        printf("the element to look for %d \n",isearchfor[i]);
        //scanf("%d", &ielement );
        if(FindInTable(isearchfor[i],myHt) != NULL)   
        {
            printf("Element found in the table\n");
        }
        else
        {
            printf("Element Not found in the table\n");            
        }
    }
////////////////////////////////////////////////////////////////'


////////////////////////////////////////////////////////////////'
    // Illustration of Deleting from the HashTable
    printf("Now illustration fo Delete Operation \n");
    for (i=0;i<5;i++)
    {
        printf("the element to delete %d\n",idelete[i]);
        //scanf("%d", &ielement );
        DeleteElement(idelete[i],myHt);
        printf("Element (if presetn) Deleted. Let me check if I can find it again. \n");
        if(FindInTable(idelete[i],myHt) != NULL)   
        {
            printf("Element found in the table\n");
        }
        else
        {
            printf("Element Not found in the table\n");            
        }
    }
////////////////////////////////////////////////////////////////'


////////////////////////////////////////////////////////////////'
    printf("Now deleting the table\n");
    DeleteHashTable(myHt);
    printf("Deletion Successfull!!!");
////////////////////////////////////////////////////////////////'

    return 0;
}

