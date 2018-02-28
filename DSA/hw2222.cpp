#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
//#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


struct matrix {
    long User;
    long Item;
    int result;
    long UT;
};


bool cmp(const matrix a,const matrix b){
    if(a.User != b.User) return a.User<b.User;
        if(a.Item != b.Item) return a.Item<b.Item;
            if(a.UT != b.UT) return a.UT<b.UT;
                if(a.result != b.result) return a.result<b.result;
}

bool cmp_items(const long a , long b){
    if(a != b) return a < b;
}




int main(){
    vector<matrix>data;
    clock_t start , end_l;
    start = clock();

    FILE *fp;
    /*remember to change the address of relogtrain!!!!!!*/
    fp = fopen("rec_log_train.txt" , "r");


    long a = 0 , b = 0 , d = 0;
    int c = 0;


    int counter = 0;
    while(fscanf(fp , "%ld%ld%d%ld" , &a , &b , &c , &d) != EOF){


        matrix tmp;
        tmp.User = a;
        tmp.Item = b;
        tmp.result = c;
        tmp.UT = d;
        data.push_back(tmp);
        counter++;
    }

    sort(data.begin() , data.end() , cmp);

    int times = 0;
    cin>>times;
    string cmd;
    for(int i = 0 ; i < times ; i++){
        cin>>cmd;
        if(cmd == "accept"){
            int u = 0 , i = 0 , t = 0;
            cin>>u;
            cin>>i;
            cin>>t;
            matrix find_goal;
            find_goal.User = u;
            find_goal.Item = i;
            find_goal.UT = t;
            find_goal.result = -2;
            int index = 0;
            index = lower_bound(data.begin(),data.end(),find_goal,cmp)-data.begin()-1;
            cout<<data[index].result<<endl;
        }
        else if(cmd == "items"){
            int u1 = 0 , u2 = 0;
            cin>>u1;
            cin>>u2;
            matrix find_goal;
            find_goal.User = u1;
            find_goal.Item = -1;
            find_goal.result = -2;
            find_goal.UT = 0;
            int index1 = 0 , index2 = 0;
            index1 = lower_bound(data.begin() , data.end() , find_goal , cmp)-data.begin()-1;
            vector<long> fin_result;
            while(data[index1].User == data[index1+1].User){
                matrix tmp;
                tmp.User = u2;
                tmp.Item = data[index1].Item;
                tmp.result = -2;
                tmp.UT = 0;
                index2 = lower_bound(data.begin() , data.end() , tmp , cmp)-data.begin()-1;
                if(index2 != false){
                    fin_result.push_back(data[index2].Item);
                }
                index1++;
            }
            matrix tmp;
            tmp.User = u2;
            tmp.Item = data[index1].Item;
            tmp.result = -2;
            tmp.UT = 0;
            index2 = lower_bound(data.begin() , data.end() , tmp , cmp)-data.begin()-1;
            if(index2 != false){
                fin_result.push_back(data[index2].Item);
            }

            for(int i = 0 ; i < fin_result.size() ; i++){
                if(fin_result[i] == fin_result[i+1]){
                    fin_result[i] = -1;

                }
                else{
                    cout<<fin_result[i]<<endl;
                }
            }

        }
    }



    fclose(fp);
    end_l = clock();
    double diff = end_l - start;
    printf(" %f  ms" , diff);
    return 0;
}

