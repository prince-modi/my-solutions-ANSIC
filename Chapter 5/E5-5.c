//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 07/09/21.
//  Write versions fo the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their
//  argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
//
//

#include <stdio.h>
#include <string.h>

void astrncpy(char *, char *, int);
void astrncat(char *, char *, int);
int astrncmp(char *, char *, int);


int main(void){
    char a[50]="Heklo", b[]="Hello";
    astrncat(a, b, 4);
    printf("%d\n",astrncmp(a, b, 3));
    printf("%s\n",a);
    return 0;
}

void astrncpy(char *s, char *t, int n){
    /*if(n>strlen(t)){
        printf("error: n argument greater than string length\n");
        return;
    }*/
    for(int i=0;i<n;i++)
        *s++ = *t++;
}

void astrncat(char *s, char *t, int n){
    /*if(n>strlen(t)){
        printf("error: n argument greater than string length\n");
        return;
    }*/
    while(*++s)
        ;
    for(int i=0;i<n;*s++ = *t++,++i)
        ;
}

int astrncmp(char *s, char *t, int n){
    /*if(n>strlen(t)){
        printf("error: n argument greater than string length\n");
        return;
    }*/
    for(int i=0;*s == *t;s++,t++,++i)
        if(i==n)
            return 0;
    return *s - *t;
}

