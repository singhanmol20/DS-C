#include <stdio.h>

int input(int a){
    printf("enter a number?");
    scanf("%d",&a);
    return a;
}
int compute(int *a, int *b){
    return *a + *b;
}
int output(int a){
    printf("%d",a);
}
int main(){
    int a,b;
    a= input(a);
    b= input(a);
    output(compute(&a,&b));
}