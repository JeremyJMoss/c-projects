#include <stdio.h>

int greatestCommonDivisor(int a, int b){
    if (a < 0 || b < 0){
        printf("Please do not include negative numbers\n");
        return -1;
    }
    
    int temp;

    while (b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

float absoluteValue(float num){
    if (num >= 0){
        return num;
    }
    return -num;
}

float squareRoot(float num){
    if (num < 0){
        printf("Negative argument to squareRoot\n");
        return -1;
    }
    
    float absNum = absoluteValue(num);

    int start = 0, end = absNum, mid;

    float ans;

    while (start <= end) {
        mid = (start + end) / 2;

        if (mid * mid == absNum) {
            ans = mid;
            break;
        }

        if (mid * mid < absNum) {
            ans = start;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    float increment = 0.1;

    for (int i=0; i < 5; ++i) {
        while (ans * ans <= absNum)
            ans += increment;
        

        ans -= increment;
        increment /= 10;
    }
    return ans;
}

int main(void){
    int gcd = greatestCommonDivisor(12003434, 1000000000);
    printf("%d\n", gcd);
    int n = 225;
    printf("%f\n", squareRoot(n));
    return 0;
}