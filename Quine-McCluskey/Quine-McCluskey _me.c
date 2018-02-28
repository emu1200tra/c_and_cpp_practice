#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;

int main(){
  int variable_num = 0 , m_num = 0 , d_num = 0;
  printf("enter variable_num:\n");
  scanf("%d" , &variable_num);
  printf("enter m_num:%d\n", m_num);
  scanf("%d" , &m_num);
  int *m = (int*)malloc(m_num*sizeof(int));
  for(int i = 0 ; i < m_num ; i++){
    printf("enter %d element of m:", i+1);
    scanf("%d" , &m[i]);
  }
  printf("enter d_num:\n");
  scanf("%d" , &d_num);
  int *d = (int*)malloc(d_num*sizeof(int));
  for(int i = 0 ; i < d_num ; i++){
    printf("enter %d element of d:", i+1);
    scanf("%d" , &d[i]);
  }
  all_mintern_num = m_num + d_num;
  int *all_mintern = (int*)malloc(all_mintern_num*sizeof(int));
  for()




  return 0;
}