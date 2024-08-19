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
    if(gcd == 1) printf("%d and %d are co-prime\n\n", a, b);
    else printf("%d and %d are not co-prime\n", a, b);
    return 0;
}