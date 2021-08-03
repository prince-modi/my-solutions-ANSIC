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
    int n=255;
    char s[MAX]={0};
    for(int i=2;i<37;i++){                                  //limiting the base to 36 Maximum
        itob(n,s,i);
        printf("Decimal %d in base %3d : %s\n",n,i,s);
    }
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
    char ch[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";       //character array to use for conversion from decimal to n-base
    int i, sign, temp;
    sign=n;
    i=0;
    do{
        temp=abs(n%b);                                       
        s[i++]=ch[temp];                                    //takes the temp value from character array and places that in the string
    }while(n/=b);
    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    strrev(s);
}

