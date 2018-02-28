#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

struct data{
    string element;
    int frequency;
};

struct vec{
    vector<data>data_vector;
};

unordered_map<string , int> mydict2w;
unordered_map<string , int> mydict3w;
unordered_map<string , int> mydict4w;
unordered_map<string , int> mydict5w;
unordered_map<string , int> twice;

string prep[20] = {"of" , "to" , "in" , "for" , "with" , "on" , "at" , "by", "from" , "up" , "about" , "than" , "after" , "before" , "down" , "between" , "under" , "since" , "without" , "near"};

vec veccat(vector<data> a , vector<data> b){
    vector<data>c;
    for(int i = 0 ; i < a.size() ; i++){
        c.push_back(a[i]);
    }
    for(int i = 0 ; i < b.size() ; i++){
        c.push_back(b[i]);
    }
    vec tmp;
    tmp.data_vector = c;
    return tmp;
}


int record_times = 0;

vec EDITa(vector<string>piece){
    string record;
    vector<data>return_data;
    vector<string>piece_record = piece;
    for(int i = 0 ; i < piece.size()+1 ; i++){
        if(i != piece.size()){
            for(int j = 0 ; j < 20 ; j++){
                piece.insert(piece.begin()+i , prep[j]);
                int k;
                for(k = 0 ; k < piece.size() ; k++){
                    record += piece[k];
                    //if bug check '\0' here
                    if(k != piece.size()-1){
                        record.push_back(' ');
                    }
                }
                unordered_map<string , int>::const_iterator check_twice = twice.find(record);
                if(check_twice != twice.end()){
                    goto jump;
                }
                else{
                    pair<string , int>tmp_pair(record , 0);
                    twice.insert (tmp_pair);
                }
                //cout<<"debug:"<<record<<endl;
                //record += '\0';
                //if bug check this
                switch(piece.size()){
                case 2:
                {
                    unordered_map<string , int>::const_iterator got = mydict2w.find(record);
                    if(got != mydict2w.end()){
                        data tmp_data;
                        tmp_data.element = got->first;
                        tmp_data.frequency = got->second;
                        return_data.push_back(tmp_data);
                    }
                }
                break;
                case 3:
                {
                    unordered_map<string , int>::const_iterator got = mydict3w.find(record);
                    if(got != mydict3w.end()){
                        data tmp_data;
                        tmp_data.element = got->first;
                        tmp_data.frequency = got->second;
                        return_data.push_back(tmp_data);
                    }
                }
                break;
                case 4:
                {
                    unordered_map<string , int>::const_iterator got = mydict4w.find(record);
                    if(got != mydict4w.end()){
                        data tmp_data;
                        tmp_data.element = got->first;
                        tmp_data.frequency = got->second;
                        return_data.push_back(tmp_data);
                    }
                }
                break;
                case 5:
                {
                    unordered_map<string , int>::const_iterator got = mydict5w.find(record);
                    if(got != mydict5w.end()){
                        data tmp_data;
                        tmp_data.element = got->first;
                        tmp_data.frequency = got->second;
                        return_data.push_back(tmp_data);
                    }
                }
                break;
                }
                jump:
                if(record_times == 0){
                    record_times++;
                    vector<data>return_vec = EDITa(piece).data_vector;
                    return_data = veccat(return_vec , return_data).data_vector;
                    record_times = 0;
                    piece = piece_record;
                }
                piece = piece_record;
                record.clear();

            }

        }
        else{
           for(int j = 0 ; j < 20 ; j++){
                piece.push_back(prep[j]);
                int k;
                for(k = 0 ; k < piece.size() ; k++){
                    record += piece[k];
                    //if bug check '\0' here
                    if(k != piece.size()-1){
                        record.push_back(' ');
                    }
                }
                unordered_map<string , int>::const_iterator check_twice = twice.find(record);
                if(check_twice != twice.end()){
                    goto jump2;
                }
                else{
                    pair<string , int>tmp_pair(record , 0);
                    twice.insert (tmp_pair);
                }
                //cout<<"debug:"<<record<<endl;
                //record += '\0';
                //if bug check this
                switch(piece.size()){
                case 2:
                {
                    unordered_map<string , int>::const_iterator got = mydict2w.find(record);
                    if(got != mydict2w.end()){
                        data tmp_data;
                        tmp_data.element = got->first;
                        tmp_data.frequency = got->second;
                        return_data.push_back(tmp_data);
                    }
                }
                break;
                case 3:
                {
                    unordered_map<string , int>::const_iterator got = mydict3w.find(record);
                    if(got != mydict3w.end()){
                        data tmp_data;
                        tmp_data.element = got->first;
                        tmp_data.frequency = got->second;
                        return_data.push_back(tmp_data);
                    }
                }
                break;
                case 4:
                {
                    unordered_map<string , int>::const_iterator got = mydict4w.find(record);
                    if(got != mydict4w.end()){
                        data tmp_data;
                        tmp_data.element = got->first;
                        tmp_data.frequency = got->second;
                        return_data.push_back(tmp_data);
                    }
                }
                break;
                case 5:
                {
                    unordered_map<string , int>::const_iterator got = mydict5w.find(record);
                    if(got != mydict5w.end()){
                        data tmp_data;
                        tmp_data.element = got->first;
                        tmp_data.frequency = got->second;
                        return_data.push_back(tmp_data);
                    }
                }
                break;
                }
                jump2:
                if(record_times == 0){
                    record_times++;
                    vector<data>return_vec = EDITa(piece).data_vector;
                    return_data = veccat(return_vec , return_data).data_vector;
                    record_times = 0;
                    piece = piece_record;
                }

                piece = piece_record;
                record.clear();

            }
        }

        piece = piece_record;
        record.clear();

    }
    vec tmp_vec;
    tmp_vec.data_vector = return_data;
    return tmp_vec;

}

int sign_times = 0;

vec EDITb(vector<string>piece , vector<int>prep_record){
    cout<<"into:"<<sign_times<<endl;
    vector<int>recordinserta = prep_record;
    vector<int>recordinsertb = prep_record;
    vector<int>recorddelete = prep_record;
    vector<int>recordsubstitute = prep_record;
    vector<string>inserta = piece;
    vector<string>insertb = piece;
    vector<string>deleted = piece;
    vector<string>substitute = piece;
    vector<data>return_data;
    for(int i = 0 ; i < 20 ; i++){
        inserta = piece;
        insertb = piece;
        substitute = piece;
        recordinserta = prep_record;
        recordinsertb = prep_record;
        recordsubstitute = prep_record;
        //-------------------
        //do nothing;
        //------inserta------
        inserta.insert(inserta.begin()+recordinserta[sign_times] , prep[i]);
        for(int j = sign_times+1 ; j < recordinserta.size() ; j++){
            recordinserta[j]++;
        }
        //------insertb------
        if(recordinsertb[sign_times]+1 != insertb.size()){
            insertb.insert(insertb.begin()+recordinsertb[sign_times]+1 , prep[i]);
            for(int j = sign_times+1 ; j < recordinsertb.size() ; j++){
                recordinsertb[j]++;
            }
        }
        else{
            cout<<"prep:"<<prep[i]<<endl;
            insertb.push_back(prep[i]);
        }

        //------substitute-----
        substitute[recordsubstitute[sign_times]] = prep[i];
        if(sign_times != prep_record.size()-1){
            sign_times++;
            int tmp_sign_time = sign_times;
            return_data = veccat(return_data , EDITb(piece , prep_record).data_vector).data_vector;
            sign_times = tmp_sign_time;
            return_data = veccat(return_data , EDITb(inserta , recordinserta).data_vector).data_vector;
            sign_times = tmp_sign_time;
            return_data = veccat(return_data , EDITb(insertb , recordinsertb).data_vector).data_vector;
            sign_times = tmp_sign_time;
            return_data = veccat(return_data , EDITb(substitute , recordsubstitute).data_vector).data_vector;
            sign_times = tmp_sign_time-1;
        }
        else{
            //built string and check here;
            string catpiece;
            string catinserta;
            string catinsertb;
            string catsubstitute;
            cout<<"---------piece------"<<endl;
            int z = 0;
            for(z = 0 ; z < piece.size() ; z++){
                    catpiece += piece[z];
                    if(z != piece.size()-1){
                        catpiece.push_back(' ');
                    }
            }
            unordered_map<string , int>::const_iterator check_twice = twice.find(catpiece);
            if(check_twice != twice.end()){
                goto jump;
            }
            else{
                pair<string , int>tmp_pair(catpiece , 0);
                twice.insert (tmp_pair);
            }
            switch(piece.size()){
            case 2:
            {
                unordered_map<string , int>::const_iterator got = mydict2w.find(catpiece);
                if(got != mydict2w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 3:
            {
                unordered_map<string , int>::const_iterator got = mydict3w.find(catpiece);
                if(got != mydict3w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 4:
            {
                unordered_map<string , int>::const_iterator got = mydict4w.find(catpiece);
                if(got != mydict4w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 5:
            {
                unordered_map<string , int>::const_iterator got = mydict5w.find(catpiece);
                if(got != mydict5w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            }
            jump:
            cout<<"---------------inserta----------------"<<endl;
            for(z = 0 ; z < inserta.size() ; z++){
                    catinserta += inserta[z];
                    if(z != inserta.size()-1){
                        catinserta.push_back(' ');
                    }
            }
            check_twice = twice.find(catinserta);
            if(check_twice != twice.end()){
                goto jump2;
            }
            else{
                pair<string , int>tmp_pair(catinserta , 0);
                twice.insert (tmp_pair);
            }
            switch(inserta.size()){
            case 2:
            {
                unordered_map<string , int>::const_iterator got = mydict2w.find(catinserta);
                if(got != mydict2w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 3:
            {
                unordered_map<string , int>::const_iterator got = mydict3w.find(catinserta);
                if(got != mydict3w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 4:
            {
                unordered_map<string , int>::const_iterator got = mydict4w.find(catinserta);
                if(got != mydict4w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 5:
            {
                unordered_map<string , int>::const_iterator got = mydict5w.find(catinserta);
                if(got != mydict5w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            }
            jump2:
            cout<<"-----------------insertb---------------"<<endl;
            for(z = 0 ; z < insertb.size() ; z++){
                    catinsertb += insertb[z];
                    if(z != insertb.size()-1){
                        catinsertb.push_back(' ');
                    }
            }
            cout<<"insertb:"<<catinsertb<<";"<<endl;
            check_twice = twice.find(catinsertb);
            if(check_twice != twice.end()){
                goto jump3;
            }
            else{
                pair<string , int>tmp_pair(catinsertb , 0);
                twice.insert (tmp_pair);
            }
            switch(insertb.size()){
            case 2:
            {
                unordered_map<string , int>::const_iterator got = mydict2w.find(catinsertb);
                if(got != mydict2w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 3:
            {
                unordered_map<string , int>::const_iterator got = mydict3w.find(catinsertb);
                if(got != mydict3w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 4:
            {
                unordered_map<string , int>::const_iterator got = mydict4w.find(catinsertb);
                if(got != mydict4w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 5:
            {
                unordered_map<string , int>::const_iterator got = mydict5w.find(catinsertb);
                if(got != mydict5w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            }
            jump3:
            cout<<"-------------------substitute--------------"<<endl;
            for(z = 0 ; z < substitute.size() ; z++){
                    catsubstitute += substitute[z];
                    if(z != substitute.size()-1){
                        catsubstitute.push_back(' ');
                    }
            }
            check_twice = twice.find(catsubstitute);
            if(check_twice != twice.end()){
                goto jump4;
            }
            else{
                pair<string , int>tmp_pair(catsubstitute , 0);
                twice.insert (tmp_pair);
            }
            switch(substitute.size()){
            case 2:
            {
                unordered_map<string , int>::const_iterator got = mydict2w.find(catsubstitute);
                if(got != mydict2w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 3:
            {
                unordered_map<string , int>::const_iterator got = mydict3w.find(catsubstitute);
                if(got != mydict3w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 4:
            {
                unordered_map<string , int>::const_iterator got = mydict4w.find(catsubstitute);
                if(got != mydict4w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            case 5:
            {
                unordered_map<string , int>::const_iterator got = mydict5w.find(catsubstitute);
                if(got != mydict5w.end()){
                    data tmp_data;
                    tmp_data.element = got->first;
                    tmp_data.frequency = got->second;
                    return_data.push_back(tmp_data);
                }
            }
            break;
            }
            jump4:
            continue;
            catinserta.clear();
            catinsertb.clear();
            catsubstitute.clear();

        }
        //remember to restart vector here;


    }
    //------delete-------
    cout<<"-----------------delete--------------------"<<endl;
    deleted.erase(deleted.begin()+recorddelete[sign_times]);
    cout<<"here1"<<endl;
    for(int j = sign_times + 1 ; j < recorddelete.size() ; j++){
        recorddelete[j]--;
    }
    cout<<"here2"<<endl;
    if(sign_times != prep_record.size()-1){
        cout<<"here3"<<endl;
        sign_times++;
        int tmp_sign_time = sign_times;
        return_data = veccat(return_data , EDITb(deleted , recorddelete).data_vector).data_vector;
        sign_times = tmp_sign_time-1;
        cout<<"here4"<<endl;
    }
    else{
        //built string and check here;
        cout<<"here5"<<endl;
        string catdelete;
        int z = 0;
        for(z = 0 ; z < deleted.size() ; z++){
                catdelete += deleted[z];
                if(z != deleted.size()-1){
                    catdelete.push_back(' ');
                }
        }
        unordered_map<string , int>::const_iterator check_twice = twice.find(catdelete);
        if(check_twice != twice.end()){
            goto jump5;
        }
        else{
            pair<string , int>tmp_pair(catdelete , 0);
            twice.insert (tmp_pair);
        }
        switch(deleted.size()){
        case 2:
        {
            unordered_map<string , int>::const_iterator got = mydict2w.find(catdelete);
            if(got != mydict2w.end()){
                data tmp_data;
                tmp_data.element = got->first;
                tmp_data.frequency = got->second;
                return_data.push_back(tmp_data);
            }
        }
        break;
        case 3:
        {
            unordered_map<string , int>::const_iterator got = mydict3w.find(catdelete);
            if(got != mydict3w.end()){
                data tmp_data;
                tmp_data.element = got->first;
                tmp_data.frequency = got->second;
                return_data.push_back(tmp_data);
            }
        }
        break;
        case 4:
        {
            unordered_map<string , int>::const_iterator got = mydict4w.find(catdelete);
            if(got != mydict4w.end()){
                data tmp_data;
                tmp_data.element = got->first;
                tmp_data.frequency = got->second;
                return_data.push_back(tmp_data);
            }
        }
        break;
        case 5:
        {
            unordered_map<string , int>::const_iterator got = mydict5w.find(catdelete);
            if(got != mydict5w.end()){
                data tmp_data;
                tmp_data.element = got->first;
                tmp_data.frequency = got->second;
                return_data.push_back(tmp_data);
            }
        }
        break;
        }
        jump5:

        cout<<"here6"<<endl;


    }
    vec tmp;
    tmp.data_vector = return_data;
    return tmp;
}


vec check(string query){
    vector<string>piece;
    char tmp[256];
    string tmp_2;
    int k = 0;
    for(int i = 0 ; i < query.size() ; i++){
        if(query[i] == ' ' || query[i] == '\0'){
            tmp[k] = '\0';
            cout<<"tmp:"<<tmp<<endl;
            k = 0;
            tmp_2 = tmp;
            piece.push_back(tmp_2);
        }
        else{
            tmp[k] = query[i];
            k++;
        }

    }
    tmp[k] = '\0';
    tmp_2 = tmp;
    piece.push_back(tmp_2);
    cout<<"tmp:"<<tmp<<endl;
    vector<int>record_index;
    for(int i = 0 ; i < piece.size() ; i++){
        if(piece[i] == "of" || piece[i] == "to" || piece[i] == "in" || piece[i] == "for" || piece[i] == "with" || piece[i] == "on" || piece[i] == "at" || piece[i] == "by" || piece[i] == "from" || piece[i] == "up" || piece[i] == "about" || piece[i] == "than" || piece[i] == "after" || piece[i] == "before" || piece[i] == "down" || piece[i] == "between" || piece[i] == "under" || piece[i] == "since" || piece[i] == "without" || piece[i] == "near"){
            record_index.push_back(i);
        }
    }
    vector<data>record;
    if(record_index.empty()){
        switch(piece.size()){
        case 2:
        {
            cout<<"query:"<<query<<endl;
            unordered_map<string , int>::const_iterator check_noprep = mydict2w.find(query);
            if(check_noprep != mydict2w.end()){
                data tmp_data;
                tmp_data.element = check_noprep->first;
                tmp_data.frequency = check_noprep->second;
                record.push_back(tmp_data);
            }
        }
        break;
        case 3:
        {
            cout<<"query3:"<<query<<";"<<endl;
            unordered_map<string , int>::const_iterator check_noprep = mydict3w.find(query);

            //cout<<"find:"<<check_noprep->first<<":"<<check_noprep->second<<endl;
            if(check_noprep != mydict3w.end()){
                data tmp_data;
                tmp_data.element = check_noprep->first;
                tmp_data.frequency = check_noprep->second;
                record.push_back(tmp_data);
            }
        }
        break;
        case 4:
        {
            cout<<"query:"<<query<<endl;
            unordered_map<string , int>::const_iterator check_noprep = mydict4w.find(query);
            if(check_noprep != mydict4w.end()){
                data tmp_data;
                tmp_data.element = check_noprep->first;
                tmp_data.frequency = check_noprep->second;
                record.push_back(tmp_data);
            }
        }
        break;
        case 5:
        {
            cout<<"query:"<<query<<endl;
            unordered_map<string , int>::const_iterator check_noprep = mydict5w.find(query);
            if(check_noprep != mydict5w.end()){
                data tmp_data;
                tmp_data.element = check_noprep->first;
                tmp_data.frequency = check_noprep->second;
                record.push_back(tmp_data);
            }
        }
        break;
        }

        vector<data>tmp_data = EDITa(piece).data_vector;
        return veccat(tmp_data , record);

    }
    else{
        vec tmp_data;
        tmp_data = EDITb(piece , record_index);

        return tmp_data;
    }


}


bool cmp(data a , data b){
    if(a.frequency != b.frequency) return a.frequency>b.frequency;
        if(a.element != b.element) return a.element<b.element;

}



int main(){
    FILE *fp1;
    fp1 = fopen("/tmp2/dsa2016_project/2gm.small.txt" , "r");
    char tmp_data[4096];
    if(fp1 == NULL){
        perror("error opening file");
    }
    string  key;
    while(!feof(fp1)){
        fgets(tmp_data , 4096 , fp1);
        char tmp[4096] , tmp_2[4096];
        int i = 0 , k = 0 , sign = 0 , sign2 = 0;
        for(i = 0 ; i < 4096 ; i++){
            if(tmp_data[i] == '\t'){
                tmp[i] = '\0';
                sign2 = 1;
                i++;
            }
            if(tmp_data[i] == '\0'){
                break;
            }
            if(sign2 == 0){
                tmp[i] = tmp_data[i];
            }
            else if(sign2 == 1){
                tmp_2[k] = tmp_data[i];
                k++;
            }
        }
        string tmp_element = tmp;

        tmp_2[k] = '\0';
        string trans = tmp_2;
        stringstream ss;
        int element = 0;
        ss << trans;
        ss >> element;
        key = tmp_element;
        pair<string , int>tmp_pair(key , element);
        mydict2w.insert (tmp_pair);
    }
    fclose(fp1);
    //----------------
    fp1 = fopen("/tmp2/dsa2016_project/3gm.small.txt" , "r");
    if(fp1 == NULL){
        perror("error opening file");
    }
    while(!feof(fp1)){
        fgets(tmp_data , 4096 , fp1);
        char tmp[4096] , tmp_2[4096];
        int i = 0 , k = 0 , sign = 0 , sign2 = 0;
        for(i = 0 ; i < 4096 ; i++){
            if(tmp_data[i] == '\t'){
                tmp[i] = '\0';
                sign2 = 1;
                i++;
            }
            if(tmp_data[i] == '\0'){
                break;
            }
            if(sign2 == 0){
                tmp[i] = tmp_data[i];
            }
            else if(sign2 == 1){
                tmp_2[k] = tmp_data[i];
                k++;
            }
        }
        string tmp_element = tmp;

        tmp_2[k] = '\0';
        string trans = tmp_2;
        stringstream ss;
        int element = 0;
        ss << trans;
        ss >> element;
        key = tmp_element;
        pair<string , int>tmp_pair(key , element);
        mydict3w.insert (tmp_pair);
    }
    fclose(fp1);
    //----------------
    fp1 = fopen("/tmp2/dsa2016_project/4gm.small.txt" , "r");
    if(fp1 == NULL){
        perror("error opening file");
    }
    while(!feof(fp1)){
        fgets(tmp_data , 4096 , fp1);
        char tmp[4096] , tmp_2[4096];
        int i = 0 , k = 0 , sign = 0 , sign2 = 0;
        for(i = 0 ; i < 4096 ; i++){
            if(tmp_data[i] == '\t'){
                tmp[i] = '\0';
                sign2 = 1;
                i++;
            }
            if(tmp_data[i] == '\0'){
                break;
            }
            if(sign2 == 0){
                tmp[i] = tmp_data[i];
            }
            else if(sign2 == 1){
                tmp_2[k] = tmp_data[i];
                k++;
            }
        }
        string tmp_element = tmp;

        tmp_2[k] = '\0';
        string trans = tmp_2;
        stringstream ss;
        int element = 0;
        ss << trans;
        ss >> element;
        key = tmp_element;
        pair<string , int>tmp_pair(key , element);
        mydict4w.insert (tmp_pair);
    }
    fclose(fp1);
    //-----------------------------
    fp1 = fopen("/tmp2/dsa2016_project/5gm.small.txt" , "r");
    if(fp1 == NULL){
        perror("error opening file");
    }
    while(!feof(fp1)){
        fgets(tmp_data , 4096 , fp1);
        char tmp[4096] , tmp_2[4096];
        int i = 0 , k = 0 , sign = 0 , sign2 = 0;
        for(i = 0 ; i < 4096 ; i++){
            if(tmp_data[i] == '\t'){
                tmp[i] = '\0';
                sign2 = 1;
                i++;
            }
            if(tmp_data[i] == '\0'){
                break;
            }
            if(sign2 == 0){
                tmp[i] = tmp_data[i];
            }
            else if(sign2 == 1){
                tmp_2[k] = tmp_data[i];
                k++;
            }
        }
        string tmp_element = tmp;

        tmp_2[k] = '\0';
        string trans = tmp_2;
        stringstream ss;
        int element = 0;
        ss << trans;
        ss >> element;
        key = tmp_element;
        pair<string , int>tmp_pair(key , element);
        mydict5w.insert (tmp_pair);
    }
    fclose(fp1);
    //-------dictionary complete-----------
    cout<<"dic complete"<<endl;
    /*for(auto& x:mydict3w)
        cout<<x.first << ":" << x.second<< endl;
*/
    char input_string[4096];
    string query;
    while(!feof(stdin)){
        fgets(input_string , 4096 , stdin);
        query = input_string;
        query.pop_back();
        vector<data>output;
        output = check(query).data_vector;
        sort(output.begin() , output.end() , cmp);
        /*vector<data>::iterator erase_com;
        erase_com = unique(output.begin() , output.end() , cmp);
        output.resize(distance(output.begin() , erase_com));
        //sort(output.begin() , output.end() , cmp);*/
        cout<<"query: "<<query<<endl;
        if(output.size()<10){
            cout<<"output: "<<output.size()<<endl;
        }
        else{
            cout<<"output: "<<"10"<<endl;
        }
        for(int i = 0 ; i < output.size() ; i++){
            output[i].frequency;//.pop_back();
            cout<<output[i].element<<"\t"<<output[i].frequency<<endl;
            if(i==9){
                break;
            }
        }
        twice.clear();
    }



    return 0;

}
