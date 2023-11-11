#include "listrec.h"
#include "boolean.h"
#include <stdio.h>

int main(){
    List ini = NIL;
    printf("%d\n",length(ini));
    ini = konso(ini, 6);
    ini = konso(ini, 5);
    List ini2 = NIL;
    ini = concat(ini,ini2);
    displayList(ini2);
    displayList(ini);
    printf("%d\n",length(ini));
    if(isOneElmt(ini)){
        printf("ada");
    }
}