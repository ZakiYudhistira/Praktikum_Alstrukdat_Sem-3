#include "boolean.h"
#include "matrix.h"
#include <stdio.h>

Matrix salinBaru(Matrix input, int i_mulai, int j_mulai, int baris, int kolom)
{
    Matrix hasil;
    createMatrix(baris, kolom, &hasil);
    int i,j;
    for(i=0;i<baris;i++)
    {
        for(j=0;j<kolom;j++)
        ELMT(hasil,i,j) = ELMT(input, i_mulai+i,j_mulai+j);
    }
    return hasil;
}

int sumMatrix(Matrix m)
{
    int i,j;
    int sum = 0;
    for(i=0;i<ROW_EFF(m);i++)
    {
        for(j=0;j<COL_EFF(m);j++)
        {
            sum += ELMT(m, i ,j);
        }
    }
    return sum;
}

int getMax(Matrix utama, Matrix sub)
{
    Matrix temp;
    int inc_baris = 0, inc_kolom = 0;
    int maks = 0;
    while(inc_baris + ROW_EFF(sub) <= ROW_EFF(utama))
    {
        while (inc_kolom + COL_EFF(sub) <=COL_EFF(utama))
        {
            temp = salinBaru(utama,inc_baris,inc_kolom, ROW_EFF(sub), COL_EFF(sub));
            int i,j;
            {
                if (maks < sumMatrix(temp))
                {
                    maks = sumMatrix(temp);
                }
            }
            inc_kolom++;
        }
        inc_kolom = 0;
    inc_baris++;
    }
    return maks;
}

int main()
{
    Matrix utama;
    int baris, kolom, luas, maks = 0;
    scanf("%d %d %d", &baris, &kolom ,&luas);
    readMatrix(&utama, baris, kolom);
    int i,j;
    for(i=1;i<=luas;i++)
    {
        for(j=1;j<=luas;j++)
        if(i*j==luas)
        {
            if(i<=ROW_EFF(utama) && j<=COL_EFF(utama))
            {
                Matrix temp;
                createMatrix(i,j, &temp);
                if(getMax(utama, temp) > maks)
                {
                    maks = getMax(utama, temp);
                }
            }
            
        }
    }
    printf("%d\n", maks);
    return 0;
}