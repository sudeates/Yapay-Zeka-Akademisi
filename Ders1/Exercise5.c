//Write a statment that classifies a given character as uppercase letter, lowercase letter or special character
#include <stdio.h>

int main(){
    char ch;
    printf("Please enter a character:");
    scanf("%c",&ch);
    if(ch>='A' && ch<='Z'){
        printf("The character is an uppercase letter.");
    }
    else if(ch>='a' && ch<='z'){
        printf("The character is a lowercase letter.");
    }
    else{
        printf("The character is a special character.");
    }
}
