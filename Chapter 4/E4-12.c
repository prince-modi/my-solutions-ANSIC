//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 27/08/21.
//  Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive
//  routine.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

void ritoa(int, char []);
int i=0;

int main(){
    int c=INT_MIN;
    char str[MAX]={0};
    ritoa(c, str);
    printf("%s\n",str);
    
    return 0;
}

void ritoa(int c, char str[]){
    if(c<0){
        str[0]='-';
        i++;
    }
    if(abs(c/10))
        ritoa(abs(c/10),str);
    str[i++]=abs(c%10)+'0';
    str[i]='\0';
}

