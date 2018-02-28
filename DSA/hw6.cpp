#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <cctype>
//#include <conio.h>

using namespace std;

vector<float>M_vector;
vector<float>N_vector;


struct data{
    float distance_min;
    int i;
    int j;
};


float abs_float(float a){
    if(a < 0){
        return -a;
    }
    else{
        return a;
    }
}

bool cmp(data a , data b){
    if(a.distance_min!=b.distance_min) return a.distance_min<b.distance_min;
}

struct point{
    int i;
    int j;
};

float matrix[1000][100];

point pt_matrix[1000][100];

float distance_DP(int i , int j){

    float record = 0.00;
    //getch();
    if(i == 0 && j == 0){
        record = abs_float(M_vector[i] - N_vector[j]);
        matrix[i][j] = record;

        return record;
    }
    else if(i == 0 && j != 0){

        return 9999999.99999;
    }
    else if(i != 0 && j != 0){

        if(matrix[i][j] != -1){
            return matrix[i][j];
        }
        float a = distance_DP(i-1 , j);

        float b = distance_DP(i-1 , j-1);

        if(a >= b){
            record = abs_float(M_vector[i] - N_vector[j]) + b;
            pt_matrix[i][j].i = i-1;
            pt_matrix[i][j].j = j-1;
            matrix[i][j] = record;

            return record;
        }
        else{
            record = abs_float(M_vector[i] - N_vector[j]) + a;
            pt_matrix[i][j].i = i-1;
            pt_matrix[i][j].j = j;
            matrix[i][j] = record;
            return record;
        }

    }
    else{
        record = abs_float(M_vector[i] - N_vector[j]) + distance_DP(i-1 , 0);
        pt_matrix[i][0].i = i-1;
        pt_matrix[i][0].j = 0;
        matrix[i][0] = record;
        return record;
    }


}




int main(){

    for(int i = 0 ; i < 1000 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            matrix[i][j] = -1;
        }
    }


    int m , n;
    cin>>m;

    float tmp = 0.000;
    float tmp_2 = 0.00;
    for(int i = 0 ; i < m ; i++){
        cin>>tmp;
        M_vector.push_back(tmp);
    }
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>tmp_2;
        N_vector.push_back(tmp_2);
    }

    vector<data>distance_min_data;

    for(int i = 0 ; i < N_vector.size() ; i++){
        data tmp_data;
        tmp_data.distance_min = distance_DP(M_vector.size()-1 , i);
        tmp_data.i = M_vector.size()-1;
        tmp_data.j = i;

        distance_min_data.push_back(tmp_data);


    }

    sort(distance_min_data.begin() , distance_min_data.end() , cmp);

    cout<<distance_min_data[0].distance_min<<endl;

    vector<int>s_record;
    int a = distance_min_data[0].i , b = distance_min_data[0].j;
    while(a != 0 && b != 0){
        int tmp_a = a , tmp_b = b;

        if(b != pt_matrix[a][b].j){
            s_record.push_back(a);
        }

        b = pt_matrix[tmp_a][tmp_b].j;
        a = pt_matrix[tmp_a][tmp_b].i;
    }

    s_record.push_back(0);

    for(int i = s_record.size()-1 ; i >= 0 ; i--){
        cout<<s_record[i];
        if(i != 0){
            cout<<" ";
        }
    }
    cout<<endl;

    return 0;
}

