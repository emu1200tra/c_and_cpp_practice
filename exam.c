#include <stdio.h>
#include <stdlib.h>

int counter[100][100] = {{0} , {0}};
int notfirst = 0;

void game(int array[100][100] , int bian , int place[2]){
    int livedied[100][100];

    int a = 0 , b = 0;
    for(a = 0 ; a < bian ; a++){
        for(b = 0 ; b < bian ; b++){
            livedied[a][b] = array[a][b];
        }
    }
    b = 0;
    if(notfirst == 0){
        for(a = 0 ; a < bian ; a++){
            for(b = 0 ; b < bian ; b++){
                if(array[a][b] == 1){
                    counter[a][b]++;

                }
            }
        }
        notfirst++;
    }

    for(a = 0 ; a < bian ; a++){
        if(a == 0){
            if(array[0][0] == 1 && ((array[1][0]+array[1][1] + array[0][1] < 2) || (array[1][0]+array[1][1] + array[0][1] > 3))){
                livedied[0][0] = 0;
            }
            else if(array[0][0] == 0 && array[1][0]+array[1][1] + array[0][1] == 3){
                livedied[0][0] = 1;

            }
            else if(array[0][0] == 1 && livedied[0][0] == 1){
                counter[0][0]++;
            }
            if(array[0][bian-1] == 1 && ((array[0][bian-2]+array[1][bian-2] + array[1][bian-1] < 2) || (array[0][bian-2]+array[1][bian-2] + array[1][bian-1] > 3))){
                livedied[0][bian-1] = 0;
            }
            else if(array[0][bian-1] == 0 && array[0][bian-2]+array[1][bian-2] + array[1][bian-1] == 3){
                livedied[0][bian-1] = 1;

            }
            else if(array[0][bian-1] == 1 && livedied[0][bian-1] == 1){
                counter[0][bian-1]++;
            }
        }
        if(a == bian - 1){
            if(array[a][0] == 1 && ((array[a-1][0]+array[a-1][1] + array[a][1] < 2) || (array[a-1][0]+array[a-1][1] + array[a][1] > 3))){
                livedied[a][0] = 0;
            }
            else if(array[a][0] == 0 && array[a-1][0]+array[a-1][1] + array[a][1] == 3){
                livedied[a][0] = 1;

            }
            else if(array[a][0] == 1 && livedied[a][0] == 1){
                counter[a][0]++;
            }
            if(array[a][bian-1] == 1 && ((array[a-1][bian-1]+array[a-1][bian-2] + array[a][bian-2] < 2) || (array[a-1][bian-1]+array[a-1][bian-2] + array[a][bian-2] > 3))){
                livedied[a][bian-1] = 0;
            }
            else if(array[a][bian-1] == 0 && array[a-1][bian-1]+array[a-1][bian-2] + array[a][bian-2] == 3){
                livedied[a][bian-1] = 1;

            }
            else if(array[a][bian-1] == 1 && livedied[a][bian-1] == 1){
                counter[a][bian-1]++;
            }
        }
        if(a != 0 && a != bian -1 && array[a][0] == 1 && ((array[a-1][0]+array[a-1][1] + array[a][1] + array[a+1][0] + array[a+1][1] < 2) || (array[a-1][0]+array[a-1][1] + array[a][1] + array[a+1][0] + array[a+1][1] > 3))){
                livedied[a][0] = 0;
            }
        else if(a != 0 && a != bian -1 && array[a][0] == 0 && array[a-1][0]+array[a-1][1] + array[a][1] + array[a+1][0] + array[a+1][1] == 3){
                livedied[a][0] = 1;

        }
        else if(array[a][0] == 1 && livedied[a][0] == 1){
            counter[a][0]++;
        }
        if(a != 0 && a != bian -1 && array[0][a] == 1 && ((array[0][a-1]+array[1][a-1] + array[1][a] + array[1][a+1] + array[0][a+1] < 2) || (array[0][a-1]+array[1][a-1] + array[1][a] + array[1][a+1] + array[0][a+1] > 3))){
                livedied[0][a] = 0;
            }
        else if(a != 0 && a != bian -1 && array[0][a] == 0 && array[0][a-1]+array[1][a-1] + array[1][a] + array[1][a+1] + array[0][a+1] == 3){
                livedied[0][a] = 1;

        }
        else if(array[0][a] == 1 && livedied[0][a] == 1){
            counter[0][a]++;
        }
        if(a != 0 && a != bian -1 && array[a][bian-1] == 1 && ((array[a-1][bian-1]+array[a-1][bian-2] + array[a][bian-2] + array[a+1][bian-2] + array[a+1][bian-1] < 2) || (array[a-1][bian-1]+array[a-1][bian-2] + array[a][bian-2] + array[a+1][bian-2] + array[a+1][bian-1] > 3))){
                livedied[a][bian-1] = 0;
            }
        else if(a != 0 && a != bian -1 && array[a][bian -1] == 0 && array[a-1][bian-1]+array[a-1][bian-2] + array[a][bian-2] + array[a+1][bian-2] + array[a+1][bian-1] == 3){
                livedied[a][bian-1] = 1;

        }
        else if(array[a][bian-1] == 1 && livedied[a][bian-1] == 1){
            counter[a][bian-1]++;
        }
        if(a != 0 && a != bian -1 && array[bian-1][a] == 1 && ((array[bian-1][a-1]+array[bian-2][a-1] + array[bian-2][a] + array[bian-2][a+1] + array[bian-1][a+1] < 2) || (array[bian-1][a-1]+array[bian-2][a-1] + array[bian-2][a] + array[bian-2][a+1] + array[bian-1][a+1] > 3))){
                livedied[bian-1][a] = 0;
            }
        else if(a != 0 && a != bian -1 && array[bian-1][a] == 0 && array[bian-1][a-1]+array[bian-2][a-1] + array[bian-2][a] + array[bian-2][a+1] + array[bian-1][a+1] == 3){
                livedied[bian-1][a] = 1;

        }
        else if(array[bian-1][a] == 1 && livedied[bian-1][a] == 1){
            counter[bian-1][a]++;
        }
    }
   for(a = 0 ; a < bian ; a++){
        for(b = 0 ; b < bian ; b++){
           if(a != 0 && a != bian -1 && b != 0 && b != bian-1 && array[a][b] == 1 && ((array[a-1][b]+array[a-1][b-1] + array[a-1][b+1] + array[a][b-1] + array[a][b+1] + array[a+1][b-1] + array[a+1][b] + array[a+1][b+1] < 2) || (array[a-1][b]+array[a-1][b-1] + array[a-1][b+1] + array[a][b-1] + array[a][b+1] + array[a+1][b-1] + array[a+1][b] + array[a+1][b+1] > 3))){
                livedied[a][b] = 0;
            }
            else if(a != 0 && a != bian -1 && b != 0 && b != bian-1 && array[a][b] == 0 && array[a-1][b]+array[a-1][b-1] + array[a-1][b+1] + array[a][b-1] + array[a][b+1] + array[a+1][b-1] + array[a+1][b] + array[a+1][b+1] == 3){
                livedied[a][b] = 1;

            }
            else if(a != 0 && a != bian -1 && b != 0 && b != bian-1 && array[a][b] == 1 && livedied[a][b] == 1){
                counter[a][b]++;
            }
        }
    }
    for(a = 0 ; a < bian ; a++){
        for(b = 0 ; b < bian ; b++){
            array[a][b] = livedied[a][b];
        }
    }
    int max = 0 , sign = 0;

    for(a = 0 ; a < bian ; a++){
        for(b = 0 ; b < bian ; b++){
            if(max < counter[a][b] && sign == 0 && array[a][b] != 0){
                max = counter[a][b];
                sign++;
                place[0] = a;
                place[1] = b;
            }
            else if(max <= counter[a][b] && sign != 0 && array[a][b] != 0){
                max = counter[a][b];
                if(place[0] < a){
                    place[0] = a;
                    place[1] = b;
                }
                else if(place[0] == a && place[1] < b){
                    place[0] = a;
                    place[1] = b;
                }
            }

        }
    }


}



int main()
{
    int bian = 0 , step = 0;
    scanf("%d%d" , &bian , &step);
    int array[100][100] = {{0} , {0}};
    int a , b;
    for(a = 0 ; a < bian ; a++){
        for(b = 0 ; b < bian ; b++){
            scanf("%d" , &array[a][b]);
        }
    }
    int c;
    int result[2] = {0};
    //step = 0 will WA.
    if(step == 0){
        int sign = 0;

        for(a = 0 ; a < bian ; a++){
            for(b = 0 ; b < bian ; b++){
                if(array[a][b] != 0 && sign == 0){
                    sign++;
                    result[0] = a;
                    result[1] = b;
                }
                else if(array[a][b] != 0 && sign != 0){
                    if(result[0] < a){
                        result[0] = a;
                        result[1] = b;
                    }
                    else if(result[0] == a && result[1] < b){
                        result[0] = a;
                        result[1] = b;
                    }
                }

            }
        }

    }
    else{
        for(c = 0 ; c < step ; c++){
            game(array , bian , result);
        }
    }
    for(c = 0 ; c < bian ; c++){
        for(a = 0 ; a < bian ; a++){
            if(a % 4 != 0 || a == 0){
                printf("%d " , array[c][a]);
            }
            else{

                printf("%d" , array[c][a]);
                printf("\n");
            }
        }

    }
    printf("%d %d" , result[0] + 1 , result[1] + 1);

    return 0;
}
