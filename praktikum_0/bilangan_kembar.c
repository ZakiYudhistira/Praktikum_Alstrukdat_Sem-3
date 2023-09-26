#include <stdio.h>
int main(){
    int awal, akhir, count;
    count = 0;
    scanf("%d", &awal);
    scanf("%d", &akhir);
    for (awal ; awal <= akhir ; awal++){
        int array[10] = {0};
        int angka = awal;
        int count_digits = -1;
        while(angka > 0){
            int digit = angka % 10;
            array[digit]++;
            count_digits++;
            angka /= 10;
        }
        int i;
        int param = 0;
        for(i=0 ; i<10 ; i++){
            if (array[i] > count_digits){
                param = 1;
                break;
            }

        }
        if (param > 0){
            count++;
        }
        
    }
    printf("%d\n", count);
    return 0;
}