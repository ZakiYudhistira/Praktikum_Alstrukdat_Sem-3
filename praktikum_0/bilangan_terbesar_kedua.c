#include <stdio.h>
int main(){
    int n,i,j;
    int terbesar = 0;
    int terbesar_kedua = 0;
    scanf("%d", &n);
    for (i=1 ; i<=n ; i++){
        scanf("%d", &j);
        if (j > terbesar){
            terbesar_kedua = terbesar;
            terbesar = j;
        }
        else if (j > terbesar_kedua){
            terbesar_kedua = j;
        }
    }
    printf("%d\n", terbesar_kedua);
    return 0;
    }