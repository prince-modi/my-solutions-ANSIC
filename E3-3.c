//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 02/08/21.
//  Write a function expand(s1,s2) that expands shorthand notaions like a-z in the string s1 into the equivalent complete list
//  abc...xyz in s2. Allow for letters of either case and digits., and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
//  Arrange that a leading or trailing - is taken literally.
//
//

#include <stdio.h>
#include <string.h>
#define MAX 100

void expand(char notastr[], char expstr[]);

int main(){                                         //main function for test
    char s1[MAX]="a-c0-9a-b";                       //expected input in the form of a-z, 0-9, a-b-c, a-b0-9, a-b0-9a-b, -a-b, a-b-, -a-b-
    char s2[MAX]={0};
    expand(s1, s2);
    printf("Notation:%s\nExpanded String:%s\n",s1,s2);
    return 0;
}

void expand(char s1[], char  s2[]){
    int i,k,chk;
    int len=(int)strlen(s1);
    char firstch, secondch;
    i=k=chk=0;
    firstch=secondch=0;
    if(s1[i]=='-'){                                 //checking if the first character is '-'
        s2[k++]='-';                                //then set the first character of string s2 to '-' and increment k pointer
        i++;
    }
    if( s1[len-1]=='-'){                            //checking if the last character is '-'
        chk=1;                                      //if true set the chk flag to 1
    }
    for(;s1[i]!='\0';i++){                          //for loop to expand the string
        if(s1[i]=='-'){                             //if character is '-'
            if(s1[i+1]=='\0')                       //check if it is the last character
                break;                              //if true the break the loop, otherwise it will go into infinity loop
            secondch=s1[1+i++];                     //if '-' not the last character in the string, set the secondch to the character after that
        }
        else{                                       //first part of the loop that gets executed normally
            firstch=s1[i];                          //sets firstch to the first character of the notation to be expanded
            secondch=0;                             //sets secondch to '\0' to ensure that it runs if for cases like a-z0-9
        }
        for(int j=firstch;j<=secondch;j++,k++){     //expands the notation and copies that into string s2
            s2[k]=(char)j;
        }
    }
    if(chk)                                         //checks chk flag if true that means that the last character of the string is '-'
        s2[k]='-';                                  //appends '-' into the string s2
}
