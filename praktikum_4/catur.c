#include "boolean.h"
#include "matrix.h"
#include <stdio.h>



int main()
{
    Matrix catur;
    readMatrix(&catur,8,8);
    int i,j;
    int hitam, putih;
    hitam =0;
    putih = 0;
    for(i=0;i<ROW_EFF(catur);i++)
    {
        for(j=0;j<COL_EFF(catur);j++)
        {
            if(i % 2 == 0)
            {
                if(j % 2 == 0) //putih
                {
                    if(ELMT(catur,i,j)==1)
                    {
                        hitam++;
                    }
                }
                else
                {
                    if(ELMT(catur,i,j)==1)
                    {
                        putih++;
                    }
                }
            }
            else
            {
                if(j % 2 == 0) //putih
                {
                    if(ELMT(catur,i,j)==1)
                    {
                        putih++;
                    }
                }
                else
                {
                    if(ELMT(catur,i,j)==1)
                    {
                        hitam++;
                    }
                }
            }
        }
    }
    printf("%d %d\n", hitam, putih);
    return 0;
}