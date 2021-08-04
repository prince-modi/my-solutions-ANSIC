//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 04/08/21.
//  Write the function strrindex(s,t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
//

#include <stdio.h>
#define MAX 1000        //maximum input line length

int getln(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[]="ould";

/* find all lines matching pattern */
int main(){
    char line[MAX]={0};
    int ind,found=0;
    while(getln(line,MAX)>0){
        if((ind=strindex(line, pattern))>=0){
            printf("%sThe index is %d",line,ind);
            found++;
        }
    }
    printf("%d\n",found);
}

/* getln: get line into s, return length*/
int getln(char ln[], int max){
    int c,i;
    
    i=0;
    while((c=getchar())!=EOF && c!='\n'){
        ln[i++]=c;
    }
    if(c=='\n'){
        ln[i++]=c;
    }
    ln[i]='\0';
    return i;
}

/* strindex: return index of rightmost occurence of t in s, -1 if none */
int strindex(char s[], char t[]){
    int i,j,k,occ;
    occ=-1;
    for(i=0;s[i]!='\0';i++){
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k]=='\0'){
            occ=i;
        }
    }
    return occ;
}
