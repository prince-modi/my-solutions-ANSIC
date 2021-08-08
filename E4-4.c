//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 04/08/21.
//  Given the basic framework, it's straightforward to exten the calculator. Add the modulus (%) operator and provisions for negative
//  numbers.
//

#include <stdio.h>
#include <stdlib.h>                         // for atof()
#include <math.h>

#define MAXOP 100                           // max size of operand or operator
#define NUMBER '0'                          // signal that a number was found

//function declaration
int getop(char []);
void push(double);
double pop(void);
void print(void);
void duplicate(void);
void swap(void);
void clr(void);


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
            case '?':
                print();
                break;
            case 'd':
                duplicate();
                break;
            case '>':
                clr();
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

//push: push f onto value stack
void push(double f){
    if(sp<MAXVAL)
        val[sp++]=f;
    else
        printf("error: stack overflow, can't push %g\n",f);
}

//pop: pop and return top value from stack
double pop(void){
    if(sp>0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

//print: print top value from stack without modifying aything
void print(void){
    printf("The element at the top of the stack is %g\n",val[sp]);
}

//duplicate: return top value from stack
void duplicate(void){
    double temp;
    temp=pop();
    push(temp);
    push(temp);
}

//swap: swap top two values in the stack
void swap(void){
    double temp;
    if(sp>1){
        temp=val[sp];
        val[sp]=val[sp-1];
        val[sp-1]=temp;
    }
    else
        printf("error: not enough items in stack\n");
}

//clr: empty the stack
void clr(void){
    for(int i=0;i<MAXVAL;i++)
        val[i]=0;
}

#include <ctype.h>

int getch(void);
void ungetchh(int);

//getop: get next operator or numeric operand
int getop(char s[]){
    int i,c;
    while((s[0]=c=getch())==' '|| c=='\t')
        ;
    s[1]='\0';
    i=0;
    if(isalpha(c)){
        while (isalpha(s[++i]=c=getch()))
            ;
        ungetchh(s[i]);
        s[i]=0;
        return s[0];
    }
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
