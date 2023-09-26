#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main(){
    ListStatik list1;
    float rata2;
    int n, maksimal, minimal, id_muncul, median;
    rata2 = 0;
    readList(&list1);
    scanf("%d", &n);
    int i;
    sortList(&list1, true);
    for(i=0 ; i< listLength(list1); i++)
    {
        rata2 += (float)ELMT(list1, i);
    }
    rata2 = rata2/(float)listLength(list1);
    if(listLength(list1) % 2 == 1)
    {
        median = ELMT(list1, (listLength(list1)/2));
    }
    else
    {
        median = ELMT(list1, (listLength(list1)/2)-1);
    }
    extremeValues(list1, &maksimal, &minimal);
    //-----------------------------------------
    printList(list1);
    printf("\n");
    printf("Average: %.2f\n", rata2);
    if(indexOf(list1, n) != -1)
    {
        printf("%d\n", indexOf(list1,n));
    }
    else{
        printf("%d tidak ada\n", n);}
    if(n == maksimal)
    {
        printf("X maksimum\n");
    }
    if(n == minimal)
    {
        printf("X minimum\n");
    }
    if(n == median)
    {
        printf("X median\n");
    }
    return 0;
}