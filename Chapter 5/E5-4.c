//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 07/09/21.
//  Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
//
//

#include <stdio.h>

int strend(char *, char *);

int main(void){
    char a[]="More Hello", b[]="Hello";
    printf("%d\n",strend(a, b));
    return 0;
}

int strend(char *s, char *t){
    int i=0;
    while(*++s)
        ;
    for(;*t;t++,i++)
        ;
    s-=i;
    t-=i;
    for(;*s==*t;s++,t++)
        if(*t=='\0')
            return 1;
    return 0;
}

