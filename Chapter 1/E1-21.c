//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 18/06/21.
//  Write a program entab that replaces strings of blanks by the minimum number of tabs and
//  blanks to achieve the same spacing. Use the same tab stops as for detab. When either a
//  tab or a single blank would suffice to reach a tab stop, which should be given
//  preference?
//

#include <stdio.h>
#define TABS 4

int main() {
    int c, n, t;
    n=t=0;
    while((c=getchar())!=EOF){
        //t=t%TABS;
        //++t;
        if(c==' '){
            ++t;
            ++n;
            while((c = getchar())==' '){
                ++t;
                ++n;
                t=t%TABS;
            }
            t=t%TABS;
            if(n>=TABS){
                putchar('\t');
                n=n-TABS;
            }
            if(t!=4){
                n=t;
                //printf("%d",n);
            }
            if(n<TABS){
                for(int i=0;i<n;i++){
                    //printf("%d",n);
                    putchar(' ');
                }
            }
            n=0;
        }
        ++t;
        //printf("%d",t);
        t=t%TABS;
        //if(t==4)
            //printf("%d",t);
        putchar(c);
        if(c=='\n'){
            t=0;
        }
    }
}
