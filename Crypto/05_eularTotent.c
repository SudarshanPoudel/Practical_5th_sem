#include<stdio.h>   

int findGcd(int a, int b){
    if(b == 0) return a;
    else return findGcd(b, a%b);
}


int main(){
    int n, gcd, i, noOfCoprimes = 0;
    printf("Enter Any Number : ");
    scanf("%d",&n);
    for(i = 1; i < n; i++)
        if(findGcd(n, i) == 1) noOfCoprimes++;
    
    printf("No of Coprimes = %d\n\n", noOfCoprimes);
    return 0;
}