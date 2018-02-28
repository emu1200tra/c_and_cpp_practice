#include <stdio.h>
#include <stdlib.h>


// int main(){
// 	int k = 2;
// 	int n[10] = {"1", "3", 
// 	"-1", "-3", 
// 	"1", "3", 
// 	"-1", "-3",
// 	"1", "-3",
// 	}

// 	int num = 0;
// 	bool isPositive = true;
// 	int max = 0; 
// 	int j = 0;
// 	while (n[num] != 0) {

// 		for ( j = num; j < num + k; j++) {
// 			if ( n[j] < 0 ) {
// 				break;
// 			}
// 			max++;
// 		}
// 		num++;
// 	}

// 	return 0;
// }

// int stack[1000] , pt = 0 ;

// void push(int num) {
// 	stack[pt] = num;
// 	pt++;
// }

// int pop() {
// 	int popreturn = stack[pt-1];
// 	pt--;
// 	return popreturn;
// }
int queue[1000] , push = 0, pop = 0;
void enqueue(int num){
    queue[push] = num;
    push++;
    if(push == 1000){
    	push = 0;
    }
}
int dequeue(){
	int num = queue[pop];
	pop++;
	if(pop == 1000){
		pop = 0;
	}
	return num;
}



