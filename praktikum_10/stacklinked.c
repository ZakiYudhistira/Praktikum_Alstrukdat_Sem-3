#include "stacklinked.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   
{
    Address p;
    p = (Address)malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s)
/* Mengirim true jika Stack kosong: TOP(s) = NIL */
{
    return ADDR_TOP(s) == NULL;
}

int length(Stack s)
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */
{
    Address p = ADDR_TOP(s);
    int count = 0;
    while(p != NULL){
        count++;
        p = NEXT(p);
    }
    return count;
}

void CreateStack(Stack *s)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
{
    ADDR_TOP(*s) = NULL;
}

void DisplayStack(Stack s)
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1 (TOP), 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */
{
    printf("[");
    boolean first = true;
    Address p = ADDR_TOP(s);
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

void push(Stack *s, ElType x)
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
{
    Address new = newNode(x);
    if(isEmpty(*s)){
        ADDR_TOP(*s) = new;
    } else {
        NEXT(new) = ADDR_TOP(*s);
        ADDR_TOP(*s) = new;
    }
}

void pop(Stack *s, ElType *x)
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
{
    *x = TOP(*s);
    if(length(*s)==1){
        free(ADDR_TOP(*s));
        ADDR_TOP(*s) = NULL;
    } else {
        Address next = NEXT(ADDR_TOP(*s));
        free(ADDR_TOP(*s));
        ADDR_TOP(*s) = next;
    }
}

// int main(){
//     Stack s;
//     CreateStack(&s);
//     push(&s,9);
//     push(&s,9);
//     push(&s,9);
//     push(&s,9);
//     ElType buang;
//     pop(&s,&buang);
//     pop(&s,&buang);
//     pop(&s,&buang);
//     pop(&s,&buang);
//     DisplayStack(s);
//     return 0;
// }