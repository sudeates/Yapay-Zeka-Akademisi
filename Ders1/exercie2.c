#include <stdio.h>
//Write a C Program to read three numbers and print tehir averages
int main(){
    int a,b,c;
    float average;
    printf("Please enter the numbers");
    scanf("%d %d %d",&a,&b,&c);
    average=(a+b+c)/3.0;
    printf("The average is: %f",average);
    return 0;
}