//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 07/09/21.
//  Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s
//
//

#include <stdio.h>

void astrcat(char *, char *);

int main(void){
    char a[]="Hello", b[]=" Bolo!";
    astrcat(a,b);
    printf("%s\n",a);
    return 0;
}

void astrcat(char *s, char *t){
    while(*s++)
        ;
    s--;
    while(*s++ = *t++)
        ;
    return;
}

