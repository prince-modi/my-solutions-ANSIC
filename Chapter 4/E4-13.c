//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 27/08/21.
//  Write a recursive version of the function reverse(s), which reverses the string s in place.
//

#include <stdio.h>
#include <string.h>

void revstr(char [], int, int);
void mswap(char [], int, int);

int main(){
    char str[]="It works?";
    int len=(int)strlen(str);
    revstr(str,0,len-1
         );
    printf("%s\n",str);
    return 0;
}

void revstr(char str[], int i, int len){
    if(i>=len)
        return;
    if(len>0){
        revstr(str, i+1, len-1);
    }
    mswap(str, len, i);
}

void mswap(char str[],int i,int j){
    int temp;
    
    temp=str[i];
    str[i]=str[j];
    str[j]=temp;
}
