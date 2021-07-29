//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 26/07/21.
//  Write a function escape(s,t) that converts charactess newline and tab into visible escape sequences like \n and \t as it copies the string t to s.
//  Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
//

#include <stdio.h>
#define MAX 100

void escape(char s[], char t[]);
void npcape(char s[], char t[]);

int main(){
    char s[MAX]="Hello\tBolo";
    char t[MAX]={0};
    
    escape(t,s);
    printf("Original String: %s\nNew String: %s\n",s,t);
    npcape(s,t);
    printf("New Original String: %s\nOrginal String: %s\n",t,s);
    return 0;
}

void escape(char s[], char t[]){
    int i,j;
    for(i=j=0;t[i]!='\0';++i,++j){
        switch (t[i]) {
            case '\n':
                s[j]='\\';
                s[++j]='n';
                break;
            case '\t':
                s[j]='\\';
                s[++j]='t';
                break;
            default:
                s[j]=t[i];
                break;
        }
    }
    s[++j]='\0';
    return;
}

void npcape(char s[], char t[]){
    int i,j;
    for(i=j=0;t[i]!='\0';++i,++j){
        switch (t[i]) {
            case '\\':
                j++;
                if(t[j]=='n'){
                    s[i]='\n';
                }
                else if(t[j]=='t'){
                    s[i]='\t';
                }
                break;
                
            default:
                s[i]=t[j];
                break;
        }
    }
    return;
}
