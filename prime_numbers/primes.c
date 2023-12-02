#include <stdio.h>
#include <stdbool.h>

int main(){
    int primes[30];
    primes[0] = 2;
    primes[1] = 3;
    int currentIndex = 2;
    for (int i = 5; i <= 100; i = i+2){
        bool isPrime = true;
        for (int j = 1; isPrime && i / primes[j] >= primes[j]; ++j){
            if (i % primes[j] == 0){
                isPrime = false;
            }
        }

        if (isPrime){
            primes[currentIndex++] = i;
        }

    }
    for (int i = 0; i < currentIndex; ++i){
        printf("%d", primes[i]);
        if (i < currentIndex - 1){
            printf(", ");
        }
    }
    printf("\n");
}





