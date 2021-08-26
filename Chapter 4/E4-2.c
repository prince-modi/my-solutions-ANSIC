//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 04/08/21.
//  Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an
//  optionally signed exponent.
//

#include <stdio.h>
#include <ctype.h>

double stof(char str[]); //takes a string and converts that to a floating point value

int main(void){
    char str[]="123.45e-2";
    double num,stof(char s[]);
    num=stof(str);
    printf("%f\n",num);
    return 0;
}

double stof(char s[]){
    int sign,i;
    double var,power,npow;
    npow=1.0;
    for(i=0;isspace(s[i]);i++)
        ;
    sign=s[i]>0?1:-1;
    if(s[i]=='+' || s[i]=='-')
        i++;
    for(var=0;isdigit(s[i]);i++){
        var=var*10.0+(s[i]-'0');
    }
    if(s[i]=='.')
        i++;
    for(power=1.0;isdigit(s[i]);i++){
        var=var*10.0+(s[i]-'0');
        power*=10.0;
    }
    if(s[i]=='E' || s[i]=='e'){
        i++;
    }
    if(s[i]=='-'){
        for(int j=s[++i]-'0';j>0;j--){
            power*=10.0;
        }
    }
    else if ((isdigit(s[i]))){
        for(int j=s[i]-'0';j>0;j--){
            npow*=10.0;
        }
    }
    return sign*var*npow/power;
}
