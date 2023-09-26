#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>


void hapusPertama(ListDin*l)
{
    int i;
    for(i=0 ; i < NEFF(*l)-1 ; i++)
    {
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    int buang;
    deleteLast(l,&buang);
}
int main()
{
    ListDin t1, t2, t3;
    int i=0;
    CreateListDin(&t1, 100000);
    CreateListDin(&t2, 100000);
    CreateListDin(&t3, 100000);
    readList(&t1);
    readList(&t2);
    while(NEFF(t1) > 0 && NEFF(t2) > 0)
    {
        
        if(ELMT(t1,0) >= ELMT(t2, 0))
        {
            insertLast(&t3, ELMT(t1, i));
            hapusPertama(&t1);
        }
        else
        {
            insertLast(&t3, ELMT(t2, i));
            hapusPertama(&t2);
        }
    }
    if(NEFF(t1) == 0 && NEFF(t2) > 0)
    {
        int i;
        for(i = 0 ; i<NEFF(t2) ; i++)
        {
            insertLast(&t3, ELMT(t2, i));
        }
    }
    else if(NEFF(t1) > 0 && NEFF(t2) == 0)
    {
        int i;
        for(i = 0 ; i<NEFF(t1) ; i++)
        {
            insertLast(&t3, ELMT(t1, i));
        }
    }
    printList(t3);
    printf("\n");
    
    return 0;
}