#include <stdio.h>
void readArray(int n, int *p){
    printf("enter the values of array");
    for(int i=0;i<n;i++,p++){
        scanf("%d",p);
    }
  
}
void print_array(int *p, int n){
    printf("the values are");
    for(int i=0;i<n;i++){
        printf("%d \n", *(p+i));
    }
}

int main(){
    int n=5;
    int chem[n];
    readArray(n,chem);
    print_array(chem,n);
}