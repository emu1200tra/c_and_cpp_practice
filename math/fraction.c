#include "fraction.h"

Frac normal(long long a, long long b) {
    Frac x;
    int i ;
    for(i = a ; i > 1 ; i--){
        if(a % i == 0 && b % i == 0){
            a = a / i;
            b = b / i;
            break;
        }
    }
    x.a = a;
    x.b = b;
    return x;
}

Frac add(Frac x, Frac y) {
    //x.b y.b
    long long denominator = 0 , numerator = 0;
    denominator = x.b * y.b;
    x.a = x.a * y.b;
    y.a = y.a * x.b;
    numerator = x.a + y.a;
    return normal(numerator , denominator);
}
Frac subtract(Frac x, Frac y) {
    long long denominator = 0 , numerator = 0;
    denominator = x.b * y.b;
    x.a = x.a * y.b;
    y.a = y.a * x.b;
    numerator = x.a - y.a;
    return normal(numerator , denominator);
}
Frac multipy(Frac x, Frac y) {
    long long denominator = 0 , numerator = 0;
    denominator = x.b * y.b;
    numerator = x.a * y.a;
    return normal(numerator , denominator);
}
Frac divide(Frac x, Frac y) {
    long long denominator = 0 , numerator = 0;
    denominator = x.b * y.a;
    numerator = x.a * y.b;
    return normal(numerator , denominator);
}
