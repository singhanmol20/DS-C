#include <stdio.h>
struct student{
    int roll_no;
    char name[20];
    float fees;
    char DOB[10];
}s[2];

int main(){
    struct student s1,s2;
    for(int i=0;i<2;i++){
        scanf("%d", &s->roll_no);
        scanf("%s",s->name);
        scanf("%f",&s->fees);
        scanf("%s",s->DOB);
    }
     for(int i=0;i<2;i++){
        printf("%d\n", s->roll_no);
        printf("%s\n",s->name);
        printf("%0.2f\n",s->fees);
        printf("%s",s->DOB);
    }
}