//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 21/07/21.
//  Write a loop equivalent to the for loop above without using && or ||
//  for(int i=0;i<lim-1 && (c=getchar())!='\n' && c!=EOF;++i)
//

#include <stdio.h>

int main(){
    int c,lim=10;
    for(int i=0;i<lim-1;++i){
        if((c=getchar())!='\n'){
            if(c!=EOF){
                //SOMETHING
            }
        }
    }
        return 0;
}

