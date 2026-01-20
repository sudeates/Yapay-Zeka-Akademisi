//Write a c program reads the coodrinates of two points and calculates the distance between them
#include <stdio.h>
#include <math.h>

int main(){
    int x1,y1,x2,y2;
    float distance;
    printf("Please enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d",&x1,&y1);
    printf("Please enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d",&x2,&y2);
    distance=sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("The distance between the two points is: %.2f",distance);
    return 0;
}