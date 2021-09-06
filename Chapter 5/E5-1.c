//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 06/09/21.
//  As writtenm getint treats a + or - not followed by a digit as a valide representation of zero. FIt it to push such a character
//  back on the input.
//
//

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetchh(int);
int getint(int *);

int main(void){
    int test=0,check;
    do {
        check=getint(&test);
        if(isdigit(check))
            printf("%d\n",test);
    } while((test=getch())!=EOF);
    return 0;
}

// getint: get next integer from input into *pn
int getint(int *pn){
    int c, sign, rng;
    
    while(isspace(c=getch()))
        ;
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
        ungetchh(c);
        return 0;
    }
    sign = (c=='-')?-1:1;
    if(c=='-' || c=='+'){
        c=getch();
    }
    rng=c;
    for(*pn=0;isdigit(c);c=getch())
        *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if(c!=EOF)
        ungetchh(c);
    return rng;
}

#define MAXSIZE 100
int BUFFER[MAXSIZE];
int bufp=0;

int getch(void){
    int c;
    c=(bufp>0)?BUFFER[bufp--]:getchar();
    return c;
}

void ungetchh(int c){
    if(bufp<MAXSIZE){
        BUFFER[bufp++]=c;
    }
    else
        printf("error:BUFFER full\n");
}
