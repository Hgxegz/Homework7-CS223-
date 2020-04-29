#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 264

void checkLine( char *lineone, char *linetwo, int linenumber ) //prints the line when there is different strings with line number
{
  if(strcmp (lineone, linetwo) < 0 || strcmp (lineone, linetwo) > 0)
    printf( "%d<%s\n%d>%s\n", linenumber, lineone, linenumber, linetwo);
}

int main(int argc, const char *argv[]){
    char line1[MAXLINE], line2[MAXLINE];
    if(argc != 3){ //makes sure the parameters are correct
        printf("Cannot process given info.");
    }
    FILE *fileOne = fopen(argv[1], "r"); 
    FILE *fileTwo = fopen(argv[2], "r");
    if(!fileOne) //checks if file 1 opens
        printf("Cannot open the first file");
    
    if(!fileTwo) //checks if file 2 opens
        printf("Cannot open the second file");
    int lineCounter = 1; //line counter to print out the line number a mismatch occurs
    while((fgets(line1, MAXLINE, fileOne) != NULL) && (fgets(line2, MAXLINE, fileTwo) != NULL)){ //iterates through the files line by line
        checkLine(line1, line2, lineCounter);
        ++lineCounter;
    }

    return 0;
}