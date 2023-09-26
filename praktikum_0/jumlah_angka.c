#include <stdio.h>
int main(){
    int angka, digit;
    int jumlah = 0;
    scanf ("%d", &angka);
    while (angka > 0){
        digit = angka % 10;
        jumlah += digit;
        angka /= 10;

    }
    printf("%d\n", jumlah);
    return 0;
}