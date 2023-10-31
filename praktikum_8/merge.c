#include "merge.h"
#include "listlinier.h"
#include <stdio.h>
#define endl printf("\n");

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
    Address p = source;
    if(listLength % 2 == 0){
        while(p != NULL){
            if(count < midPoint){
                insertLast(front, INFO(p));
                count++;
            } else {
                insertLast(back, INFO(p));
            }
            p = NEXT(p);
            
        }
    } else {
        midPoint++;
        while(p != NULL){
            if(count < midPoint){
                insertLast(front, INFO(p));
                count++;
            } else {
                insertLast(back, INFO(p));
            }
            p = NEXT(p);
        }
    }
}

List merge(List a, List b)
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/
{
    List l3;
    CreateList(&l3);
    if(a == NULL){
        return b;
    } else if (b == NULL){
        return a;
    } else {
        Address pa = FIRST(a);
        Address pb = FIRST(b);
        while(pa != NULL && pb != NULL){
            if(INFO(pa) < INFO(pb)){
                insertLast(&l3, INFO(pa));
                pa = NEXT(pa);
            } else {
                insertLast(&l3, INFO(pb));
                pb = NEXT(pb);
            }
        }
        while(pa != NULL){
            insertLast(&l3, INFO(pa));
            pa = NEXT(pa);
        }
        while(pb != NULL){
            insertLast(&l3, INFO(pb));
            pb = NEXT(pb);
        }
        return l3;
    }
}

void mergeSort(List* list){
    displayList(*list);
    endl;
    if(length(*list) == 1){
        return ;
    }
    List front, back;
    CreateList(&front);
    CreateList(&back);
    splitList(*list, &front, &back);
    mergeSort(&front);
    mergeSort(&back);
    *list = merge(front ,back);
}
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
    CreateList(&test);
    insertFirst(&test, 91);
    insertFirst(&test, 1);
    insertFirst(&test, 6);
    insertFirst(&test, 71);
    insertFirst(&test, 55);
    // insertFirst(&test, 77);
    endl;
    mergeSort(&test);
    displayList(test);

    return 0;
}