#include "listlinier.h"
#include <stdio.h>

boolean isIn (List l, ElType val) {
    Address p = l;
    while (p != NULL) {
        if (INFO(p) == val) {
            return true;
        }
        p = NEXT(p);
    }
    return false;
}

int fineIdx (List l, ElType val) {
    Address p = l;
    int idx = 0;
    while (p != NULL) {
        if (INFO(p) == val) {
            return idx;
        }
        idx++;
        p = NEXT(p);
    }
}

int main() {
    int n_maks, count = 0, operation_count;
    scanf("%d", &n_maks);
    scanf("%d", &operation_count);
    int i,n,j=0;
    int hit = 0, miss = 0;
    List l;
    CreateList(&l);
    for (i = 0 ; i < operation_count ; i++) {
        scanf("%d",&n);
        ElType buang;
        if(count < n_maks){
            if(isIn(l,n)) {
                deleteAt(&l, fineIdx(l,n), &buang);
                insertFirst(&l, n);
                printf("hit ");
                displayList(l);
                printf("\n");
                hit++;
            } else {
                insertFirst(&l, n);
                count++;
                printf("miss ");
                displayList(l);
                printf("\n");
                miss++;
            }   
        } else {
            if(isIn(l,n)) {
                deleteAt(&l, fineIdx(l,n), &buang);
                insertFirst(&l, buang);
                printf("hit ");
                displayList(l);
                printf("\n");
                hit++;
            } else {
                insertFirst(&l, n);
                deleteLast(&l, &buang);
                printf("miss ");
                displayList(l);
                printf("\n");
                miss++;
            }
        }
    }
    if (hit == 0 && miss == 0) {
        printf("hit ratio: 0.00\n");
    } else {
    printf("hit ratio: %.2f\n", (float)hit/(((float)hit+(float)miss)));
    }
    return 0;
}