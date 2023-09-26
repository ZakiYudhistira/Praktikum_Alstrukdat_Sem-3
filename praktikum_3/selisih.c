#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    ListDin ini_list;
    CreateListDin(&ini_list, 100);
    readList(&ini_list);
    if (listLength(ini_list) > 1)
    {
        sort(&ini_list, true);
        int n = listLength(ini_list)-1;
        printf("%d\n", (ELMT(ini_list, n)-ELMT(ini_list, 0)+1));
    }
    else
    {
        printf("%d\n", 0);
    }
    return 0;
}