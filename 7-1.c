#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, const char* argv[]){
    int c;
    while(!isalnum(*argv[0])){
        argv[0]++;
    }
    while((c = getchar()) != EOF){
        if(strcmp(argv[0], "upper") == 0){
            putchar(toupper(c));
        } else {
            putchar(tolower(c));
        }
    }
    return 0;
}