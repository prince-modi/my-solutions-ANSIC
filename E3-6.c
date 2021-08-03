//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 03/08/21.
//  Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted
//  number must be padded with blanks on the left if necessary to make it wide enough.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void itob(int n, char str[], int padding);
void strrev(char str[]);

int main(){
    int n=10000;
    int p=5;
    char s[MAX]={0};
    itob(n,s,p);
    printf("Converted number with width of %d is %s\n",p,s);
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

void itob(int n, char s[], int p){
    int i, sign, len;
    sign=n;
    i=0;
    do{
        s[i++]=abs(n%10)+'0';
    }while(n/=10);
    if(sign<0)
        s[i++]='-';
    len=(int)strlen(s);
    if(len<p){
        for(int j=p-len;j>0;j--){
            s[i++]=' ';
        }
    }
    s[i]='\0';
    strrev(s);
}

