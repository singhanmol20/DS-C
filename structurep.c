// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

struct cov19{
    char name[20];
    int age;
    char bloodGp[4];
    char symptoms[50];
    char address[20];
}c[10];
 
int main() {
    int n;
    printf("enter the number of patients\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the detail of patient\n");
        printf("Enter your name:\n");
        scanf("%s",c[i].name);
        printf("Enter your age:\n");
        scanf("%d", &c[i].age);
        printf("Enter your blood group:\n");
        scanf("%s",c[i].bloodGp); 
        printf("Enter your address:\n");
        scanf("%s",c[i].address);
        printf("Enter your symptoms:\n");
        scanf("%s",c[i].symptoms);
       
    }
      for(int i=0;i<n;i++){
        printf("the detail of patients are\n");
       printf("%s\n",c[i].name);
        printf("%d\n", c[i].age);
       printf("%s\n", c[i].bloodGp);
        printf("%s\n", c[i].symptoms);
        printf("%s\n",c[i].address);
    }
    return 0;
}