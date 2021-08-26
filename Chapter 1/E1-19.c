//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 17/07/21.
//  Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its iput a line at a time.
//

#include <stdio.h>
#define MIN 20
#define MAX 1000

int linecheck(char line[],int min);
void reverse(char org[],char rev[]);

int main(){
    char line[MAX];
    char opp[MAX];
    while(1){
        reverse(line,opp);
        printf("%s\n",opp);
    }
    return 0;
}

int linecheck(char line[],int max){
    int c,i;
    c=0;
    for(i=0;i<=max && (c=getchar())!=EOF && c!='\n';++i){
        line[i]=c;
    }
    if(c=='\n'){
        line[i]=c;
        ++i;
    }
    line[i]='\0';
    return i;
}

void reverse(char line[],char rev[]){
    int len,i;
    i=0;
    len=linecheck(line, MAX);
    while((rev[len-i-1]=line[i])!='\0'){
        ++i;
    }
    rev[i]='\n';
    ++i;
    rev[i]='\0';
}
