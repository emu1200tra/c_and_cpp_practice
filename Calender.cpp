#include <stdio.h>
#include <stdlib.h>

int main(){
	int year , month , day;
	scanf("%d%d%d" , &year , &month , &day);
	if(month > 12 || month < 1 || day > 6 || day < 0){
		printf("invalid\n");
		return 0;
	}
	printf(" Su Mo Tu We Th Fr Sa\n");
	printf("=====================\n");
	int leap;
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		leap = 1;
	}
	else{
		leap = 0;
	}
	
			
				for(int i = 0 ; i < day ; i++){
				printf("   ");
				}
				if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
					for(int i = 1 ; i <= 31 ; i++){
						printf("%3d", i);
						day++;
						if(day == 7){
							printf("\n");
							day = 0;
						}

					}
				}
				else if(month == 4 || month == 6 || month == 9 || month == 11){
					for(int i = 1 ; i <= 30 ; i++){
						printf("%3d", i);
						day++;
						if(day == 7){
							printf("\n");
							day = 0;
						}

					}
				}
				else if(leap == 1 && month == 2){
					for(int i = 1 ; i <= 29 ; i++){
						printf("%3d", i);
						day++;
						if(day == 7){
							printf("\n");
							day = 0;
						}

					}
				}
				else if(leap == 0 && month == 2){
					for(int i = 1 ; i <= 28 ; i++){
						printf("%3d", i);
						day++;
						if(day == 7){
							printf("\n");
							day = 0;
						}

					}
				}
				if(day != 0){
					printf("\n");
				}

				printf("=====================\n");
			



	return 0;
}