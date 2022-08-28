#include <iostream>
#include <climits>
/*
 * CONSTRAINT: ASSUME THAT ONLY 32-BIT INTEGERS ARE BEING TESTED
 */
int reverse2(int x) {

    // check if x is outside the boundary of signed integer range    
    if(INT_MIN < x && x > INT_MAX) {
        return 0;
    }
    
    // check if x is negative integer
    int sign = 1;
    if (x < 0) {
        sign = -1;
    }
    
    int num = abs(x), res = 0;
    while (num > 0) {
        if (res > INT_MAX/10) {
            return 0;
        }
        res = (res * 10) + (num % 10);
        num = int(num/10);
    }
    
    // don't forget to multipy the result with sign
    return res * sign;
}
int main() {
    std::cout<<reverse2(-123);
}
