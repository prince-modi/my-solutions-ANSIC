//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 08/08/21.
//  Given the basic framework, it's straightforward to exten the calculator. Add the modulus (%) operator and provisions for negative
//  numbers.
//

#include <stdio.h>
#include <stdlib.h>                         // for atof()
#include "calc.h"

#define MAXOP 100                           // max size of operand or operator


int main(){
    int type;
    double op2;
    char s[MAXOP];
    
    while((type=getop(s))!=EOF){
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            case '-':
                op2=pop();
                push(pop()-op2);
                break;
            case '/':
                op2=pop();
                if(op2!=0.0)
                    push(pop()/op2);
                else
                    printf("error: zero division\n");
                break;
            case '%':
                op2=pop();
                if(op2!=0.0)
                    push((int)pop()%(int)op2);
                else
                    printf("error: zero division\n");
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }
    return 0;
}
