#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows; COL_EFF(*m) = nCols; 
}

boolean isMatrixIdxValid(int i, int j){
    return (0 <= i && i < ROW_CAP) && (0 <= j && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m)-1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (0 <= i && i < ROW_EFF(m)) && (0 <= j && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMT(m,i,i);
}

void copyMatrix(Matrix mIn, Matrix *mOut){
    ElType c = COL_EFF(mIn), r = ROW_EFF(mIn);
    COL_EFF(*mOut) = c;
    ROW_EFF(*mOut) = r;
    
    *mOut = mIn;
}

void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow,nCol,m);
    IdxType i,j;
    for(i=0;i<nRow;i++){
        for(j=0;j<nCol;j++){
            scanf("%d",&ELMT(*m,i,j));
        }
    }
}

void displayMatrix(Matrix m){
    IdxType i,j,r = ROW_EFF(m),c = COL_EFF(m);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(j){
                printf(" %d",ELMT(m,i,j));
            } else {
                printf("%d",ELMT(m,i,j));
            }
        }
        printf("\n");
    }
}

Matrix addMatrix(Matrix m1, Matrix m2){
    IdxType i,j,r = ROW_EFF(m1), c = COL_EFF(m1);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ELMT(m1,i,j) += ELMT(m2,i,j);
        }
    }
    return m1;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    IdxType i,j,r = ROW_EFF(m1), c = COL_EFF(m1);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ELMT(m1,i,j) -= ELMT(m2,i,j);
        }
    }
    return m1;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m3; createMatrix(ROW_EFF(m1),COL_EFF(m2),&m3);
    IdxType i,j,k,r = ROW_EFF(m1),c = COL_EFF(m2),s = COL_EFF(m1);
    ElType sum;
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            sum = 0;
            for(k=0;k<s;k++){
                sum += (ELMT(m1,i,k) * ELMT(m2,k,j));
            }
            ELMT(m3,i,j) = sum;
        }
    }

    return m3;
}

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod){
    Matrix m3; createMatrix(ROW_EFF(m1),COL_EFF(m2),&m3);
    IdxType i,j,k,r = ROW_EFF(m1),c = COL_EFF(m2),s = COL_EFF(m1);
    ElType sum;
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            sum = 0;
            for(k=0;k<s;k++){
                sum += ELMT(m1,i,k) * ELMT(m2,k,j);
            }
            ELMT(m3,i,j) = sum % mod;
        }
    }

    return m3;
}

Matrix multiplyByConst(Matrix m, ElType x){
    IdxType i,j,r = ROW_EFF(m),c = COL_EFF(m);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ELMT(m,i,j) *= x;
        }
    }
    return m;
}

void pMultiplyByConst(Matrix *m, ElType k){
    IdxType i,j,r = ROW_EFF(*m),c = COL_EFF(*m);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ELMT(*m,i,j) *= k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2){
    IdxType i,j,r = ROW_EFF(m1),c = COL_EFF(m2);
    if(countElmt(m1) == countElmt(m2)){
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(ELMT(m1,i,j) != ELMT(m2,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return !isMatrixEqual(m1,m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m){
    return ROW_EFF(m)*COL_EFF(m);
}

boolean isSquare(Matrix m){
    return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m){
    IdxType i,j,r = ROW_EFF(m),c = COL_EFF(m);
    if(isSquare(m)){
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(ELMT(m,i,j) != ELMT(m,j,i)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

boolean isIdentity(Matrix m){
    IdxType i,j,r = ROW_EFF(m),c = COL_EFF(m);
    if(isSquare(m)){
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(i == j && ELMT(m,i,j) != 1){
                    return false;
                }
                if(i != j && ELMT(m,i,j) != 0){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

boolean isSparse(Matrix m){
    IdxType i,j,r = ROW_EFF(m),c = COL_EFF(m), count = 0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(ELMT(m,i,j) != 0){
                count++;
            }
        }
    }
    return count <= countElmt(m)/20.0;
}

Matrix negation(Matrix m){
    return multiplyByConst(m,(-1));
}

void pNegation(Matrix *m){
    IdxType i,j,r = ROW_EFF(*m),c = COL_EFF(*m);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ELMT(*m,i,j) *= -1;
        }
    }
}

float determinant(Matrix m){
    
}

Matrix transpose(Matrix m){
    Matrix m1;
    createMatrix(COL_EFF(m),ROW_EFF(m),&m1);
    IdxType i,j,r = ROW_EFF(m1),c = COL_EFF(m1);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ELMT(m1,i,j) = ELMT(m,j,i);
        }
    }

    return m1;
}

void pTranspose(Matrix *m){
    Matrix m1;
    createMatrix(COL_EFF(*m),ROW_EFF(*m),&m1);
    IdxType i,j,r = ROW_EFF(m1),c = COL_EFF(m1);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ELMT(m1,i,j) = ELMT(*m,j,i);
        }
    }
    COL_EFF(*m) = COL_EFF(m1);
    ROW_EFF(*m) = ROW_EFF(m1);
    *m = m1;
}

// int main(){
//     Matrix m1,m2,m3;
//     createMatrix(2,3,&m1);
//     readMatrix(&m1,2,3);
//     pTranspose(&m1);
//     displayMatrix(m1);
// }