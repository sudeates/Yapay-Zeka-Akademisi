//Write me program about pointers in c language. 
//The program should demonstrate how to use pointers to swap two integer values.
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}  

int main(){
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    
    swap(&num1, &num2);
    
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    
    return 0;
}