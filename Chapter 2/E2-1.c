//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 21/07/21.
//  Write a program to determine the ranges of char, short, int, and long variables, both signed
//  and unsigned, by printing appropriate values from standard headers and by direct computation.
//  Harder if you compute them: determine the ranges of the various floating-point types.
//

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    char c;
    short s,t;
    unsigned short us;
    int i,k;
    unsigned int ui;
    long l,g;
    unsigned long ul;
    float f;
    double d;
    long double ld;
    printf("CHAR MIN:%d,MAX:%d\n",SCHAR_MIN,SCHAR_MAX);
    printf("UNSIGNED CHAR MAX:%d\n",UCHAR_MAX);
    printf("SHORT MIN:%d,MAX:%d\n",SHRT_MIN,SHRT_MAX);
    printf("UNSIGNED SHORT MAX:%d\n",USHRT_MAX);
    printf("INTEGER MIN:%d,MAX:%d\n",INT_MIN,INT_MAX);
    printf("UNSIGNED INTEGER MAX:%u\n",UINT_MAX);
    printf("LONG MIN:%ld,MAX:%ld\n",LONG_MIN,LONG_MAX);
    printf("UNSIGNED LONG MAX:%lu\n",ULONG_MAX);
    printf("FLOAT MIN:%f,MAX:%f\n",FLT_MIN,FLT_MAX);
    printf("DOUBLE MIN:%f,MAX:%f\n",DBL_MIN,DBL_MAX);
    printf("LONG DOUBLE MIN:%Lf,MAX:%Lf\n",LDBL_MIN,LDBL_MAX);
    
    s=0;
    us=s-1;
    ui=s-1;
    ul=s-1;
    printf("MAX SHORT:%d,INTEGER:%u,LONG:%lu\n",us,ui,ul);
    
    for(c=0;c>-1;c++){
        c=c+1;
    }
    k=c-1;
    printf("SIGNED CHARACTER COMPUTED MIN:%d,MAX:%d\n",c,k);
    
    
    for(s=0;s>-1;s++){
        s=s+1;
    }
    t=s-1;
    printf("SIGNED SHORT COMPUTED MIN:%d,MAX:%d\n",s,t);
    
    for(i=0;i>-1;i++){
        i=i+1;
    }
    k=i-1;
    printf("SIGNED INTEGER COMPUTED MIN:%d,MAX:%d\n",i,k);
    
    for(l=0;l>-1;l++){
        l=l+1;
    }
    g=l-1;
    printf("SIGNED LONG COMPUTED MIN:%ld,MAX:%ld\n",l,g);
    return 0;
}
