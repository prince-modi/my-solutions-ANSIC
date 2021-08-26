//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 18/06/21.
//  Write a program detab that replaces tabs in the input with the proper number of blanks
//  to space to the next tab stop. Assumbe a fxed set of tabs stops, say every n columns.
//  Should n be a variable or a symbolic parameter?
//

#include <stdio.h>

int main(){
    int c,n,check;
    n=4;
    check=0;
    while((c=getchar())!=EOF){
        check=check%4;
        if(n<0 || check==0){
            n=4;
        }
        if(c=='\t'){
            for(int i=0;i<n;i++){
                putchar(' ');
                ++check;
            }
        }
        else{
            putchar(c);
            ++check;
        }
        if(c=='\n'){
            check=0;
            n=4;
        }
        n=4;
        n=n-check;
    }
}
