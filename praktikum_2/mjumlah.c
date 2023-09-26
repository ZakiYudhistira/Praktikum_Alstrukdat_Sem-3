#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main()
{
    ListStatik angka1, angka2;
    readList(&angka1);
    readList(&angka2);
    if(listLength(angka1)>=listLength(angka2))
    {
        int n;
        n = listLength(angka1)-listLength(angka2);
        int i;
        for(i = 0 ; i < n ;  i++)
        {
            insertFirst(&angka2, 0);
        }
        int j;
        for(j = listLength(angka1)-1;j >= 0 ; j--)
        {
            ELMT(angka1, j) += ELMT (angka2,j);
            if (ELMT(angka1,j) >= 10 && j > 0 )
            {
                ELMT(angka1, j) = ELMT(angka1, j) - 10;
                ELMT(angka1, j-1)++;
            } 
            else if ((ELMT(angka1,j) >= 10 && j == 0 ))
            {
                ELMT(angka1, j) = ELMT(angka1, j) - 10;
                insertFirst(&angka1, 1);
            }
        }
    printList(angka1);
    printf("\n");
    }
    else
    {
        int n;
        n = listLength(angka2)-listLength(angka1);
        int i;
        for(i = 0 ; i < n ;  i++)
        {
            insertFirst(&angka1, 0);
        }
        int j;
        for(j = listLength(angka1)-1;j >= 0 ; j--)
        {
            ELMT(angka1, j) += ELMT (angka2,j);
            if (ELMT(angka1,j) >= 10 && j > 0 )
            {
                ELMT(angka1, j) = ELMT(angka1, j) - 10;
                ELMT(angka1, j-1)++;
            } 
            else if ((ELMT(angka1,j) >= 10 && j == 0 ))
            {
                ELMT(angka1, j) = ELMT(angka1, j) - 10;
                insertFirst(&angka1, 1);
            }
        }
        printList(angka1);
        printf("\n");
    }
    
    return 0;
}