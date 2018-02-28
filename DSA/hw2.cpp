#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


struct matrix {
    long User;
    long Item;
    int result;
    long UT;
};
struct user_itema{
    long user;
    long item;
};

bool cmp(const matrix a,const matrix b){
    if(a.User != b.User) return a.User<b.User;
        if(a.Item != b.Item) return a.Item<b.Item;
            if(a.UT != b.UT) return a.UT<b.UT;
                if(a.result != b.result) return a.result<b.result;
}


bool cmp_no_UT(const matrix a,const matrix b){
    if(a.User != b.User) return a.User<b.User;
        if(a.Item != b.Item) return a.Item<b.Item;
            if(a.result != b.result) return a.result<b.result;
}



bool cmp_item_and_UT(const matrix a , const matrix b){
    if(a.Item != b.Item) return a.Item<b.Item;
        if(a.UT != b.UT) return a.UT<b.UT;
            if(a.User != b.User) return a.User<b.User;
                if(a.result != b.result) return a.result<b.result;
}

bool cmp_user_item(const user_itema a , const user_itema b){
    if(a.user != b.user) return a.user<b.user;
        if(a.item != b.item) return a.item<b.item;
}

bool cmp_item_user(const matrix a , const matrix b){
    if(a.Item != b.Item) return a.Item<b.Item;
        if(a.User != b.User) return a.User<b.User;
            if(a.UT != b.UT) return a.UT<b.UT;
                if(a.result != b.result) return a.result<b.result;
}

bool check (matrix a, matrix b) {
  bool sign = false;
  if(a.User == b.User)
    if(a.Item == b.Item)
        if(a.result == b.result)
            if(a.UT == b.UT)
                sign = true;

  return sign;
}

bool check_UT (const long a , const long b){
    return (a==b);
}

int main(){
    vector<matrix>data;


    FILE *fp;

    fp = fopen("/tmp2/KDDCUP2012/track1/rec_log_train.txt" , "r");


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


    vector<matrix>::iterator erasedata;
    erasedata = unique(data.begin() , data.end() , check);
    data.resize(distance(data.begin() , erasedata));


    int times = 0;
    cin>>times;
    string cmd;
    int index;
    long size_data = data.size() ;
    vector<matrix>::iterator data_start = data.begin();
    vector<matrix>::iterator data_end = data.end();
    for(int ct = 0 ; ct < times ; ct++){
        cin>>cmd;
        vector<long> fin_result;
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
            index = 0;
            index = lower_bound(data.begin(),data.end(),find_goal,cmp)-data.begin();
            if(data[index].User == u && data[index].Item == i && data[index].UT == t){
                cout<<data[index].result<<endl;
            }
            else{
                cout<<"0"<<endl;
            }

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
            index1 = lower_bound(data.begin() , data.end() , find_goal , cmp)-data.begin();

            int sign = 0;
            long cp = data[index1].User;
            if(data[index1].User = u1)
            while(data[index1].User == cp){
                matrix tmp;
                tmp.User = u2;
                tmp.Item = data[index1].Item;
                tmp.result = -2;
                tmp.UT = 0;
                index2 = lower_bound(data.begin() , data.end() , tmp , cmp)-data.begin();
                if(data[index1].Item == data[index2].Item){
                    fin_result.push_back(data[index2].Item);
                    sign = 1;
                }

                index1++;
            }

            if(sign == 0){
                fin_result.push_back(0);
            }

            vector<long>::iterator erase_com;
            erase_com = unique(fin_result.begin() , fin_result.end());
            fin_result.resize(distance(fin_result.begin() , erase_com));

            for(int j = 0 ; j < fin_result.size() ; j++){


                if(fin_result[j] == 0){
                    cout<<"EMPTY"<<endl;
                }
                else{
                    cout<<fin_result[j]<<endl;
                }


            }
            if(fin_result.size() == 0){
                cout<<"EMPTY"<<endl;
            }
            fin_result.clear();

        }
        else if(cmd == "users"){

            long i1 = 0 , i2 = 0 , t1 = 0 , t2 = 0;
            cin>>i1;
            cin>>i2;
            cin>>t1;
            cin>>t2;
            matrix tmp1;
            tmp1.User = data[0].User;
            tmp1.Item = i1;
            tmp1.result = -2;
            tmp1.UT = t1;
            matrix tmp2;
            tmp2.User = data[0].User;
            tmp2.Item = i2;
            tmp2.result = -2;
            tmp2.UT = t1;


            int sign = 0;
            long cpy_user = data[0].User;
            vector<matrix>::iterator jump_start_1 = lower_bound(data_start , data_end , tmp1 , cmp);
            vector<matrix>::iterator jump_start_2 = lower_bound(data_start , data_end , tmp2 , cmp);

            vector<long> save;



            for(int i = 0 ; i < size_data ; i++){
                if(sign == 0){
                    if(i != 0){
                        jump_start_1 = lower_bound(jump_start_1 , data_end , tmp1 , cmp);
                        jump_start_2 = lower_bound(jump_start_2 , data_end , tmp2 , cmp);

                    }
                    if(data[jump_start_1 - data_start].User == cpy_user &&
                       data[jump_start_2 - data_start].User == cpy_user &&
                       data[jump_start_1 - data_start].Item == i1 &&
                       data[jump_start_2 - data_start].Item == i2 &&
                       data[jump_start_1 - data_start].UT >= t1 &&
                       data[jump_start_1 - data_start].UT <= t2 &&
                       data[jump_start_2 - data_start].UT >= t1 &&
                       data[jump_start_2 - data_start].UT <= t2){
                        save.push_back(cpy_user);
                    }
                            sign = 1;
                }

                if(data[i].User != cpy_user){
                    cpy_user = data[i].User;
                    tmp1.User = cpy_user;
                    tmp2.User = cpy_user;
                    sign = 0;
                    i--;

                }


            }
            if(save.size() != 0){
                long save_size = save.size();
                for(int i = 0 ; i < save_size ; i++){
                    cout<<save[i]<<endl;
                }
                save.clear();
                save.shrink_to_fit();

            }
            else{
                cout<<"EMPTY"<<endl;
            }



        }
        else if(cmd == "ratio"){
            long item = 0 , threshold = 0;
            cin>>item;
            cin>>threshold;
            long counting_user = 0;
            long counting_item = 0;
            long counting = 0;
            long cp_user = data[0].User;
            int sign = 0;
            int sign_of_user = 0;
            matrix tmp1;
            tmp1.User = cp_user;
            tmp1.Item = 0;
            tmp1.result = -2;
            tmp1.UT = 0;

            matrix tmp2;
            tmp2.User = cp_user;
            tmp2.Item = 2147483647;
            tmp2.result = 2;
            tmp2.UT = 2147483647;
            vector<matrix>::iterator jump_start_1 = lower_bound(data_start , data_end , tmp1 , cmp);
            vector<matrix>::iterator jump_end_1 = upper_bound(data_start , data_end , tmp2 , cmp);


            for(int i = 0 ; i < size_data ; i++){
                if(sign == 0){

                    if(i != 0){
                        jump_start_1 = lower_bound(jump_start_1 , data_end , tmp1 , cmp);
                        jump_end_1 = upper_bound(jump_start_1 , data_end , tmp2 , cmp);
                    }


                    if(jump_end_1 - jump_start_1 > threshold){
                        counting_user++;


                        int index_item = jump_end_1 - jump_start_1;
                        for(int k = 0 ; k < index_item ; k++){

                            if((data[jump_start_1 - data_start + k].User == cp_user) && (data[jump_start_1 - data_start + k].Item == item) && (data[jump_start_1 - data_start + k].result == 1)){
                                counting_item++;
                                break;
                            }
                        }


                    }

                    sign = 1;
                }
                if(data[i].User != cp_user){
                    cp_user = data[i].User;
                    tmp1.User = cp_user;
                    tmp2.User = cp_user;
                    sign = 0;
                    i--;

                }


            }
            if(counting_user != 0)
                cout<<counting_item<<"/"<<counting_user<<endl;
            else{
                cout<<"EMPTY"<<endl;
            }


        }
        else if(cmd == "findtime_item"){
            long i = 0;

            cin>>i;
            long kmt = 0;



            matrix tmp;

            tmp.User = 0;
            tmp.Item = i;
            tmp.result = -2;
            tmp.UT = 0;

            vector<long> time_stamp;
            vector<matrix>::iterator index_user;


            while(scanf("%ld" , &kmt) == 1){

                tmp.User = kmt;
                index_user = lower_bound(data_start , data_end , tmp , cmp);
                if(data[index_user-data.begin()].User == kmt && data[index_user-data.begin()].Item == i){

                    time_stamp.push_back(data[index_user-data.begin()].UT);
                }
                while(index_user+1 != lower_bound(index_user+1 , data_end , tmp , cmp)){
                    index_user = lower_bound(index_user , data_end , tmp , cmp);
                    if(data[index_user-data.begin()].User == kmt && data[index_user-data.begin()].Item == i){

                        time_stamp.push_back(data[index_user-data.begin()].UT);
                    }
                }

            }



            vector<long>::iterator erase_com;
            erase_com = unique(time_stamp.begin() , time_stamp.end());
            time_stamp.resize(distance(time_stamp.begin() , erase_com));
            sort(time_stamp.begin() , time_stamp.end());
            int time_stamp_size = time_stamp.size();
            if(time_stamp_size != 0)
            for(int k = 0 ; k < time_stamp_size ; k++){
                cout<<time_stamp[k]<<endl;
            }
            else{
                cout<<"EMPTY"<<endl;
            }

            time_stamp.clear();



        }
    }




    fclose(fp);


    return 0;
}

