//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 18/06/21.
//  Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
//

#include <stdio.h>

int main() {
    int c, nb, nl, nt;
    nb=nl=nt=0;
    while((c=getchar())!= EOF){
        if(c==' '){
            //putchar(c);
            while((c = getchar()) == ' ');
            putchar(' ');
            putchar(c);
        }
        else{
            putchar(c);
        }
    }
}
