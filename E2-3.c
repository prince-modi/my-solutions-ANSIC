//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 24/07/21.
//  Write the function htoi(s), which converts a string of hexadecimal digits into its equivalent integer value.
//  The allowable digits are 0 through 9, a through f, and A through F.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

long htoi(char s[]);

int main(void){
    printf("%lu\n",htoi("f43"));
    return 0;
}

long htoi(char hs[]){
    char c,d;
    unsigned long i,result;
    result=0;
    i=strlen(hs);
    for(int k=0,j=i-1;k<i;++k,--j){
        c=hs[k];
        d=c;
        c=c-'0';
        switch (d) {
            case 'a':
            case 'A':
                c=10;
                break;
            case 'b':
            case 'B':
                c=11;
                break;
            case 'c':
            case 'C':
                c=12;
                break;
            case 'd':
            case 'D':
                c=13;
                break;
            case 'e':
            case 'E':
                c=14;
                break;
            case 'f':
            case 'F':
                c=15;
                break;
            default:
                break;
        }
        result=result+(c*pow(16,j));
    }
    return result;
}

