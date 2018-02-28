#include <iostream>
#include<stdlib.h>


using namespace std;

int main()
{
    int length = 0;
    cin>>length;
    int *arr = (int*)malloc(length * sizeof(int));

    cout<<"輸入陣列"<<endl;
    cout<<"輸入長度"<<endl;
    int num = 0;
    cin>>num;

    for(int i = 0 ; i < num ; i++){
        cin>>*(arr+i);
    }

    for(int i = 0 ; i < num ; i++){
        cout<<*(arr+i)<<endl;
    }

    return 0;
}
