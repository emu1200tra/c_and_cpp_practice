#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <iostream>


using namespace std;

int main()
{
	srand(time(0));
	int x = rand()%21;
	//printf("\n");
	if (x==0)
		printf("大李水餃\n");
	else if (x==1)
		printf("吉野烤肉飯\n");
	else if (x==2)
		printf("轉角牛肉麵\n");
	else if (x==3)
		printf("師大第一腿\n");
	else if (x==4)
		printf("紫牛\n");
	else if (x==5)
		printf("一極拌\n");
	else if (x==6)
		printf("義麵麵\n");
	else if (x==7)
		printf("咖哩廚房\n");
	else if (x==8)
		printf("笑嘻嘻\n");
	else if (x==9)
		printf("客家粄條\n");
	else if (x==10)
		printf("泰大爺\n");
	else if (x==11)
		printf("坂本屋\n");
	else if (x==12)
		printf("滇味小廚\n");
	else if (x==13)
		printf("好米廚房\n");
	else if (x==14)
		printf("忠誠山東蔥油餅\n");
	else if (x==15)
		printf("泰風小館\n");
	else if (x==16)
		printf("韓食館\n");
	else if (x==17)
		printf("大柱子擔仔麵\n");
	else if (x==18)
		printf("健安雞肉飯\n");
	else if (x==19)
		printf("活大鬆軟麵包\n");
	else if (x==20)
		printf("宅男便當\n");


    cout<<x<<endl;
	return 0;

}
