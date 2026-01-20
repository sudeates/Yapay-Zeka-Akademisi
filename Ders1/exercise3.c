//write c a program that read a four digit number and finds the sum of its digits
#include <stdio.h>

int main(){
    int number,digit1,digit2,digit3,digit4,sum;
    printf("Please enter a four digit number: ");
    scanf("%d",&number);
    digit1=number%10;
    digit2=(number/10)%10;
    digit3=(number/100)%10;
    digit4=(number/1000)%10;
    sum=digit1+digit2+digit3+digit4;
    printf("The sum of the digits is: %d",sum);
    return 0;
}