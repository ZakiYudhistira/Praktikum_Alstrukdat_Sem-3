#include "queuelinked.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
{
    Address p;
    p = (Address)malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
{
    return ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL;
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
{
    int count = 0;
    Address p = ADDR_HEAD(q);
    while(p != NULL){
        count++;
        p = NEXT(p);
    }
    return count;
}

/*** Kreator ***/
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}
void DisplayQueue(Queue q)
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    printf("[");
    boolean first = true;
    Address p = ADDR_HEAD(q);
    while(p != NULL){
        if(first){
            printf("%d",INFO(p));
            first = false;
        p = NEXT(p);
        } else {
            printf(",%d",INFO(p));
        p = NEXT(p);
        }
    }
    printf("]");
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
{
    Address new = newNode(x);
    if(new != NULL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q) = new;
            ADDR_TAIL(*q) = new;
        } else {
            NEXT(ADDR_TAIL(*q)) = new;
            ADDR_TAIL(*q) = new;
        }
    }
}
void dequeue(Queue *q, ElType *x)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    *x = HEAD(*q);
    if(length(*q) == 1){
        free(ADDR_HEAD(*q));
        ADDR_HEAD(*q) = NULL;
        ADDR_TAIL(*q) = NULL;
    } else {
        Address p = ADDR_HEAD(*q);
        ADDR_HEAD(*q) = NEXT(p);
        free(p);
    }
}

// int main(){
//     Queue l;
//     CreateQueue(&l);
//     enqueue(&l,5);
//     enqueue(&l,5);
//     enqueue(&l,5);
//     enqueue(&l,5);
//     DisplayQueue(l);
//     return 0;
// }