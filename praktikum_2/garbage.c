#include "liststatik.h"
#include "boolean.h"
#include <stdio.h>

int hitung_waktu(ListStatik list_waktu, ListStatik list_rumah, int jenis)
{
    int waktu = 0, id_maks =0, i;
    for(i=listLength(list_rumah)-1;i>=0;i--)
    {
        if(ELMT(list_rumah, i) == jenis)
        {
            id_maks = i;
            break;
        }
        else
        {
            id_maks = 0;
        }
    }
    for(i=0;i<=id_maks;i++)
    {
        if(ELMT(list_rumah,i)==jenis)
            {
                waktu++;
            }
        if(i>=1)
        {
            waktu += ELMT(list_waktu, i-1)*2;
        }
    }
    return waktu;
}

int main(){
    
    ListStatik list_rumah, list_waktu;
    CreateListStatik(&list_rumah);
    CreateListStatik(&list_waktu);
    readList(&list_rumah);
    readList(&list_waktu);
    printf("%d\n", hitung_waktu(list_waktu, list_rumah, 1) + hitung_waktu(list_waktu, list_rumah, 2) + hitung_waktu(list_waktu, list_rumah, 3));
    return 0;
}