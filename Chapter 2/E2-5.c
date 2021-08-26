//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 24/07/21.
//  Write the function any(s1,s2), which returns the first location in the string s1 where any character from the string s2
//  occurs, or -1 is s1 contains no characters from s2.
//

#include <stdio.h>

int any(char s[],char d[]);

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
    printf("The first occurence of s2 in s1 is at %d\n",any(s,d));
    return 0;
}

int any(char s[],char d[]){
    for(int k=0;d[k]!='\0';k++){
        for(int i=0;s[i]!='\0';i++){
            if(s[i]==d[k]){
                return i;
            }
        }
    }
    return -1;
}
