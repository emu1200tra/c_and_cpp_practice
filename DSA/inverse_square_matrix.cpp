#include<iostream>
#include<cstdio>


using namespace std;

void abs (double* a){
    if(*a < 0){
        *a = -(*a);
    }
}


int main(){
    int length = 0;
    double square[200][200] = {0};
    double inverse_square[200][200] = {0};
    double I[200][200] = {0};
    cin>>length;
    for(int i = 0 ; i < length ; i++){
        inverse_square[i][i] = 1;
        I[i][i] = 1;
    }

    double copy_square[200][200] = {0};

    for(int i = 0 ; i < length ; i++){
        for(int j = 0 ; j < length ; j++){
            cin>>square[i][j];
            copy_square[i][j] = square[i][j];
        }
    }



    for(int triangle = 0 ; triangle < length ; triangle++){
        for(int column = triangle + 1 ; column < length ; column++){
            // multiplier ­¼¼Æ
            double multiplier = square[column][triangle] / square[triangle][triangle];
            for(int row = 0 ; row < length ; row++){
                square[column][row] -= (square[triangle][row]*multiplier);
                inverse_square[column][row] -= (inverse_square[triangle][row]*multiplier);
            }
        }

    }
    //from up to down
    for(int triangle = length-1 ; triangle >= 0 ; triangle--){
        for(int column = triangle - 1 ; column >= 0 ; column--){
            // multiplier ­¼¼Æ
            double multiplier = square[column][triangle] / square[triangle][triangle];
            for(int row = length-1 ; row >= 0 ; row--){
                square[column][row] -= (square[triangle][row]*multiplier);
                inverse_square[column][row] -= (inverse_square[triangle][row]*multiplier);
            }
        }
    }

    for(int column = 0 ; column < length ; column++){
        double temp = square[column][column];
        for(int row = 0 ; row < length ; row++){
            square[column][row] /= temp;
            inverse_square[column][row] /= temp;
        }
    }

    double result[200][200] = {0};

    for(int i = 0 ; i < length ; i++){
        for(int j = 0 ; j < length ; j++){
            result[i][i] += (copy_square[i][j]*inverse_square[j][i]);
        }
    }

    double error = 0 , temp = 0;
    for(int i = 0 ; i < length ; i++){
        temp = result[i][i] - I[i][i];
        abs(&temp);
        if(temp >= error){
            error = temp;
        }
    }


    cout<<error<<endl;



    for(int i = 0 ; i < length ; i++){
        for(int j = 0 ; j < length ; j++){
            printf("%lf\t" , inverse_square[i][j]);
        }
        cout<<endl;
    }


    return 0;
}
