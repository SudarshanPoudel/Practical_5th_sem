// Practical 1
// Program to calculate Server utilization, Average no of customer and Average waiting time in the system and the queue based on arrival and service rate.

#include<stdio.h>

int main(){
    float arrivalRate, serviceRate;
    float utilization, ls, lq, ws, wq;

    printf("Enter arrival rate : ");
    scanf("%f", &arrivalRate);
    printf("Enter service rate : ");
    scanf("%f", &serviceRate);

    utilization = arrivalRate / serviceRate;
    ls = arrivalRate / (serviceRate - arrivalRate);
    lq = ls - utilization;
    ws = ls / arrivalRate;
    wq = lq / arrivalRate;

    printf("Server utilization : %.3f\n", utilization);
    printf("Avg. no. of customer in system : %.3f\n", ls);
    printf("Avg. no. of customer in queue : %.3f\n", lq);
    printf("Avg. waiting time in system : %.3f\n", ws);
    printf("Avg. waiting time in queue : %.3f\n\n", wq);

    return 0;
}