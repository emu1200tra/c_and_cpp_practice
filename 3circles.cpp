#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void bubble(long long A[] , int i){
	for(int a = 0 ; a < i ; a++)
	{
		for(int b = 0 ; b < i ; b++)
		{
			int trans;
			if(A[b] < A[b + 1] && (b + 1) < i){
				trans = A[b];
				A[b] = A[b + 1];
				A[b + 1] = trans;
			}
		}
	}
}

void copy(int A[] , int B[] , int i){
	//A複製目標  B需複製陣列
	for(int a = 0 ; a < i ; a++){
		A[a] = B[a];
	}
}

int findmin(int array[] , int i){
	int min = array[0];
	for(int a = 0 ; a < i ; a++){
		if(min > array[a]){
			min = array[a];
		}
	}
	return min;
}




int main()
{
	long long casenum , c1[2] , c2[2] , c3[2] , r1 , r2 , r3 , counter = 0;
	scanf("%lld" , &casenum);
	for(int i = 0 ; i < casenum ; i++){
		scanf("%lld%lld%lld" , &c1[0] , &c1[1] , &r1);
		scanf("%lld%lld%lld" , &c2[0] , &c2[1] , &r2);
		scanf("%lld%lld%lld" , &c3[0] , &c3[1] , &r3);
		for(int numx = c1[0] - r1 ; numx <= c1[0] + r1 ; numx++){
			for(int numy = c1[1] - r1 ; numy <= c1[1] + r1 ; numy++){
				if(((numx - c1[0]) * (numx - c1[0]) + (numy - c1[1]) * (numy - c1[1]) <= r1 * r1) && ((numx - c2[0]) * (numx - c2[0]) + (numy - c2[1]) * (numy - c2[1]) > r2 * r2) && ((numx - c3[0]) * (numx - c3[0]) + (numy - c3[1]) * (numy - c3[1]) > r3 * r3)){
					counter++;
					
				}
			}
		}
		for(int numx = c2[0] - r2 ; numx <= c2[0] + r2 ; numx++){
			for(int numy = c2[1] - r2 ; numy <= c2[1] + r2 ; numy++){
				if(((numx - c1[0]) * (numx - c1[0]) + (numy - c1[1]) * (numy - c1[1]) > r1 * r1) && ((numx - c2[0]) * (numx - c2[0]) + (numy - c2[1]) * (numy - c2[1]) <= r2 * r2) && ((numx - c3[0]) * (numx - c3[0]) + (numy - c3[1]) * (numy - c3[1]) > r3 * r3)){
					counter++;
				}
			}
		}
		for(int numx = c3[0] - r3 ; numx <= c3[0] + r3 ; numx++){
			for(int numy = c3[1] - r3 ; numy <= c3[1] + r3 ; numy++){
				if(((numx - c1[0]) * (numx - c1[0]) + (numy - c1[1]) * (numy - c1[1]) > r1 * r1) && ((numx - c2[0]) * (numx - c2[0]) + (numy - c2[1]) * (numy - c2[1]) > r2 * r2) && ((numx - c3[0]) * (numx - c3[0]) + (numy - c3[1]) * (numy - c3[1]) <= r3 * r3)){
					counter++;

				}
			}
		}
		for(int numx = c3[0] - r3 ; numx <= c3[0] + r3 ; numx++){
			for(int numy = c3[1] - r3 ; numy <= c3[1] + r3 ; numy++){
				if(((numx - c1[0]) * (numx - c1[0]) + (numy - c1[1]) * (numy - c1[1]) <= r1 * r1) && ((numx - c2[0]) * (numx - c2[0]) + (numy - c2[1]) * (numy - c2[1]) <= r2 * r2) && ((numx - c3[0]) * (numx - c3[0]) + (numy - c3[1]) * (numy - c3[1]) <= r3 * r3)){
					counter++;

				}
			}
		}
		printf("%lld\n", counter);
		counter = 0;
	}



				
				
    return 0;
}
