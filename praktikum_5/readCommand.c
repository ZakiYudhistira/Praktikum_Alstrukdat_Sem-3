#include "wordmachine.h"
#include "charmachine.h"
#include <stdio.h>
#define endin printf("\n");

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

int main() {
    Word output;
    output.Length = 0;
    STARTWORD();
    while(currentChar != MARK){
        output.TabWord[output.Length] = currentChar;
        output.Length++;
        ADV();
    }
    printWord(output);
    endin;
    printf("%d\n",output.Length);
    return 0;
}