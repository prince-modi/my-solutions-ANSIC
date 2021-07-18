//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 18/06/21.
//  Write a program to print a histogram of the frequencies of different characters in its input.
//

#include <stdio.h>
#define LM 26

int main(){
    int c,nlen;
    nlen=0;
    int nalph[LM];
    for(int i=0;i<LM;++i){
        nalph[i]=0;
    }
    while((c=getchar())!=EOF){
        if(c>='a'&&c<='z'){
            ++nalph[c-97];
        }
    }
    for(int i=0;i<LM;i++){
        if(nalph[i]!=0){
            printf("%c:%d ",i+97,nalph[i]);
            for(int k=0;k<nalph[i];k++){
                printf("=");
            }
            printf("\n");
        }
    }
}
