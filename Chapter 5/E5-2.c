//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 06/09/21.
//  Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?
//
//

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetchh(int);
int getfloat(float *);

int main(void){
    int check;
    float t=0;
    while((t=getch())!=EOF) {
        ungetchh(t);
        check=getfloat(&t);
        if(isdigit(check))
            printf("%f\n",t);
    }
    return 0;
}

// getfloat: get next float from input into *pf
int getfloat(float *pf){
    int c, sign, rng, d=1;
    float p;
    while(isspace(c=getch()))
        ;
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
        ungetchh(c);
        return 0;
    }
    sign = c=='-'?-1:+1;
    if(c=='-' || c=='+'){
        c=getch();
    }
    rng=c;
    for(*pf=0.0;isdigit(c) && c!='.';c=getch())
        *pf = 10.0 * *pf + (c-'0');
    if(c=='.')
        c=getch();
    for(p=0;isdigit(c);c=getch()){
        p = 10.0 * p +(c-'0');
        d*=10;
    }
    p=p/d;
    *pf+=p;
    return rng;
}

#define MAXSIZE 100
int BUFFER[MAXSIZE];
int bufp=0;

int getch(void){
    return (bufp>0)?BUFFER[--bufp]:getchar();
}

void ungetchh(int c){
    if(bufp<=MAXSIZE){
        BUFFER[bufp++]=c;
    }
    else
        printf("error:BUFFER full\n");
}
