//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 03/08/21.
//  In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value
//  of n equal to -(2^wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it
//  runs.
//
//  Why does this version not handle the largest negative number?
//  The largest negative value for INT32 is -2147483648, and the largest positive value for INT32 is 2147483647, so when you try to
//  convert the INT32_MIN at line 52, it converts into itself. Because this is a two's complement number representation.
//
//  Using the absolute value.
//  Absolute value takes a number, if it is positive keeps it positive, if it is negative basically multiplies it with -1, and turns
//  in into positive.
//  abs(x)->x>0?x:-(x)
//
//  Explainations on https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_3:Exercise_4


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 100

void strrev(char str[]);
void itoa(int n, char str[]);

int main(){
    
    int n=INT32_MIN;
    char s[MAX]={0};
    
    itoa(n,s);
    printf("%s\n",s);
    return 0;
}

void strrev(char s[]){
    int c,i,j;

    for(i=0,j=(int)strlen(s)-1;i<j;i++,j--){
            c=s[i];
            s[i]=s[j];
            s[j]=c;
    }
}

void itoa(int n, char s[]){
    int i, sign;
    sign=n;
    i=0;
    
    do{
        s[i++]=abs(n%10)+'0';
    }while ((n/=10));
    
    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    strrev(s);
}

