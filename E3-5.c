//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 03/08/21.
//  Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular
//  itob(n,s,16) formats n as a hexadecimal integer in s.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

void itob(int n, char str[], int base);
void strrev(char str[]);

int main(){
    int n=-9178;
    char s[MAX]={0};
    itob(n,s,16);
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

void itob(int n, char s[], int b){
    char ch[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, sign, temp;
    sign=n;
    i=0;
    do{
        temp=abs(n%b);
        s[i++]=ch[temp];
    }while(n/=b);
    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    strrev(s);
}

