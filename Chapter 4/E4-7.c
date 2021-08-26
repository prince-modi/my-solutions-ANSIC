//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 25/08/21.
//  Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetchh()?
//


#include <stdio.h>
#include <stdlib.h>                                             // for atof()
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOF 100                                               // max size of operand or operator
#define VAR 26                                                  // max number of variables
#define NUMBER '0'                                              // signal that a number was found

int getop(char []);
void push(double);
double pop(void);

// reverse Polish calculator
int main()
{
    int type;
    double op2;
    char s[MAXOF];
    double v[VAR]={0};
    
    while ((type = getop(s))!=EOF) {
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
                push(pop()/op2);
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                if(type>='a' && type<='z'){
                    getop(s);
                    if(s[0]=='='){
                        getop(s);
                        v[type-'a']=atof(s);
                    }
                    else{
                        push(v[type-'a']);
                        if(isalpha(s[0])){
                            push(v[s[0]-'a']);
                        }
                        else
                            push(atof(s));
                    }
                }
                else
                    printf("error: unknown command %s\n",s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp=0;
double val[MAXVAL];

// push: push f onto value stack
void push(double f){
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error: stack full, can't push %g\n",f);
}

// pop: pop and return top value from stack
double pop(void){
    if(sp>0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void);
void ungetchh(int);

// getop: get next operator or numeric operand
int getop(char s[]){
    int i,c=0;
    
    while((s[0]=c=getch())==' '|| c=='\t')
        ;
    s[1]='\0';
    if (!isdigit(c) && c != '.')
        return c;
    i=0;
    if (isdigit(c))
        while(isdigit(s[++i]=c=getch()))
            ;
    if(c=='.')
        while(isdigit(s[++i]=c=getch()))
            ;
    s[i]='\0';
    if(c != EOF)
        ungetchh(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void){
    return (bufp>0) ? buf[--bufp]: getchar();
}

void ungetchh(int c){
    if(bufp>BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}

// ungets can be implemented in two ways, one where it is aware of the buffer and directly modifies it
void ungets(char s[]){
    if(bufp>BUFSIZE)
        printf("ungets: too many characters in string\n");
    else
        for(int i=0;i<strlen(s);i++){
            buf[bufp++]=s[i];
        }
}

// another way it can be implemented is by using the ungetchh() function where ungets uses the function to modify the values in the
// buffer
void ungetstwo(char s[]){
    if(bufp>BUFSIZE)
        printf("error");
    else
        for(int i=0;i<strlen(s);i++)
            ungetchh(s[i]);
}
