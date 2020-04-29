// Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELENGTH 80
#define LINESPERPAGE 10

void printpages(FILE *ifp, FILE *ofp);

int main(int argc, char *argv[]) {
    FILE *fp;
    while (--argc > 0) //goes until there are no more files to read
        if ((fp = fopen(*++argv, "r")) != NULL) {
            fprintf(stdout, "\n\n\t\t\tFile: %s\n\n", *argv);
            printpages(fp, stdout);
            fclose(fp);
        } else {
            printf("Could not open the file");
            return 1;
        }

    return 0;
}

void printpages(FILE *ifp, FILE *ofp)
{
    char c;
    int line = 0;
    int pageNum = 1;
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
        if (c == '\n') {
            ++line;
            if (line == LINESPERPAGE)
            {
                printf("\n\t\t\tPage %d End.\n\n", pageNum);
                ++pageNum;
                line = 0;
            }
        }

    }
}
