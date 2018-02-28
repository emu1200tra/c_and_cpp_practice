#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <cctype>


using namespace std;

/*bool cmp(string a , string b){
    if(a != b) return a<b;
}*/

struct fnfal_data{
    string origin;
    vector<string>output;
};

vector<fnfal_data>input;

void check_dic(vector<string>dictionary){
    int size_dic = dictionary.size();
    for(int i = 0 ; i < size_dic ; i++){
        cout<<dictionary[i]<<endl;
    }
}

vector<string>dictionary;


void check_output(vector<fnfal_data>input){
    int size_output = input.size();
    for(int i = 0 ; i < size_output-1 ; i++){
        cout<<input[i].origin<<" ==>";
        int index = lower_bound(dictionary.begin() , dictionary.end() , input[i].origin) - dictionary.begin();

        if(input[i].origin == dictionary[index]){
            cout<<" OK"<<endl;
        }
        else if(input[i].output.empty()){
            cout<<" NONE"<<endl;
        }
        else{
            for(int j = 0 ; j < input[i].output.size() ; j++){
                cout<<" "<<input[i].output[j];
            }
            if(i + 1 != size_output){
                cout<<endl;
            }
        }

    }
}



bool check(string str1){
    int index = lower_bound(dictionary.begin() , dictionary.end() , str1) - dictionary.begin();
    //cout<<"check:"<<str1<<":"<<dictionary[index]<<endl;
    if(str1 == "tyres"){
        //cout<<"with dictionary:"<<dictionary[index]<<endl;
    }
    if(str1 == dictionary[index]){
        return true;
    }
    else{
        return false;
    }
}

fnfal_data fnfal_data_cat(fnfal_data a , fnfal_data b){
    for(int i = 0 ; i < b.output.size() ; i++){
        a.output.push_back(b.output[i]);
    }
    return a;
}


fnfal_data edit_distance(string string1 , int sign){
        string string1cp = string1;
        fnfal_data tmp , tmp2;
        //------insert--------
        for(int i = 0 ; i < string1cp.size() + 1 ; i++){
            for(char j = 'a' ; j <= 'z' ; j++){
                string1cp.insert(i , 1 , j);
                //cout<<"check insert:"<<string1cp<<endl;
                bool check_bool = check(string1cp);
                if(check_bool){
                    //cout<<"yee"<<endl;
                    tmp.output.push_back(string1cp);
                }
                if(sign == 0){
                    tmp2 = edit_distance(string1cp , 1);
                    tmp = fnfal_data_cat(tmp2 , tmp);
                }
                string1cp = string1;
            }
            string1cp = string1;
        }
        //----------------------
        //-------delete---------
        for(int i = 0 ; i < string1cp.size() ; i++){
            string1cp.erase(i , 1);
            bool check_bool = check(string1cp);
            if(check_bool){
                tmp.output.push_back(string1cp);
            }
            if(sign == 0){
                tmp2 = edit_distance(string1cp , 1);
                tmp = fnfal_data_cat(tmp2 , tmp);
            }
            string1cp = string1;
        }
        //-----------------------
        //-------substitute-------
        for(int i = 0 ; i < string1cp.size() ; i++){
            for(char j = 'a' ; j <= 'z' ; j++){
                string1cp.erase(i , 1);
                string1cp.insert(i , 1 , j);

                bool check_bool = check(string1cp);
                if(check_bool){
                    tmp.output.push_back(string1cp);
                }
                if(sign == 0){
                    tmp2 = edit_distance(string1cp , 1);
                    tmp = fnfal_data_cat(tmp2 , tmp);
                }
                string1cp = string1;
            }
            string1cp = string1;
        }
        //------------------------
        //-------transpose--------
        for(int i = 1 ; i < string1cp.size() ; i++){
            char tmp_alphabat = string1cp[i];
            string1cp[i] = string1cp[i-1];
            string1cp[i-1] = tmp_alphabat;
            bool check_bool = check(string1cp);
            if(check_bool){
                tmp.output.push_back(string1cp);
            }
            if(sign == 0){
                tmp2 = edit_distance(string1cp , 1);
                tmp = fnfal_data_cat(tmp2 , tmp);
            }
            string1cp = string1;
        }
        //------------------------
        return tmp;
}



int main(){
    char string1[4096];
    string string1tmp;
    string string1cp;
    FILE *fp;
    fp = fopen("/tmp2/dsa2016_hw5/cmudict-0.7b" , "r");
    char tmp_data[4096];
    char string_cp[4096];


    if (fp == NULL){
        perror ("Error opening file");
    }
    while(!feof(fp)){

        fgets(tmp_data , 256 , fp);

        int i;
        for(i = 0 ; i < 255 ; i++){
            if(tmp_data[i] == ' '){
                break;
            }
            if(tmp_data[i] == '\n'){
                break;
            }
            string_cp[i] = tmp_data[i];
        }

        string_cp[i] = '\0';
        string string_cp2 = string_cp;
        transform(string_cp2.begin() , string_cp2.end() , string_cp2.begin() , [](unsigned char c) { return tolower(c); });
        dictionary.push_back(string_cp2);
        string_cp[0] = '\0';
        tmp_data[0] = '\0';
    }

    fclose(fp);
    sort(dictionary.begin() , dictionary.end());




    while(!feof(stdin)){

        fgets(string1 , 4096 , stdin);

        int i;
        for(i = 0 ; i < 4096 ; i++){
            //cout<<string1[i]<<":";
            if(string1[i] == '\n' || string1[i] == '\r'){
                string1[i] = '\0';
                break;
            }
            if(string1[i] == '\t'){
                string1[i] = '\0';
                break;
            }
            if(string1[i] == ' '){
                string1[i] = '\0';
                break;
            }
            //cout<<string1[i]<<endl;
        }
        string1[i] == '\0';
        string1tmp = string1;
        //cout<<string1tmp<<"\t";
        fnfal_data tmp;
        string1cp = string1tmp;
        string1[0] = '\0';
        tmp = edit_distance(string1cp , 0);
        tmp.origin = string1tmp;
        sort(tmp.output.begin() , tmp.output.end());
        vector<string>::iterator erasedata;
        erasedata = unique(tmp.output.begin() , tmp.output.end());
        tmp.output.resize(distance(tmp.output.begin() , erasedata));

        input.push_back(tmp);

      //  cout<<"done"<<endl;
    }

    check_output(input);


    return 0;
}
