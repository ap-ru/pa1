#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    for(int i = 1; i <= argc-1; i++){
        for(int j = i + 1; j <= argc-1; j++){
            if(strcmp(argv[i], argv[j]) == 1){
                char* temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
                //printf("all good");
            }
        }
    }
    for(int i = 1; i <= argc-1; i++){
        printf("%s\n", argv[i]);
    }
    return EXIT_SUCCESS;
}