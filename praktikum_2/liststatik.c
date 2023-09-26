#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
{
    int i;
    for(i=0;i<CAPACITY;i++)
    {
        ELMT(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
int listLength(ListStatik l)
{
    int i;
    int count=0;
    for(i=0;i<CAPACITY;i++)
    {
        if (ELMT(l, i) != MARK){
            count++;
        }
    }
    return count;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return 0;
}
IdxType getLastIdx(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return listLength(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return i < CAPACITY && i >= IDX_MIN;
}

boolean isIdxEff(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return i < listLength(l) && i >= IDX_MIN;
}

/* ********** TEST KOSONG/PENUH ********** */
boolean isEmpty(ListStatik l)
/* *** Test List kosong *** */
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
    return ELMT(l, 0) == MARK;
}

boolean isFull(ListStatik l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

{
    return ELMT(l, CAPACITY-1) != MARK;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
    int n;
    CreateListStatik(l);
    scanf("%d", &n);
    while (n < IDX_MIN || n > CAPACITY)
    {
        scanf("%d", &n);
    }
    int i;
    if (n > 0)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d", &ELMT(*l, i));
        }
    }
    
}

void printList(ListStatik l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    int panjang;
    panjang = listLength(l);
    if (panjang == 0)
    {
        printf("[]");
    }
    else
    {
        int i;
        printf("[");
        for (i=0;i<panjang;i++)
        {
            if (i==0)
            {
                printf("%d", ELMT(l, i));
            }
            else
            {
                printf(",%d", ELMT(l, i));
            }
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
{
    ListStatik hasil;
    CreateListStatik(&hasil);
    if (plus)
    {
        int i;
        for (i=0;i<listLength(l1);i++)
        {
            ELMT(hasil, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    else
    {
        int i;
        for (i=0;i<listLength(l1);i++)
        {
            ELMT(hasil, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return hasil;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
    if (listLength(l1) != listLength(l2))
    {
        return false;
    }
    else
    {
        int i;
        for (i=0 ; i<listLength(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                return false;
            }
        }
    }
    return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
int indexOf(ListStatik l, ElType val)
{
    int panjang;
    panjang = listLength(l);
    if (panjang == 0)
    {
        return IDX_UNDEF;
    }
    else
    {
        int i;
        for (i=0 ; i < panjang ; i++)
        {
            if (ELMT(l, i) == val)
            {
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for(i = 1 ; i < listLength(l) ; i++)
    {
        if (ELMT(l,i) > *max)
        {
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min)
        {
            *min = ELMT(l,i);
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
{
    int i,temp1, temp2 ,panjang;
    temp1 = ELMT(*l, 0);
    temp2 = ELMT(*l,1);
    ELMT(*l, 0) = val;
    panjang = listLength(*l);
    for (i=1 ; i <= panjang ; i++)
    {
        temp2 = ELMT(*l,i);
        ELMT(*l,i) = temp1;
        temp1 = temp2;
    }

}

void insertAt(ListStatik *l, ElType val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
{
    int i,temp1, temp2 ,panjang;
    temp1 = ELMT(*l, idx);
    temp2 = ELMT(*l,idx+1);
    ELMT(*l, idx) = val;
    panjang = listLength(*l);
    for (i=idx+1 ; i <= panjang ; i++)
    {
        temp2 = ELMT(*l,i);
        ELMT(*l,i) = temp1;
        temp1 = temp2;
    }

}
void insertLast(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, listLength(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
{
    int i, panjang;
    panjang = listLength(*l);
    *val = ELMT(*l, 0);
    for (i=0 ; i < panjang-1 ; i++)
    {
        ELMT(*l,i) = ELMT(*l, i+1);
    }
    ELMT(*l,panjang-1) = MARK;
}
void deleteAt(ListStatik *l, ElType *val, IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
{
    int i, panjang;
    panjang = listLength(*l);
    *val = ELMT(*l, idx);
    for (i=idx ; i < panjang-1 ; i++)
    {
        ELMT(*l,i) = ELMT(*l, i+1);
    }
    ELMT(*l,panjang-1) = MARK;
}
void deleteLast(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, listLength(*l)-1);
    ELMT(*l, listLength(*l)-1) = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    if (!isEmpty(*l))
    {
        int panjang;
        panjang = listLength(*l);
        int i,j,max,min,temp,id_max,id_min;
        if (asc)
        {
            for(i=0 ; i < panjang -1 ; i++)
            {
                for(j=i+1 ; j < panjang ; j++)
                {
                    if(ELMT(*l, j)<ELMT(*l, i))
                    {
                        temp = ELMT(*l,i);
                        ELMT(*l,i) = ELMT(*l,j);
                        ELMT(*l,j) = temp;
                    }
                }
            }
        }
        else
        {
            for(i=0 ; i < panjang -1 ; i++)
            {
                for(j=i+1 ; j < panjang ; j++)
                {
                    if(ELMT(*l, j) >ELMT(*l, i))
                    {
                        temp = ELMT(*l,i);
                        ELMT(*l,i) = ELMT(*l,j);
                        ELMT(*l,j) = temp;
                    }
                }
            }
        }
    }
}

// int main()
// {
//     ListStatik ini_list;
//     readList(&ini_list);
//     sortList(&ini_list, false);
//     printList(ini_list);
//     return 0;
// }