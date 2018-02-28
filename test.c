#include<stdio.h>
#include<stdlib.h>

void edge(int a[10][10],int x, int y){
     int b[x][y];
     int i=0,j=0;
     for(i=0 ; i<x ; i++){
         for(j=0 ; j<y ; j++){
             b[i][j]=a[i][j];
         }
     }
     i=1;j=1;
     for(i=1 ; i<x ; i++){
         for(j=1 ; j<y ; j++){
             if(a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1]==4){
                 b[i][j]=0;
             }
         }
     }
     i=1;j=1;
     for(i=1; i<x ; i++){
         for(j=1 ; j<y ; j++){
             a[i][j]=b[i][j];
        }
     }
}
int main(){
    int a[10][10];
    int x,y,i=0,j=0;
    printf("input rows,columns");
    scanf("%d",&x);
    scanf("%d",&y);
    printf("input 0 or 1\n");
    for(i=0 ; i<x ; i++){
        for(j=0 ; j<y ; j++){
            scanf("%d",&a[i][j]);
        }
    }
    i=0;j=0;
    printf("before--------------\n");
    for(i=0 ; i<x ; i++){
        for(j=0 ; j<y ; j++){
            printf("%d ",a[i][j]);
        }
    printf("\n");
    }
    printf("after----------------\n");
    edge(a,x,y);
    i=0;j=0;
    for(i=0 ; i<x ; i++){
        for(j=0 ; j<y ; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
