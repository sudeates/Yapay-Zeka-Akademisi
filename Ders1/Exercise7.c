//Write a program with functionthat reads in the side of a square and then prints a hallow square. 
//Your program should work for squares of all sizes between 1 and 20.

#include <stdio.h>

void printHollowSquare(int side){
    for(int i=0;i<side;i++){
        for(int j=0;j<side;j++){
            if(i==0 || i==side-1 || j==0 || j==side-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    int side;
    printf("Please enter the side length of the square (1-20): ");
    scanf("%d",&side);
    if(side<1 || side>20){
        printf("Invalid side length. Please enter a value between 1 and 20.");
    }
    else{
        printHollowSquare(side);
    }
}
