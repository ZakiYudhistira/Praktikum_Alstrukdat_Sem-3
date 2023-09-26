#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

void hapus_elemen (ListDin *l, ElType val)
{
    int i;
    ElType temp;
    for(i=NEFF(*l)-1; i >= 0 ; i--)
    {
        if(ELMT(*l, i) == val)
        {
            int j;
            for(j=i ; j < NEFF(*l)-1 ; j++)
            {
                ELMT(*l, j) = ELMT(*l, j+1);
            }
        }
    }
    NEFF(*l)--;
}

int main()
{
    ListDin array;
    int jumlah_anggota, jumlah_query;
    scanf("%d", &jumlah_anggota);
    CreateListDin(&array, jumlah_anggota);
    scanf("%d", &jumlah_query);
    int i;
    for(i=0 ; i < jumlah_query ; i++)
    {
        int tipe;
        scanf("%d",&tipe);
        if(tipe==1)
        {
            int x;
            scanf("%d",&x);
            int k, l, count=0;
            int NEFFawal = NEFF(array);
            for(k=0; k<NEFF(array); k++)
            {
                if(ELMT(array,k) < x)
                {
                    count++;
                }
            }
            for(l =0 ; l < count ; l++)
            {
                for(k=0; k<NEFF(array); k++)
                {
                    if(ELMT(array,k) < x)
                    {
                        hapus_elemen(&array, ELMT(array,k));
                    }
                }
            }
            insertLast(&array, x);
        }
        else
        {
            printf("%d\n", NEFF(array));
            printList(array);
            printf("\n");
        }
    }

    return 0;
}