#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    ListDin array;
    CreateListDin(&array, 0);
    int query;
    scanf("%d", &query);
    int i;
    for(i = 0; i < query ; i++)
    {
        int tipe;
        scanf("%d",&tipe);
        if(tipe==1)
        {
        int x;
        scanf("%d",&x);
        if(CAPACITY(array) == 0)
        {
            expandList(&array, 1);
        }
        else if(NEFF(array)==CAPACITY(array))
        {
            expandList(&array, CAPACITY(array));
        }
        insertLast(&array, x);

        }
        else if(tipe==2)
        {
        int elemen_hilang;
        deleteLast(&array, &elemen_hilang);
            if(NEFF(array)<=round(CAPACITY(array)/2))
            {
                shrinkList(&array, CAPACITY(array) - round(CAPACITY(array)/2));
            }

        }
        else
        {
        printf("%d ", CAPACITY(array));
        printList(array);
        printf("\n");
        }
    }
    
    return 0;
}