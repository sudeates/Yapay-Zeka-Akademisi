//If the values of variables a,b,c are all same print "all same" on the screen and find their sum

#include <stdio.h>

int main(){
    int a,b,c,sum;
    printf("Please enter three numbers: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a==b && b==c){
        sum=a+b+c;
        printf("All same\n");
        printf("The sum is: %d",sum);
    }
    return 0;
}