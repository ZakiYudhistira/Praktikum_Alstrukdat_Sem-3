#include <stdio.h>
int main(){
    int fav,domba;
    scanf("%d", &domba);
    scanf("%d", &fav);
    int i = 1;
    for(i;  i<=domba ; i++){
        if (i % fav == 0){
            printf("happy\n");
        }
        else{
            printf("%d\n", i);
        }
    }

    return 0;

}