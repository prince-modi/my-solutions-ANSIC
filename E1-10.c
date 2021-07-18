//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 17/07/21.
//  Write a program to copy its input to its output, replacing each tab by \t, eacg backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguos way.

#include <stdio.h>

int main() {
    int c, nb, nl, nt;
    nb=0;
    nl=0;
    nt=0;
    while((c=getchar())!= EOF){
        if(c=='\t'){
            putchar('\\');
            putchar('t');
        }
        else if(c=='\b'){
            putchar('\\');
            putchar('b');
        }
        else if(c=='\\'){
            putchar('\\');
            putchar('t');
        }
        else{
            putchar(c);
        }
    }
}
