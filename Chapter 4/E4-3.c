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

#define MAXOP 100                           // max size of operand or operator
#define NUMBER '0'                          // signal that a number was found

int getop(char []);
void push(double);
double pop(void);


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

#define MAXVAL 100                          // maxiumum depth of val stack

int sp=0;                                   // stack pointer
double val[MAXVAL];                         // value stack

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

#include <ctype.h>

int getch(void);
void ungetchh(int);

int getop(char s[]){
    int i,c;
    while((s[0]=c=getch())==' '|| c=='\t')
        ;
    s[1]='\0';
    i=0;
    if(!isdigit(c) && c!='\n'){
        if(isdigit(s[++i]=getch()))
            while (isdigit(s[++i]=c=getch()))
                ;
        else if(c!='.'){
            ungetchh(s[i]);
            s[i]=0;
            return c;                       // returns anything other than number
        }
    }
    if(isdigit(c))
        while(isdigit(s[++i]=c=getch()))    // collect integer part
            ;
    if(c=='.')                              // collect fraction part
        while(isdigit(s[++i]=c=getch()))
            ;
    if(c=='\n')
        return c;
    s[i]='\0';
    if(c!=EOF)
        ungetchh(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void){
    return (bufp>0)?buf[--bufp]:getchar();
}

void ungetchh(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}
