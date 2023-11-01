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

boolean isSub(Matrix utama, Matrix sub)
{
    if(countElmt(sub)>countElmt(utama))
    {
        return false;
    }
    else if(ROW_EFF(sub) > ROW_EFF(utama) || COL_EFF(sub) > COL_EFF(utama))
    {
        return false;
    }
    else if(isMatrixEqual(sub,utama))
    {
        return true;
    }
    else
    {
        Matrix temp;
        int inc_baris = 0, inc_kolom = 0;
        while(inc_baris + ROW_EFF(sub) <= ROW_EFF(utama))
        {
            while (inc_kolom + COL_EFF(sub) <= COL_EFF(utama))
            {
                temp = salinBaru(utama,inc_baris,inc_kolom, ROW_EFF(sub), COL_EFF(sub));
                if(isMatrixEqual(temp,sub))
                {
                    return true;
                }
                inc_kolom++;
            }
            inc_kolom = 0;
        inc_baris++;
        }
        return false;
    }
}

int main()
{
    Matrix puzzle_utama;
    Matrix temp;
    Matrix potongan;
    boolean berhasil;
    berhasil = true;
    int baris, kolom, jumlah_puzzle;
    int k;
    scanf("%d %d", &baris, &kolom);
    readMatrix(&puzzle_utama, baris, kolom);
    scanf("%d",&jumlah_puzzle);
    for(k=0;k<jumlah_puzzle;k++)
    {
        scanf("%d %d", &baris, &kolom);
        readMatrix(&potongan, baris, kolom);
        if(!isSub(puzzle_utama, potongan))
        {
            berhasil = false;
            break;
        }
        
    }
    if(berhasil)
    {
        printf("Puzzle dapat diselesaikan.\n");
    }
    else
    {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }

    return 0;
}