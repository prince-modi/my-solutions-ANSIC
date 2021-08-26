//
//  getch.c
//  c project
//
//  Created by Prince Bhagirath Modi on 26/08/21.
//

#include <stdio.h>
#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp=0;

int getch(void){
    return (bufp>0)?buf[--bufp]:getchar();
}

void ungetchh(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}

