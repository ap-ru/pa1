#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    
    //Access input information
    //Iterate through input letter through letter
    //Change each letter according to cypher
    //Output the updated word

    char word[100];
    char current = 'a';
    
    strcpy(word, argv[1]);
    if(argc > 1){
        for(int i = 2; i < argc; i++){
            strcat(word, " ");
            strcat(word, argv[i]);
        }
    }

    for(int i = 0; i < strlen(word); i++){
        current = word[i];
        if(isalpha(current) == 0)    
            putchar(current);
        else if(isupper(current)){
            current = (current + 13 - 65) % 26 + 65;
            putchar(current);
        }
        else{
            current = (current + 13 - 97) % 26 + 97;
            putchar(current);
        }
    }

    putchar('\n');

    return(0);
}
