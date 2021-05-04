#include<stdio.h>
#include<stdlib.h>
#define M 10
#define N 10

int explorar (int A[][N], int i,int j){
int flag = 5;

if(i < 0 || j < 0) return 0;
if(i >= M || j >= N ) return 0 ;
if(i == 9  && j == 9) {
printf("Chegou no lugar!!!\n");
printf("%d %d -->\n",i,j);
return 1;
}
if(A[i][j] == 1) return 0;


               if(A[i][j] == 0){
               A[i][j] = 5;

                if(explorar(A,i+1,j)){
                printf("%d %d -->\n",i,j);
                return 1;

                }
            
                else if (explorar(A, i - 1,j)){
                printf("%d %d -->\n",i,j);
                return 1;
                }

                else if(explorar(A,i,j+1)){
                printf("%d %d -->\n",i,j);
                return 1;
                }
                else if(explorar(A, i , j - 1)){
                printf("%d %d -->\n",i,j);
                return 1;
                }
              
             }
   return 0;

   
}



void main (){




int m[10][10]= {{0,1,0,0,0,0,0,0,0,0}, // labirinto sem solução
                {1,1,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,1,1},
                {0,0,0,0,0,0,0,0,0,0}};
explorar(m,0,0);

 int x = explorar(m,0,0);
 if(x == 0){
    printf("caminho não encontrado");
 }
 


int n[10][10]= {{0,1,0,0,0,0,0,0,0,0}, // labirinto sem solução
                {1,1,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0,0,0,0}};

//explorar(n,0,0);


int p[10][10]= {{0,1,0,0,0,0,0,0,0,0}, // labirinto com solução
                {0,1,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0,0,0,0}};

//explorar(p,0,0);



}

