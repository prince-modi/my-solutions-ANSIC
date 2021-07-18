//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 17/07/21.
//  Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
//

#include <stdio.h>

int ftoc(int f);

int main(){
    int lower,upper,step;
    lower=0;
    upper=300;
    step=20;
    for(int f=lower;f<=upper;f=f+step){
        printf("%3d%6d\n",f,ftoc(f));
    }
    return 0;
}
int ftoc(int far){
    int c;
    c=5*(far-32)/9;
    return c;
}
