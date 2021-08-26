//
//  stack.c
//  c project
//
//  Created by Prince Bhagirath Modi on 26/08/21.
//

#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

static int sp=0;
static double val[MAXVAL];

void push(double f){
    if(sp<MAXVAL)
        val[sp++]=f;
    else
        printf("error: stack overflow, can't push %g\n",f);
}

double pop(void){
    if(sp>0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}
