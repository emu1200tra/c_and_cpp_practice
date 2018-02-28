#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double p[2048];

float americanput(float T , float S , float K , float r , float sigma , float q , float n){  
  float delta = T / n;
  double up = exp(sigma*sqrt(delta));
  p0 = (up * exp((-r)*delta) - exp((-q) * delta)) * up / (pow(up , 2) - 1);
  p1 = exp((-r) * delta) - p0;
  for(float i = 0 ; i <= n ; i++){
    p[i] = K - S * pow(up , (2*i - n));
    if (p[i] < 0) p[i] = 0;
  }
  for (float j = n-1 ; j >=0 ; j--) {
    for (float i = 0 ; i <= j ; i++) {
        p[i] = p0 * p[i] + p1 * p[i+1];
        float exercise = K - S * pow(up , (2*i - j));
        if (p[i] < exercise) p[i] = exercise;
      }
  }
  return p[0];
}


float europeanput(float T , float S , float K , float r , float sigma , float q , float n){  
  float delta = T / n;
  double up = exp(sigma*sqrt(delta));
  p0 = (up * exp((-r)*delta) - exp((-q) * delta)) * up / (pow(up , 2) - 1);
  p1 = exp((-r) * delta) - p0;
  for(float i = 0 ; i <= n ; i++){
    p[i] = K - S * pow(up , (2*i - n));
    if (p[i] < 0) p[i] = 0;
  }
  for (float j = n-1 ; j >=0 ; j--) {
    for (float i = 0 ; i <= j ; i++) {
        p[i] = p0 * p[i] + p1 * p[i+1];
      }
  }
  return p[0];
}


int main(){
  float S , X , t , s , r , n;
  scanf("%f%f%f%f%f%f" , &S , &X , &t , %s , %r , %n);
  float america = americanput(t , S , X , r , s , r , n);
  float european = europeanput(t , S , X , r , s , r , n);
  printf("american:%f ; european:%f\n", america , european);



  return 0;
}