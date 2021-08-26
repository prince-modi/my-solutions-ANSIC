//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 18/06/21.
//  Write a program to count blanks, tabs, and newlines.
//

#include <stdio.h>

int main() {
    int c, nb, nl, nt;
    nb=nl=nt=0;
    while((c=getchar())!= EOF){
        if(c=='\n'){
            ++nl;
        }
        else if(c ==' '){
            ++nb;
        }
        else if(c=='\t'){
            ++nt;
        }
    }
    printf("\nNo of blank, tabs, and newlines is %d,%d,%d\n", nb, nt, nl);
    return 0;
}
