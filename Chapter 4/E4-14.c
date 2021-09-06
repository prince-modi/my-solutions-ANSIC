//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 06/09/21.
//
//

#include <stdio.h>
#define swap(t,x,y) \
    t=x;\
    x=y;\
    y=t;

int main(){
    int t,x=10,y=20;
    swap(t,x,y);
    printf("%d %.d\n",x,y);
    return 0;
}

