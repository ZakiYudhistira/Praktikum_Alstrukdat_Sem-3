#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main()
{
    int n;
    ListStatik a1,b2;
    readList(&a1);
    readList(&b2);
    if (listLength(a1) < listLength(b2))
    {
        n = listLength(a1);
        int i;
        for(i=0 ; i < n ; i++)
        {
            insertLast(&b2, ELMT(a1, i));
        }
        sortList(&b2, true);
        printList(b2);
        printf("\n");
    }
     else
    {
        n = listLength(b2);
        int i;
        for(i=0 ; i < n ; i++)
        {
            insertLast(&a1, ELMT(b2, i));
        }
        sortList(&a1, true);
        
        printList(a1);
        printf("\n");
    }
    return 0;
}