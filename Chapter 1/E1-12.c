//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 17/07/21.
//  Write a program that prints its input one word per line.
//

#include <stdio.h>

int main() {
    int c;
    while((c=getchar())!= EOF){
        if(c!=' '){
            putchar(c);
        }
        else{
            putchar('\n');
        }
    }
}
