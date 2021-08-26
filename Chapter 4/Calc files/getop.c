//
//  getop.c
//  c project
//
//  Created by Prince Bhagirath Modi on 26/08/21.
//

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

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
