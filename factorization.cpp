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
	long long a , b , c , x , f , xarray[3] , arraycounter = 0 , counter = 0 ;
	scanf("%lld%lld%lld" , &a , &b , &c);
	
	if(c > 0){
		for(int i = c ; i >= -c ; i--){
			x = i;
			f = x * x * x + a * x * x + b * x + c;
			if(f == 0){
				xarray[arraycounter] = x;
				arraycounter++;
				counter++;
			
			}

		}
	}
	else if(c < 0){
		for(int i = c ; i <= -c ; i++){
			x = i;
			f = x * x * x + a * x * x + b * x + c;
			if(f == 0){
				xarray[arraycounter] = x;
				arraycounter++;
				counter++;
			
			}

		}
	}
	else if(c == 0){
		xarray[0] = 0;
		arraycounter = 1;
		counter = 1;
		if(b > 0){
			for(int i = b ; i >= -b ; i--){
				x = i;
				f = x * x + a * x + b;
				if(f == 0){
					xarray[arraycounter] = x;
					arraycounter++;
					counter++;
			
				}

			}
		}
		else if(b < 0){
			for(int i = b ; i <= -b ; i++){
				x = i;
				f = x * x + a * x + b;
				if(f == 0){
					xarray[arraycounter] = x;
					arraycounter++;
					counter++;
			
				}

			}
		}
		else{
			xarray[1] = 0;
			xarray[2] = -a;
			counter = 3;
		}
	}
	if(counter == 1){
		xarray[1] = xarray[0];
		xarray[2] = xarray[0];
	}
	else if(counter == 2){
		if(c != 0){
			if(xarray[0] * xarray[0] * xarray[1] == -c){
				xarray[2] = xarray[0];
			}
			else if(xarray[0] * xarray[1] * xarray[1] == -c){
				xarray[2] = xarray[1];
			}
		}
		else if(c == 0 && b == 0){
			xarray[2] = xarray[0];
		}
		else if(c == 0 && b != 0){
			xarray[2] = xarray[1];
		}
	}
	bubble(xarray , 3);
	printf("%lld %lld %lld\n", -xarray[0] , -xarray[1] , -xarray[2]);




    return 0;
}
