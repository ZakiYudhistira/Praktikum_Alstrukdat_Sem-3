#include "list_circular.h"
#include <stdio.h>

// int listLength(List l){
//     if(isEmpty(l)){
//         return 0;
//     } else {
//         Address p = FIRST(l);
//         int count = 1;
//         while(NEXT(p) != FIRST(l)){
//             count++;
//             p = NEXT(p);
//         } return count;
//     }
// }

void isiList(int angka, List *l){
    int i;
    for(i = 1 ; i <= angka ; i++){
        insertLast(l, i);
    }
}

int main(){
    List mainList;
    CreateList(&mainList);
    int n;
    scanf("%d",&n);
    isiList(n, &mainList);
    int target;
    Address prev = FIRST(mainList);
    while (NEXT(prev) != FIRST(mainList))
    {
        prev = NEXT(prev);
    }
    
    Address p = FIRST(mainList);
    int number = 1;
    scanf("%d",&target);
    while(n > 1){
        if(number == target){
            NEXT(prev) = NEXT(p);
            printf("%d\n",INFO(p));
            deallocate(p);
            p = NEXT(prev);
            number = 1;
            n--;
        } else {
            number++;
            prev = p;
            p = NEXT(p);
        }
    }
    printf("pemenang %d\n",INFO(p));
    return 0;
}