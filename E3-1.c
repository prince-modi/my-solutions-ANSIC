//
//  main.c
//  c project
//
//  Created by Prince Bhagirath Modi on 26/07/21.
//  Our binary search makes two tests inside the loop, when one would suffice (at the price of mores tests outside). Write a
//  version with only one test inside the loops ad measure the difference in run-time.
//

#include <stdio.h>

int binsearch(int x, int v[], int n){
    int low, high, mid, temp;
    
    low=mid=0;
    high= n-1;
    while(low<=high){
        temp=v[mid];
        if (x<v[mid])
            high=mid-1;
        else{
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    if(x==v[mid]){
        return mid;
    }
    else{
        return -1;
    }
}

int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    for(int i=0;i<10;++i){
        printf("%d:%d\n",i,binsearch(i, arr, 10));
    }
    return 0;
}
