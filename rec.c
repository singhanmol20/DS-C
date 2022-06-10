#include<stdio.h>

int sum(int n){
    if(n==1){
        return 1;
    }else{
        return n +sum(n-1);
    }
}
int main(){
    int k=5;
    printf("the sum is %d",sum(k));
}