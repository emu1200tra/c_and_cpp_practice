#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double p[2048];

float americanput(float T , float S , float K , float r , float sigma , float q , float n){
  float delta = T / n;
  double up = exp(sigma*sqrt(delta));
  double p0 = (up * exp((-q)*delta) - exp((-r) * delta))/(pow(up , 2) - 1);
  double p1 = exp((-r) * delta) - p0;
  for(int i = 0 ; i <= n ; i++){
    p[i] = K - S * pow(up , (2*i - n));
    if (p[i] < 0) p[i] = 0;
  }
  for (int j = n-1 ; j >=0 ; j--) {
    for (int i = 0 ; i <= j ; i++) {
        p[i] = p0 * p[i+1] + p1 * p[i];
        float exercise = K - S * pow(up , (2*i - j));
        if (p[i] < exercise) p[i] = exercise;
      }
  }
  return p[0];
}

float europeanput(float T , float S , float K , float r , float sigma , float q , float n){
  float delta = T / n;
  double up = exp(sigma*sqrt(delta));
  double p0 = (up * exp((-q)*delta) - exp((-r) * delta)) / (pow(up , 2) - 1);
  double p1 = exp((-r) * delta) - p0;
  for(int i = 0 ; i <= n ; i++){
    p[i] = K - S * pow(up , (2*i - n));
    if (p[i] < 0) p[i] = 0;
  }
  for (int j = n-1 ; j >=0 ; j--) {
    for (int i = 0 ; i <= j ; i++) {
        p[i] = p0 * p[i+1] + p1 * p[i];
      }
  }
  return p[0];
}



int main(){
  float S = 0.00, X = 0.00 , t = 0.00 , s = 0.00 , r = 0.00 , n = 0.00;
  scanf("%f%f%f%f%f%f" , &S , &X , &t , &s , &r , &n);
  s = s/100;
  r = r/100;
  float q = (1/2) + ((1/2)*(r/s)*sqrt(t/n));
  float america = americanput(t , S , X , r , s , q , n);
  float european = europeanput(t , S , X , r , s , q , n);
  printf("american:%f ; european:%f\n", america , european);




  return 0;
}
