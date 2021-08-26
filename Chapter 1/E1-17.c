
//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 17/07/21.
//  Write a program to print all input lines that are longer than 80 characters.
//

#include <stdio.h>
#define MIN 80
#define MAX 1000

int linecheck(char line[],int min);

int main(){
    int len;
    char line[MAX];
    while((len=linecheck(line,MAX))>0){
        if(len>MIN)
            printf("%sLength:%d",line,len);
    }
    return 0;
}

int linecheck(char line[],int max){
    int c,i;
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
