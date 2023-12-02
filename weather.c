#include <stdio.h>
#define MONTHS 12
#define YEARS 5 

int main(void){
    float rainfall[YEARS][MONTHS] = {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    float rainfallSums[YEARS];

    printf("YEAR\tRAINFALL (inches)\n");

    float yearlyAverage = 0.0;

    for (int year = 0; year < YEARS; ++year){
        printf("201%d\t", year);
        float sum = 0.0;
        for (int month = 0; month < MONTHS; ++month){
            sum += rainfall[year][month];
        }
        printf("%.1f\n", sum);
        yearlyAverage += sum / YEARS;
    }

    printf("\nThe yearly average is %.1f inches\n", yearlyAverage);
    
    printf("\nMONTHLY AVERAGES:\n\n");

    printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");

    for (int month = 0; month < MONTHS; ++month){
        float avg = 0;
        for (int year = 0; year < YEARS; ++year){
            avg += rainfall[year][month] / YEARS;
        }
        printf("%.1f\t", avg);
    }
    printf("\n");
    return 0;
}