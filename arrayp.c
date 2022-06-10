#include <stdio.h>
void readArray(int n, int *p){
    printf("enter the values of array\n");
    for(int i=0;i<n;i++,p++){
        scanf("%d",p);
    }
  
}
void searchArray(int n, int *p){
    int x;
    printf("enter the number to find in array\n");
    scanf("%d",&x);
    int j=0;
    for(int i=0;i<n;i++,p++){
        if(x==*p){
            j=1;
           // printf("number found\n");
        }
    }
    if(j==0){
        printf("number not found");
    }else{
        printf("number found");
    }
    
}
int main(){
    int n=5;
    int data[n];
    readArray(n,data);
    searchArray(n,data);
}