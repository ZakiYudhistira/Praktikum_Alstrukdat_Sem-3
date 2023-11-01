#include "wordmachine.h"
#include "charmachine.h"
#include <stdio.h>
#define endin printf("\n");

boolean compare(Word word1, Word word2){
    if (word1.Length < word2.Length){
        return true;
    } else if (word1.Length > word2.Length){
        return false;
    } else {
        int length = word1.Length;
        int i;
        for(i = 0 ; i < length ; i++){
            if(word1.TabWord[i] != word2.TabWord[i]){
                if(word1.TabWord[i]-'a' > word2.TabWord[i]-'a'){
                    return false;
                } 
            }
        } return true;
    }
}

void bubbleSort(Word array[], int length){
    int i,j;
    Word temp;
    for(i = 0 ; i < length ; i++){
        for(j = 0 ; j < length-1 ; j++){
            if(!compare(array[j],array[j+1])){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

int main(){
    Word listWord[100];
    int i = 0;
    STARTWORD();
    while(!EndWord){
        listWord[i] = currentWord;
        i++;
        ADVWORD();
    }
    // bubbleSort(listWord, i+1);
    int j;
    bubbleSort(listWord,i+1);
    for(j = 0 ; j < i ; j++){
        printWord(listWord[j]);
        endin;
    }
    return 0;
}