//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 17/07/21.
//  Write a program to print a histogram of the lenghts of words in input.
//

#include <stdio.h>

int main(){
    int c,nlen;
    nlen=0;
    while((c=getchar())!=EOF){
        if(c==' '||c=='\n'||c=='\t'){
            //printf("%3s"," ");
            for(int i=0;i<nlen;++i){
                printf("%s","=");
            }
            printf("\n");
            nlen=0;
        }
        else{
            //putchar(c);
            ++nlen;
        }
    }
}
