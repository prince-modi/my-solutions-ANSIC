//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 24/07/21.
//  Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
//

#include <stdio.h>

void squeeze(char s[],char d[]);

int main(void){
    int c,i,j;
    char s[100];
    char d[100]={0};
    for(i=0;(c=getchar())!='\n' && c!=EOF;++i){
        s[i]=c;
    }
    s[++i]='\0';
    c=0;
    for(j=0;(c=getchar())!='\n' && c!=EOF;++j){
        d[j]=c;
    }
    d[++j]='\0';
    squeeze(s,d);
    printf("The squeezed string is:\"%s\"\n",s);
    return 0;
}

void squeeze(char s[],char d[]){
    int i,j,k;
    j=0;
    for(k=0;d[k]!='\0';k++){
        for(i=j=0;s[i]!='\0';i++){
            if(s[i]!=d[k]){
                s[j++]=s[i];
            }
        }
    s[j]='\0';
    }
}
