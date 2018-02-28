#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct data{
    int bidID;
    int clientID;
    int action;
    int price;
    int shareCount;
};

struct output_data{
    int transID;
    int buyClient;
    int sellclient;
    int transprice;
    int transShare;
};



bool cmp_big(const data a , const data b){
    if(a.price != b.price) return a.price<b.price;
        if(a.bidID != b.bidID) return a.bidID>b.bidID;

}


bool cmp_small(const data a , const data b){
    if(a.price != b.price) return a.price>b.price;
        if(a.bidID != b.bidID) return a.bidID>b.bidID;

}

bool cmp(const data a , const data b){
    if(a.bidID != b.bidID) return a.bidID<b.bidID;
        if(a.clientID != b.clientID) return a.clientID<b.clientID;

}

int main(){
    int tmp_bid = 0 , tmp_client = 0 , tmp_action = 0 , tmp_price = 0 , tmp_share = 0;
    vector<data> buy_data;
    vector<data> sell_data;
    vector<output_data> opdata;
    vector<int>cancel;
    vector<data> list_data;
    while(scanf("%d%d%d%d%d" , &tmp_bid , &tmp_client , &tmp_action , &tmp_price , &tmp_share) == 5){
        //cout<<"yee"<<endl;
        data tmp;
        tmp.bidID = tmp_bid;
        tmp.clientID = tmp_client;
        tmp.action = tmp_action;
        tmp.price = tmp_price;
        tmp.shareCount = tmp_share;
        list_data.push_back(tmp);
        if(tmp_action == 0){
            again:
            again_check:
            if(!sell_data.empty()){

                make_heap(sell_data.begin() , sell_data.end() , cmp_small);
                int index = sell_data.front().bidID;
                if(list_data[index].clientID == -1){
                    pop_heap(sell_data.begin() , sell_data.end() , cmp_small);
                    sell_data.pop_back();
                    goto again_check;
                }

                if(tmp.price >= sell_data.front().price){
                    data tmp_2 = sell_data.front();
                    tmp_2.shareCount = sell_data.front().shareCount - tmp.shareCount;
                    if(tmp_2.shareCount > 0){
                        output_data tmp_3;
                        tmp_3.buyClient = tmp.clientID;
                        tmp_3.sellclient = sell_data.front().clientID;
                        tmp_3.transprice = sell_data.front().price;
                        tmp_3.transShare = tmp.shareCount;
                        opdata.push_back(tmp_3);
                        pop_heap(sell_data.begin() , sell_data.end() , cmp_small);
                        sell_data.pop_back();
                        sell_data.push_back(tmp_2);
                        push_heap(sell_data.begin() , sell_data.end() , cmp_small);
                    }
                    else if(tmp_2.shareCount < 0){
                        output_data tmp_3;
                        tmp_3.buyClient = tmp.clientID;
                        tmp_3.sellclient = sell_data.front().clientID;
                        tmp_3.transprice = sell_data.front().price;
                        tmp_3.transShare = sell_data.front().shareCount;
                        opdata.push_back(tmp_3);
                        pop_heap(sell_data.begin() , sell_data.end() , cmp_small);
                        sell_data.pop_back();
                        tmp.shareCount = -tmp_2.shareCount;

                        goto again;


                    }
                    else{
                        output_data tmp_3;
                        tmp_3.buyClient = tmp.clientID;
                        tmp_3.sellclient = sell_data.front().clientID;
                        tmp_3.transprice = sell_data.front().price;
                        tmp_3.transShare = sell_data.front().shareCount;
                        opdata.push_back(tmp_3);
                        pop_heap(sell_data.begin() , sell_data.end() , cmp_small);
                        sell_data.pop_back();
                    }
                }
                else{
                    buy_data.push_back(tmp);
                }
            }
            else{
                buy_data.push_back(tmp);
            }
        }

        if(tmp_action == 1){
            again_2:
            again_check_2:
            if(!buy_data.empty()){

                make_heap(buy_data.begin() , buy_data.end() , cmp_big);

                int index = buy_data.front().bidID;
                if(list_data[index].clientID == -1){
                    pop_heap(buy_data.begin() , buy_data.end() , cmp_big);
                    buy_data.pop_back();
                    goto again_check_2;
                }



                if(tmp.price <= buy_data.front().price){
                    data tmp_2 = buy_data.front();
                    tmp_2.shareCount = buy_data.front().shareCount - tmp.shareCount;
                    if(tmp_2.shareCount > 0){
                        output_data tmp_3;
                        tmp_3.buyClient = buy_data.front().clientID;
                        tmp_3.sellclient = tmp.clientID;
                        tmp_3.transprice = tmp.price;
                        tmp_3.transShare = tmp.shareCount;
                        opdata.push_back(tmp_3);
                        pop_heap(buy_data.begin() , buy_data.end() , cmp_big);
                        buy_data.pop_back();
                        buy_data.push_back(tmp_2);
                        push_heap(buy_data.begin() , buy_data.end() , cmp_big);
                    }
                    else if(tmp_2.shareCount < 0){
                        output_data tmp_3;
                        tmp_3.buyClient = buy_data.front().clientID;
                        tmp_3.sellclient = tmp.clientID;
                        tmp_3.transprice = tmp.price;
                        tmp_3.transShare = buy_data.front().shareCount;
                        opdata.push_back(tmp_3);
                        pop_heap(buy_data.begin() , buy_data.end() , cmp_big);
                        buy_data.pop_back();
                        tmp.shareCount = -tmp_2.shareCount;

                        goto again_2;

                    }
                    else{
                        output_data tmp_3;
                        tmp_3.buyClient = buy_data.front().clientID;
                        tmp_3.sellclient = tmp.clientID;
                        tmp_3.transprice = tmp.price;
                        tmp_3.transShare = buy_data.front().shareCount;
                        opdata.push_back(tmp_3);
                        pop_heap(buy_data.begin() , buy_data.end() , cmp_big);
                        buy_data.pop_back();
                    }
                }
                else{
                    sell_data.push_back(tmp);
                }
            }
            else{
                sell_data.push_back(tmp);
            }
        }

        if(tmp_action == 2){
            cancel.push_back(tmp_price);
            list_data[tmp_price].clientID = -1;
            //sort_heap(buy_data.begin() , buy_data.end() , cmp);

            /*int num = buy_data.size();
            for(int index = 0 ; index < num ; index++){
                if(buy_data[index].bidID == tmp_record.bidID && buy_data[index].clientID == tmp_record.clientID){
                    buy_data[index].bidID = 2147483647;
                    buy_data[index].clientID = 2147483647;
                    buy_data[index].action = 2147483647;
                    buy_data[index].price = -1;
                    buy_data[index].shareCount = -1;


                    goto fin;
                }
            }
            */
            //sort_heap(sell_data.begin() , sell_data.end() , cmp);

            /*num = sell_data.size();
            for(int index = 0 ; index < num ; index ++){
                if(sell_data[index].bidID == tmp_record.bidID && sell_data[index].clientID == tmp_record.clientID){
                    sell_data[index].bidID = 2147483647;
                    sell_data[index].clientID = 2147483647;
                    sell_data[index].action = 2147483647;
                    sell_data[index].price = 2147483647;
                    sell_data[index].shareCount = -1;

                }
            }
            */
/*            fin:
            continue;*/

        }


    }

    for(int i = 0 ; i < opdata.size() ; i++){
        opdata[i].transID = i;
        cout<<opdata[i].transID<<"\t"<<opdata[i].buyClient<<"\t"<<opdata[i].sellclient<<"\t"<<opdata[i].transprice<<"\t"<<opdata[i].transShare<<endl;
    }


    return 0;
}
