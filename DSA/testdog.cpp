#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;


int main(){
	char c[4]={102,117,99,107};
	for(int i=0 ; i<4 ; i++) printf("%c ",c[i]);
	printf("\n");
	//------------------------------
	char *str1=new char[10];
	char *str2 =new char[10];
	scanf("%s",str1);

	printf("%s\n",str1);


	//-------------------------------
	scanf("%s",str2);
	cout<<"-----"<<endl;
	cout<<str2;
	cout<<"-----"<<endl;
	puts(str2);
	//-------------------------------
	printf("stringlen() of str1 : %d\n",strlen(str1));
}
