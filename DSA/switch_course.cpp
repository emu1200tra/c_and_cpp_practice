#include<iostream>
#include<cstdlib>
#include<vector>
#include<time.h>

using namespace std;

int main(){

    char sign = '0';
    vector<string>input_list;
    while(sign != 'n'){
        cout<<"input course name:"<<endl;
        string tmp;
        cin>>tmp;
        input_list.push_back(tmp);
        cout<<"still? (Y \ N)";
        cin>>sign;
    }
    srand(time(NULL));
    int i = rand() % input_list.size();

    cout<<input_list[i]<<endl;


}
