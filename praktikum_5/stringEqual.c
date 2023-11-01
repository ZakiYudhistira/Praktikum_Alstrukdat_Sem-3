#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

int stringLength(char *s) {
   int result =  0;
   int i = 0;
   while (s[i] != '\0') {
      ++result;
      ++i;
   }
   return result;
}

void printWord(Word word) {

   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

boolean isSame(Word l1 , char* l2){
    if(l1.Length!=stringLength(l2)){
        return false;
    }
    else{
        int i;
        for(i=0;i<stringLength(l2);i++){
            if(l1.TabWord[i] != l2[i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    char* MOVEUP = "MOVEUP";
    char* MOVEDOWN = "MOVEDOWN";
    char* MOVELEFT = "MOVELEFT";
    char* MOVERIGHT = "MOVERIGHT";
    char* N;
    START();
    IgnoreBlanks();
    ADVWORD();
    printf("Moving ");
    printWord(currentWord);
    printf(" ");
    ADVWORD();
    if(isSame(currentWord,MOVEUP)){
        printf("square upwards\n",N);
    }
    else if(isSame(currentWord,MOVEDOWN)){
        printf("square downwards\n",N);
    }
    else if(isSame(currentWord,MOVELEFT)){
        printf("square leftwards\n",N);
    }
    else if(isSame(currentWord,MOVERIGHT)){
        printf("square rightwards\n",N);
    }


    return 0;
}