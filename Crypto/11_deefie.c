#include<stdio.h>

long long int power(int a, int b, int m){
    long long int t;
    if(b == 1) return a;
    t = power(a, b/2, m);
    if((b % 2) == 0) return (t * t)%m;
    else return (((t*t)%m)*a)%m;
}

int main(){
    int n, g, x, a, y, b;
    printf("Enter value of n and g : ");
    scanf("%d %d", &n, &g);
    printf("Enter value of x for person A : ");
    scanf("%d", &x);
    a = power(g, x, n);
    printf("Enter value of x for person B : ");
    scanf("%d", &y);
    b = power(g, y, n);

    printf("Key for person A is %lld\n", power(b, x, n));
    printf("Key for person B is %lld\n\n\n", power(a, y, n));

    return 0;
}