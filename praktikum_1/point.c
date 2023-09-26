#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"
void CreatePoint (POINT * P, float X, float Y)
{
    P->X = X;
    P->Y = Y;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P)
{
    float x,y;
    scanf("%f", &x);
    scanf("%f", &y);
    CreatePoint(P, x, y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P)
{
    printf("(%.2f,%.2f)", Absis(P),Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
{
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2)
{
    return Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2);
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
{
    return Absis(P) == 0 || Ordinat(P) == 0;
}
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P)
{
    return Ordinat(P) == 0;
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P)
{
    return Absis(P) == 0;
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P)
{
    int x = Absis(P);
    int y = Ordinat(P);
    if(x > 0 && y > 0)
    {
        return 1;
    }
    else if(x < 0 && y > 0)
    {
        return 2;
    }
    else if(x < 0 && y < 0)
    {
        return 3;
    }
    else if(x > 0 && y < 0)
    {
        return 4;
    }
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
{
    POINT baru;
    Absis(baru) = Absis(P) + 1;
    Ordinat(baru) = Ordinat(P);
    return baru;

}
/* Mengirim salinan P dengan absis ditambah satu */              
POINT NextY (POINT P)
{
    POINT baru;
    Absis(baru) = Absis(P);
    Ordinat(baru) = Ordinat(P) + 1;
    return baru;

}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
    POINT baru;
    Absis(baru) = Absis(P) + deltaX;
    Ordinat(baru) = Ordinat(P) + deltaY;
    return baru;

}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX)
{
    POINT baru;
    if (SbX)
    {
        Absis(baru) = Absis(P) ;
        Ordinat(baru) = Ordinat(P)*(-1) ;
        return baru;
    }
    else
    {
        Absis(baru) = Absis(P)*(-1) ;
        Ordinat(baru) = Ordinat(P) ;
        return baru;
    }

}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P)
{
    return sqrt((Absis(P))*(Absis(P)) + (Ordinat(P))*(Ordinat(P)));

}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2)
{
    return sqrt((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2)) + (Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2)));

}
/* Menghitung jarak antara P1 dan P2 */
void Geser (POINT *P, float deltaX, float deltaY)
{
    P->X +=deltaX;
    P->Y +=deltaY;

}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P)
{
    P->Y = 0;

}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P)
{
    P->X = 0;

}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX)
{
    if(SbX)
    {
        P->Y = -P->Y;
    }
    else
    {
        P->X = -P->X;
    }


}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut)
{
    float radian = Sudut/180*M_PI;
    float x_baru, y_baru;
    x_baru = P->X*cosf(radian) - P->Y*sinf(radian);
    y_baru = P->X*sinf(radian) + P->Y*cosf(radian);
    P->X = x_baru;
    P->Y = y_baru;

}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
void PersamaanLinearDuaVariabel (POINT P1, POINT P2)
{
    int a,b;
    a = (Ordinat(P1)-Ordinat(P2))/(Absis(P1)-Absis(P2));
    b = Ordinat(P2) - a*(Absis(P2));
    printf("(%d,%d)",a,b);

}
/* I.S. P1 dan P2 terdefinisi */
/* Prekondisi: dijamin a dan b merupaka bilangan bertipe integer */
/* F.S. Dibentuk sebuah persamaan garis y = ax + b yang memenuhi untuk P1 dan P2 */
/* Keluarkan nilai a dan b */
/* Output a dan b tercetak di layar sebagai bilangan bertipe integer dengan format "(a,b)" */