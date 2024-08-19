#include<stdio.h>

int findGcd(int a, int b){
    if(b == 0) return a;
    else return findGcd(b, a%b);
}

int main(){
    int a, b, gcd;
    printf("Enter 2 numbers : ");
    scanf("%d %d",&a, &b);
    gcd = findGcd(a, b);
    printf("GCD of %d and %d : %d\n\n", a, b, gcd);
    return 0;
}