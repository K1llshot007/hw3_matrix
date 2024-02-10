#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>



int main() {

    const int n = 200000000;
    int i =0;
    int sum[200000000];
    srand(time(NULL));
    int input[200000000];
    size_t x;
    int j =0;
    for( j;j<n;j++){
        input[j] = rand();
    }
    sum[0] = input[0];
    x = input[0];
    double elt = omp_get_wtime();
   
    // #pragma omp parallel for reduction(+:area)
   while(i<200000000){
    i++;
    x+= input[i];
    sum[i] = x;

   }


    elt = omp_get_wtime() - elt;


    printf("Time taken: %.3lf seconds\n", elt);
    printf("Performance rate: %.3lf GFLOPS\n", (6.0 * n * 1e-9)/elt);

    return 0;
}
