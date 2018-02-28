#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>map_k;
int remain = 0 , remain2 = 0;
int **PI_XY;
int **pot;
int pot_num = 0;

bool cmp(int i,int j){
    return (i<j);
}

void find_result(int remain_cpy){
  int n = remain_cpy;
  for(map_k[n] = 0 ; map_k[n] < remain2 ; map_k[n]++){
    if(PI_XY[remain-1-n][map_k[n]]){
      if(n > 0){
        remain_cpy = n;
        remain_cpy--;
        find_result(remain_cpy);
      }
      else if(n == 0){
        for(int i = 0 ; i < remain ; i++){
          pot[pot_num][i] = map_k[remain-i-1];
        }
        pot_num++;
      }
    }
  }
}


int main(){
  int variable_num = 0 , m_num = 0 , d_num = 0;
  cout<<"enter variable_num:"<<endl;
  cin>>variable_num;
  cout<<"enter m_num:"<<endl;;
  cin>>m_num;
  vector<int>m;
  for(int i = 0 ; i < m_num ; i++){
    int tmp;
    cout<<"enter "<< i+1 << "element of m:"<<endl;
    cin>>tmp;
    m.push_back(tmp);
  }
  cout<<"enter d_num:"<<endl;
  cin>>d_num;
  vector<int>d;
  for(int i = 0 ; i < d_num ; i++){
    int tmp;
    cout<<"enter "<< i+1 <<" element of d:"<<endl;
    cin>>tmp;
    d.push_back(tmp);
  }
  cout<<"check"<<endl;
  int all_mintern_num = m_num + d_num;
  vector<int>all_mintern;
  cout<<"check 0.1"<<endl;
  all_mintern.insert(all_mintern.end() , m.begin() , m.end());
  all_mintern.insert(all_mintern.end() , d.begin() , d.end());
  sort(all_mintern.begin() , all_mintern.end());
  cout<<"check 0.15"<<endl;
  int **mintern_bin = new int*[all_mintern_num];
  cout<<"check 0.2"<<endl;
  for(int i = 0 ; i < all_mintern_num ; i++){
    mintern_bin[i] = new int[variable_num + 4];
  }
  cout<<"check 0.3"<<endl;
  int div = 0;
  for(int i = 0 ; i < all_mintern_num ; i++){
    div = all_mintern[i];
    for(int j = variable_num-1 ; j >= 0 ; j--){
      mintern_bin[i][j] = div % 2;
      div = div / 2;
    }
  }
  cout<<"check 1"<<endl;
  for(int i = 0 ; i < all_mintern_num ; i++){
    int count = 0;
    for(int j = 0 ; j < variable_num-1 ; j++){
      if(mintern_bin[i][j] == 1){
        count++;
      }
    }
    mintern_bin[i][variable_num] = count;
    mintern_bin[i][variable_num+1] = 0;
    mintern_bin[i][variable_num+2] = all_mintern[i];
    mintern_bin[i][variable_num+3] = all_mintern[i];
  }

  int ****column = new int***[variable_num+1];
  for(int i = 0 ; i < variable_num + 1 ; i++){
    column[i] = new int**[variable_num+1-i];
  }
  cout<<"check 2"<<endl;
  for(int i = 0 ; i < variable_num + 1 ; i++){
    for(int j = 0 ; j < variable_num + 1 - i ; j++){
      int n = 1 , m = 1;
      for(int k = variable_num ; k >= variable_num - j - i + 1 ; k--){
        n *= k;
      }
      for(int k = j ; k >= 1 ; k--){
        m *= k;
      }
      column[i][j] = new int*[n/m];
      for(int k = 0 ; k < n/m ; k++){
        column[i][j][k] = NULL;
      }
    }
  }
  for(int i = 0 ; i < variable_num + 1 ; i++){
    int k = 0;
    for(int j = 0 ; j < all_mintern_num ; j++){
      if(mintern_bin[j][variable_num] == i){
        column[0][i][k++] = mintern_bin[j];
        //k++;
      }
    }
  }
  cout<<"check 3"<<endl;
  int ability = 1  , record = 0 , bool_record = 0;
  for(int i = 0 ; i < variable_num + 1 ; i++){
    if(ability != 0){
      ability = 0;
      for(int j = 0 ; j < variable_num - i ; j++){
        int place = 0 , p = 0 , m1 = 1 , n1 = 1;
        for(int k = variable_num ; k >= variable_num - j - i + 1 ; k--){
          n1 *= k;
        }
        for(int k = j ; k >= 1 ; k--){
          m1 *= k;
        }
        int k_bound = n1/m1;
        for(int k = 0 ; k < k_bound ; k++){
          cout<<"check loop"<<endl;
          if(column[i][j][k] != NULL){
            int m2 = 1;
            int n2 = 1;
            for(int l = variable_num ; l >= variable_num - j - i ; l--){
              n2 *= l;
            }
            for(int l = j + 1 ; l >= 1 ; l--){
              m2 *= l;
            }
            int l_bound = n2/m2;
            for(int l = 0 ; l < l_bound ; l++){
              if(column[i][j+1][l]!=NULL && column[i][j+1][l][variable_num+2+i] > column[i][j][k][variable_num+2+i] && (int)(floor(log(column[i][j+1][l][variable_num+2+i] - column[i][j][k][variable_num+2+i]) / log(2))) == (int)((log(column[i][j+1][l][variable_num+2+i]- column[i][j][k][variable_num+2+i])/log(2)))){
                bool_record = (-i);
                for(int m = 1 ; m <= i ; m++){
                  for(int n = 1 ; n <= i ; n++){
                    if(column[i][j+1][l][variable_num+1+m] == column[i][j][k][variable_num+1+n]){
                      bool_record++;
                    }
                  }
                }
                cout<<"check loop 1"<<endl;
                if(bool_record == 0){
                  ability = 1;
                  column[i][j][k][variable_num+1] = 1;
                  column[i][j+1][l][variable_num+1] = 1;
                  cout<<"check int new"<<endl;
                  column[i+1][j][p] = new int[(int)(variable_num+4+i+pow(2,i+1))];
                  //cout<<"new:"<<(variable_num+4+i+pow(2,i+1))<<endl;
                  cout<<"check inside loop"<<endl;
                  for(int m = 0 ; m <= variable_num+1+i ; m++){
                    //cout<<"fuck you:"<<column[i+1][j][p][m]<<endl;
                    //cout<<";"<<column[i][j][k][m]<<endl;

                    column[i+1][j][p][m] = column[i][j][k][m];
                  }
                  cout<<"check loop 2"<<endl;
                  column[i+1][j][p][variable_num+3+i] = column[i][j][k][variable_num+2+i];
                  for(int m = variable_num+4+i ; m < variable_num +4+i+pow(2 , i+1) ; m++){
                    //cout<<"check begin:"<<i+1<<";"<<j<<";"<<p<<";"<<m<<endl;
                    column[i+1][j][p][m] = 0;
                  }
                  //cout<<"check:"<<column[i+1][j][p][m]<<endl;
                  place = log((column[i][j+1][l][variable_num+2+i]-column[i][j][k][variable_num+2+i]))/log(2);
                  //cout<<"place:"<<place<<endl;
                  column[i+1][j][p][variable_num-1-place] = 2;
                  column[i+1][j][p][variable_num+1] = 0;
                  column[i+1][j][p][variable_num+2+i] = place;
                  cout<<"check loop 3"<<endl;
                  for(int n = 0 ; n < pow(2,i) ; n++){
                    column[i+1][j][p][variable_num+4+i+n] = column[i][j][k][variable_num + 3 + i + n];
                  }
                  for(int n = pow(2 , i) ; n < pow(2,i+1) ; n++){
                    column[i+1][j][p][variable_num+4+i+n] = column[i][j+1][l][(int)(variable_num+3+i+n-pow(2 , i))];
                  }
                  p++;
                  cout<<"check loop 4"<<endl;
                }
              }
            }
          }
        }
      }
    }
  }
  cout<<"check 4"<<endl;
  vector<int>counter;
  for(int i = 0 ; i < pow(2 , variable_num) ; i++){
    counter.push_back(0);
  }
  int **PI = new int*[all_mintern_num];
  int PI_num = 0;
  cout<<"all min num:"<<all_mintern_num<<endl;
  for(int i = 0 ; i < all_mintern_num ; i++){
    PI[i] = new int[3];
  }
  cout<<"check here"<<endl;
  for(int i = 0 ; i < variable_num+1 ; i++){
    for(int j = 0 ; j < variable_num+1-i ; j++){
      int m = 1 , n = 1;
      for(int k = variable_num ; k >= variable_num-j+1-i ; k--){
        m *= k;
      }
      for(int k = j ; k >= 1 ; k--){
        n *= k;
      }
      cout<<"check comb"<<endl;
      for(int k = 0 ; k < m/n ; k++){
        cout<<"check loop m/n"<<endl;
        if(column[i][j][k] != NULL && column[i][j][k][variable_num+1] == 0){
          bool_record = -(pow(2 , i));
          cout<<"check bool record"<<endl;
          for(int l = k-1 ; l >= 0 ; l--){
            if(bool_record != 0){
              bool_record = -(pow(2 , i));
              for(int p = 0 ; p < pow(2 , i) ; p++){
                for(int q = 0 ; q < pow(2 , i) ; q++){
                  cout<<"check column"<<endl;
                  if(column[i][j][l][variable_num+3+i+p] == column[i][j][k][variable_num+3+i+q]){
                    bool_record++;
                  }
                }
              }
            }
          }
          cout<<"check inside loop pi"<<endl;
          if(bool_record != 0){
            cout<<"check inside if:"<<PI_num<<endl;
            PI[PI_num][0] = i;
            PI[PI_num][1] = j;
            PI[PI_num][2] = k;
            PI_num++;
            cout<<"check pi here:"<<PI[PI_num][0]<<";"<<PI[PI_num][1]<<";"<<PI[PI_num][2]<<endl;
            for(int l = 0 ; l < pow(2 , i) ; l++){
              counter[column[i][j][k][variable_num+3+i+l]]++;
            }
          }
          cout<<"check end loop"<<endl;
        }
      }
    }
  }
  cout<<"check 5"<<endl;
  for(int i = 0 ; i < d_num ; i++){
    counter[d[i]] = 0;
  }
  int **ePI = new int*[all_mintern_num];
  int ePI_num = 0;
  for(int i = 0 ; i < pow(2 , variable_num) ; i++){
    if(counter[i] == 1){
      for(int j = 0 ; j < PI_num ; j++){
        for(int k = 0 ; k < pow(2 , PI[j][0]) ; k++){
          if(column[PI[j][0]][PI[j][1]][PI[j][2]][variable_num+3+PI[j][0]+k] == i){
            ePI[ePI_num] = PI[j];
            for(int l = 0 ; l < pow(2 , PI[j][0]) ; l++){
              counter[column[PI[j][0]][PI[j][1]][PI[j][2]][variable_num+3+PI[j][0]+l]] = 0;
            }
            ePI_num++;
            k = pow(2 , PI[j][0]);
          }
        }
      }
    }
  }
  cout<<"check 6"<<endl;
  for(int i = 0 ; i < pow(2 , variable_num) ; i++){
    if(counter[i] != 0){
      remain++;
    }
  }
  vector<int>PI_X;
  for(int i = 0 ; i < remain ; i++){
    PI_X.push_back(-1);
  }
  int **PI_Y = new int*[PI_num];
  for(int i = 0 ; i < PI_num ; i++){
    PI_Y[i] = NULL;
  }
  PI_XY = new int*[remain];
  int j = 0;
  for(int i = 0 ; i < pow(2 , variable_num) ; i++){
    if(counter[i] != 0){
      PI_X[j] = i;
      j++;
    }
  }
  int pepi = 1 , min = 0;
  vector<int>ppap;
  cout<<"check 7"<<endl;
  for(int i = 0 ; i < PI_num ; i++){
    for(int j = 0 ; j < pow(2 , PI[i][0]) ; j++){
      if(counter[column[PI[i][0]][PI[i][1]][PI[i][2]][variable_num+3+PI[i][0]+j]] != 0){
        j = pow(2 , PI[i][0]);
        PI_Y[remain2] = PI[i];
        remain2++;
      }
    }
  }
  if(remain2 != 0){
    for(int i = 0 ; i < remain ; i++){
      PI_XY[i] = new int[remain2];
    }
    for(int i = 0 ; i < remain ; i++){
      for(int j = 0 ; j < remain2 ; j++){
        PI_XY[i][j] = 0;
      }
    }
    for(int i = 0 ; i < remain2 ; i++){
      for(int j = 0 ; j < pow(2 , PI_Y[i][0]) ; j++){
        for(int k = 0 ; k < remain ; k++){
          if(column[PI_Y[i][0]][PI_Y[i][1]][PI_Y[i][2]][variable_num+3+PI_Y[i][0]+j] == PI_X[k]){
            PI_XY[k][i] = 1;
          }
        }
      }
    }
    cout<<"check 8"<<endl;
    for(int i = 0 ; i < remain ; i++){
      map_k.push_back(-1);
      pepi *= counter[PI_X[i]];
    }
    pot = new int*[pepi];
    for(int i = 0 ; i < pepi ; i++){
      pot[i] = new int[remain];
    }
    find_result(remain-1);
    for(int i = 0 ; i < pepi ; i++){
      ppap.push_back(0);
    }
    for(int i = 0 ; i < pepi ; i++){
      for(int j = 0 ; j < remain ; j++){
        if(pot[i][j] != -1){
          ppap[i]++;
          for(int k = j+1 ; k < remain ; k++){
            if(pot[i][k] == pot[i][j]){
              pot[i][k] = -1;
            }
          }
        }
      }
    }
    cout<<"check 9"<<endl;
    for(int i = 1 ; i < pepi ; i++){
      if(ppap[i] < ppap[min]){
        min = i;
      }
    }
    for(int i = 0 ; i < remain ; i++){
      if(pot[min][i] != -1){
        ePI[ePI_num++] = PI_Y[pot[min][i]];
        //ePI_num++;
      }
    }
    for(int i = 0 ; i < ePI_num ; i++){
      for(int j = 0 ; j < variable_num ; j++){
        if(column[ePI[i][0]][ePI[i][1]][ePI[i][2]][j] == 1){
          char tmp_out = 'A'+j;
          cout<<tmp_out;
        }
        else if(column[ePI[i][0]][ePI[i][1]][ePI[i][2]][j] == 0){
          char tmp_out = 'A'+j;
          cout<<tmp_out<<"'";
        }
      }
      if(i < ePI_num-1){
        cout<<"+";
      }
    }
    cout<<"check 10"<<endl;
    return 0;
  }
  else{
    cout<<"check 11"<<endl;
    for(int i = 0 ; i < ePI_num ; i++){
      for(int j = 0 ; j < variable_num ; j++){
        if(column[ePI[i][0]][ePI[i][1]][ePI[i][2]][j] == 1){
          char tmp_out = 'A'+j;
          cout<<tmp_out;
        }
        else if(column[ePI[i][0]][ePI[i][1]][ePI[i][2]][j] == 0){
          char tmp_out = 'A'+j;
          cout<<tmp_out<<"'";
        }
      }
      if(i < ePI_num-1){
        cout<<"+";
      }
    }
    cout<<"check 12"<<endl;
    return 0;
  }
  return 0;
}
