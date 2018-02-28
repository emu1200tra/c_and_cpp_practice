#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int s1[7+1] = {0, 2, 5, 7, 9, 3, 1, 2};
int s2[5+1] = {0, 3, 5, 3, 2, 8};


int array[7+1][5+1] = {{0} , {0}};

void LCS()
{


    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= 5; j++)
            if (s1[i] == s2[j])
                // �o�̥[�W�� 1 �O�� e1 �����׬� 1
                array[i][j] = array[i-1][j-1] + 1;
            else
                array[i][j] = max(array[i-1][j], array[i][j-1]);

    cout << "LCS �����׬O" << array[7][5];
}




int main(){
    LCS();
    return 0;
}
