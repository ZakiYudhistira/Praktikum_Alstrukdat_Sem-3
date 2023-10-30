#include "merge.h"
#include <stdio.h>

void splitList(List source, List* front, List* back)
/* Fungsi untuk memecah sebuah list dengan head source menjadi dua buah 
   list baru, yaitu front dan back. Apabila panjang list ganjil, maka
   list front akan lebih panjang dibandingkan list back.
   Sebagai contoh untuk list dengan panjang 5, maka list front memiliki
   3 elemen dan list back memiliki 2 elemen.
*/
{
    int listLength = length(source);
    int count = 0;
    int midPoint = listLength/2;
    Address pFront = NULL;
    Address pBack = source;
    if(listLength % 2 == 0){
        while(count < midPoint){
            pFront = pBack;
            pBack = NEXT(pBack);
            count++;
        }
    } else {
        midPoint++;
        while(count < midPoint){
            pFront = pBack;
            pBack = NEXT(pBack);
            count++;
        }
    }
    *front = pFront;
    *back = pBack;
}

List merge(List a, List b);
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/

void mergeSort(List* list);
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/

int main(){
    int i;
    List test, front, back;
    CreateList(&front);
    CreateList(&back);
    CreateList(&test);
    for(i = 0 ; i < 5 ; i++){
        insertFirst(&test, i);
    }
    displayList(test);
    printf("\n");
    splitList(test, &front, &back);
    displayList(front);
    displayList(back);

    return 0;
}