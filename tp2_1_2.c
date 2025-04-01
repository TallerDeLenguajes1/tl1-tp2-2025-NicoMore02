#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main() {
    int i;
    double vt[N];
    double *punterovt = vt;

    srand(time(NULL));

    for ( i = 0; i < N; i++)
    {
        *(punterovt + i) = 1 + rand() % 100;
        printf("%f\n  ", punterovt[i]);
    }
    
    
    return 0;
}