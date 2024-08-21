#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void midSqureMethod(int seed, int digits, int no_of_iterations){
    int current = seed;
    int mid_start, squred_value;
    int digit_squred = digits * 2;


    for(int i = 0; i < no_of_iterations; i++){
        squred_value = current * current;

        char squred_str[20];
        sprintf(squred_str, "%0*d", digit_squred, squred_value);

        mid_start = (strlen(squred_str) - digits)/2;

        char mid_str[digits + 1];
        for(int j = 0; j < digits; j++){
            mid_str[j] = squred_str[mid_start + j];
        }

        mid_str[digits] = '\0';

        current = atoi(mid_str);

        printf("Random Number is %d : %0*d\n", i+1, digits, current);
        
    }
}

int noOfdigits(int num){
    int d = 1;
    while(num / 10 != 0){
        d++;
        num/=10;
    }
    return d;
}


int main(){
    int seed, digit, iter;
    printf("Enter seed  and no of iterations : ");
    scanf("%d %d", &seed, &iter);
    digit = noOfdigits(seed);
    midSqureMethod(seed, digit, iter);
    printf("\n\n\n");
}