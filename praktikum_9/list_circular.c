    #include "boolean.h"
    #include "list_circular.h"
    #include <stdio.h>
    #include <stdlib.h>

    Address getLastAddress(List l)
    {
        if(FIRST(l) == NULL){
            return NULL;
        } else {
            Address p = FIRST(l);
            while(NEXT(p) != FIRST(l)){
                p = (NEXT(p));
            }
            return p;
        }
    }


    /* PROTOTYPE */
    /****************** TEST LIST KOSONG ******************/
    boolean isEmpty(List l)
    /* Mengirim true jika list kosong. Lihat definisi di atas. */
    {
        return FIRST(l) == NULL;
    }

    /****************** PEMBUATAN LIST KOSONG ******************/
    void CreateList(List *l)
    /* I.S. l sembarang             */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    {
        FIRST(*l) = NULL;
    }

    /****************** Manajemen Memori ******************/
    Address allocate(ElType val)
    /* Mengirimkan Address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
    /* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
    /* Jika alokasi gagal, mengirimkan NULL */
    {
        Address p;
        p = (Address)malloc(sizeof(ElmtList));
        if (p != NULL){
            INFO(p) = val;
            NEXT(p) = NULL;
        }
    }
    void deallocate(Address P)
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian Address P */
    {
        free(P);
    }

    /****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
    Address search(List l, ElType val)
    /* Mencari apakah ada elemen list dengan INFO(P)= val */
    /* Jika ada, mengirimkan Address elemen tersebut. */
    /* Jika tidak ada, mengirimkan NULL */
    {
        Address p = FIRST(l);
        if(FIRST(l) == NULL){
            return NULL;
        } else {
            while(NEXT(p) != FIRST(l)){
                if(INFO(p) == val){
                    return p;
                }
                p = NEXT(p);
            }
            if(INFO(p) == val){
                return p;
            } else {
                return NULL;
            }
        }
    }

    boolean addrSearch(List l, Address p)
    /* Mencari apakah ada elemen list l yang beralamat p */
    /* Mengirimkan true jika ada, false jika tidak ada */
    {
        if(FIRST(l) == NULL){
            return FIRST(l) == p;
        } else {
            Address k = FIRST(l);
            while(NEXT(k) != FIRST(l)){
                if(k == p){
                    return true;
                }
                k = NEXT(k);
            }
            if(k == p){
                return true;
            } else {
                return false;
            }
        }
    }

    /****************** PRIMITIF BERDASARKAN NILAI ******************/
    /*** PENAMBAHAN ELEMEN ***/
    void insertFirst(List *l, ElType val)
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
    {
        Address p = allocate(val);
        if(p != NULL){
            Address k = FIRST(*l);
            if(FIRST(*l) == NULL){
                FIRST(*l) = p;
                NEXT(p) = p;
            } else {
                while(NEXT(k) != FIRST(*l)){
                    k = NEXT(k);
                }
                NEXT(k) = p;
                NEXT(p) = FIRST(*l);
                FIRST(*l) = p;
            }
        }
    }

    void insertLast(List *l, ElType val)
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    {
        Address p = allocate(val);
        if(p != NULL){
            if(FIRST(*l) == NULL){
                insertFirst(l, val);
            } else {
                Address last = getLastAddress(*l);
                NEXT(last) = p;
                NEXT(p) = FIRST(*l);
            }
        }
    }

    /*** PENGHAPUSAN ELEMEN ***/
    void deleteFirst(List *l, ElType * val)
    /* I.S. List l tidak kosong  */
    /* F.S. val adalah elemen pertama list l sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /*      First element yg baru adalah suksesor elemen pertama yang lama */
    /*      Alamat elemen terakhir di-dealokasi */
    {
        Address fst = FIRST(*l);
        *val = INFO(FIRST(*l));
        if(NEXT(FIRST(*l)) == FIRST(*l)){
            deallocate(fst);
            FIRST(*l) = NULL;
        } else {
            Address last = getLastAddress(*l);
            fst = NEXT(fst);
            NEXT(last) = fst;
            deallocate(FIRST(*l));
            FIRST(*l) = fst;
        }
    }
    void deleteLast(List *l, ElType * val)
    /* I.S. list tidak kosong */
    /* F.S. x adalah elemen terakhir list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /*      Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    /*      Alamat elemen terakhir di-dealokasi */
    {
        Address p = FIRST(*l);
        if(NEXT(p) == p){
            deleteFirst(l, val);
        } else {
            Address loc = NULL;
            while(NEXT(p) != FIRST(*l)){
                loc = p;
                p = NEXT(p);
            }
            *val = INFO(p);
            deallocate(p);
            NEXT(loc) = FIRST(*l);
        }
    }

    /****************** PROSES SEMUA ELEMEN LIST ******************/
    void displayList(List l)
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    {
        printf("[");
        if(FIRST(l) == NULL){
            printf("]");
        } else {
            Address p = FIRST(l);
            while(NEXT(p) != FIRST(l)){
                printf("%d,",INFO(p));
                p = NEXT(p);
            }
            printf("%d]",INFO(p));
        }
    }

    // int main(){
    //     List l;
    //     CreateList(&l);
    //     insertLast(&l, 6);
    //     ElType buang;
    //     deleteLast(&l,&buang);
    //     printf("%d\n",buang);
    //     displayList(l);
    //     return 0;
    // }

// int main(){
//     List l;
//     CreateList(&l);
//     insertFirst(&l,5);
//     insertFirst(&l,9);
//     insertLast(&l,1);
//     ElType buang;
//     deleteFirst(&l, &buang);
//     displayList(l);
//     Address tes = search(l,9);
//     if(tes == NULL){
//         printf("nt\n");
//     } else {
//         printf("%d\n",INFO(tes));
//     }
//     return 0;
// }
