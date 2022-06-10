#include<stdio.h>
void read(char *p,int size){

int count1=0,count2=0;
for(;*p!='\0';(p++)){


if(*p==' ')
{
    count1++;
}else
{
count2++;
}
}
count1++;
printf("word= %d, number of character = %d",count1,count2);
}



int main(){
char input[50];
gets(input);
read(input,50);
}