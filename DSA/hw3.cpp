#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

struct node{
  int x;
  int y;
  struct node *next;
};



struct data{
    int num_id;
    char info[30];
};

struct record{
    int length;
    int width;
};

struct data_sl{
    int length[30][16];
    int width[30][16];
};

record last_record[900];
int counting = 0;


void check_data(data_sl a , int length , int width){
    cout<<"check start"<<endl;
    int index  = 0;
    for(int i = 0 ; i < length ; i++){
        while(a.length[i][index] != -1){
            cout<<a.length[i][index]<<"\t";
            index++;
        }
        cout<<endl;
        index = 0;
    }
    index = 0;
    cout<<"----------------"<<endl;
    for(int i = 0 ; i < width ; i++){
        while(a.width[i][index] != -1){
            cout<<a.width[i][index]<<"\t";
            index++;
        }
        cout<<endl;
        index = 0;
    }

    cout<<endl;
}
/*
bool check_ans_length(data a , int length , bool matrix[30]){
    int matrix_result_length[16] = {0};
    int recorder = 0 , index = 0;
    for(int i = 0 ; i < length ; i++){
        if(matrix[i] == true){
            recorder++;
        }
        else{
            if(recorder != 0){
                matrix_result_length[index] = recorder;
                index++;
                recorder = 0;
            }
        }
    }
    index = 0;
    int index_data = 0;

    while(a.info[index_data] != '\n'){
        if(a.info[index_data] != ' '){
            if((int)a.info[index_data] != matrix_result_length[index]){
                return false;
            }
            else{
                index++;
            }
        }
        index_data++;
    }
    return true;



}



class stack_step{
    struct node *root;
public:
    stack_step();
    void last_step_push(int , int );
    record last_step_pop();
    bool check_empty();
};

stack_step::stack_step(){
    top = NULL;
}

void stack_step::last_step_push(int width , int length){
    last_record[counting].length = length;
    last_record[counting].width = width;
    counting++;
}



record stack_step::last_step_pop(){
    counting--;
    return last_record[counting];
}

bool stack_step::check_empty(){
    return (top == NULL);
}

class nonogram{
private:
    int num;
    int **A;
    //This part has to check
public:

};

*/

struct wraper_int{
    vector<int> line;
};

struct wraper_char{
    vector<char> line;
};

char UC = '_' , FL = 'x' , NT = ' ' , none = '.';

wraper_char alternatives(wraper_int data_ans , int length){
    int datalength = data_ans.line.size();
    int datasum;
    for(int i = 0 ; i < datalength ; i++){
        datasum += data_ans.line[i];
    }
    if(datalength == 0){
        wraper_char return_vl;

        for(int i = 0 ; i < length ; i++){
            return_vl.line.push_back(UC);
        }
        return return_vl;
    }
    int j = 0;
    wraper_char result;
    if(datalength == 1){
        j = 1;
    }
    string header;
    wraper_char tails;
    for(int i = 0 ; i < length - datalength - datasum + 2 ; i++){
        header = UC * i + FL * data_ans.line[0] + UC * (1-j);
        if(j){
            for(int k = 0 ; k < (length - (sizeof(header)/sizeof(char))) ; k++){
                tails.line.push_back(UC);
            }
        }
        else{
            wraper_int cpy;
            for(int k = 1 ; k < datalength ; k++){
                cpy.line[k-1] = data_ans.line[k];
            }
            tails = alternatives(cpy , (length - (sizeof(header) / sizeof(char))));
        }
        for(int k = 0 ; k < (sizeof(header) / sizeof(char)) ; k++){
            result.line.push_back(header[k]);
        }
        for(int k = 0 ; k < tails.line.size() ; k++){
            result.line.push_back(tails.line[k]);
        }
    }
    return result;

}

char decide(char alter[30][30] , int idx){
    char mark = alter[0][idx];
    for(int j = 1 ; j < (sizeof(alter)/sizeof(char)) ; j++){
        if(mark != alter[j][idx]){
            return none;
        }
    }
    if(mark == FL){
        return FL;
    }
    else{
        return NT;
    }
}

void delete_il(char **alter , int *idx , char *mark){
    //this part has to check
    if(alter != 'E' && sizeof(**alter))
}



int main(){
    int matrix [30][30] = {0};
    int length = 0 , width = 0;
    cin>>length;
    cin>>width;
    char garbage = '0';
    scanf("%c" , &garbage);
    data array_length[30] , array_width[30];
    for(int i = 0 ; i < length ; i++){
        array_length[i].num_id = i;
        fgets(array_length[i].info , 30 , stdin);
    }
    for(int i = 0 ; i < width ; i++){
        array_width[i].num_id = i;
        fgets(array_width[i].info , 30 , stdin);
    }
    int recorder = 0 , index = 0;
    data_sl length_sl;
    for(int i = 0 ; i < length ; i++){
        while(array_length[i].info[recorder] != '\n'){
            if(array_length[i].info[recorder] != ' '){
                if(recorder != 0){
                    if(array_length[i].info[recorder-1] != ' '){
                        cout<<"check"<<endl;
                        length_sl.length[i][--index] = (((int)array_length[i].info[recorder-1] - 48)*10 + ((int)array_length[i].info[recorder] - 48));
                        //cout<<"check here"<<((int)array_length[i].info[recorder-1] - 48)*10 + ((int)array_length[i].info[recorder] - 48)<<endl;
                        index++;
                    }
                    else{
                        length_sl.length[i][index] = (int)array_length[i].info[recorder] - 48;
                        //cout<<"check here"<<(int)array_length[i].info[recorder] - 48<<endl;
                        index++;
                    }
                }
                else{
                    length_sl.length[i][index] = (int)array_length[i].info[recorder] - 48;
                    //cout<<"check here"<<(int)array_length[i].info[recorder] - 48<<endl;
                    index++;
                }
            }
            recorder++;
        }
        length_sl.length[i][index] = -1;
        index = 0;
        recorder = 0;
    }
    recorder = 0;
    index = 0;

    for(int j = 0 ; j < width ; j++){
        while(array_width[j].info[recorder] != '\n'){
            if(array_width[j].info[recorder] != ' '){
                if(recorder != 0){
                    if(array_width[j].info[recorder-1] != ' '){
                        length_sl.width[j][--index] = ((int)array_width[j].info[recorder-1] - 48)*10 + ((int)array_width[j].info[recorder] - 48);
                        //cout<<"check here"<<length_sl.width[j][index]<<endl;
                        index++;
                    }
                    else{
                        length_sl.width[j][index] = (int)array_width[j].info[recorder] - 48;
                        //cout<<"check here"<<length_sl.width[j][index]<<endl;
                        index++;
                    }
                }
                else{
                    length_sl.width[j][index] = (int)array_width[j].info[recorder] - 48;
                   // cout<<"check here"<<length_sl.width[j][index]<<endl;
                    index++;
                }
            }
            recorder++;
        }
        length_sl.width[j][index] = -1;
        index = 0;
        recorder = 0;
    }

    check_data(length_sl , length , width);





    return 0;
}
