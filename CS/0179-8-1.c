#include <stdio.h>
#include <stdlib.h>
int lifeMartrix[42][42];
int lifeMartrix_T[42][42];
int n;
void init(){ //init
    int i;
    for(i = 0; i < 42; i++){
        lifeMartrix[0][i] = 0;
        lifeMartrix[41][i] = 0;
        lifeMartrix[i][0] = 0;
        lifeMartrix[i][41] = 0;
    }
    for(i = 1; i <= 40; i++){
        lifeMartrix[i][i] = 1;
        lifeMartrix[i][41-i] = 1;
    }
}
void printM(int lifeMartrix[42][42]){ //print out steps(all steps)
    int i, j;
    for(i = 1; i <= 40; i++){
            for(j = 1; j <= 40; j++){
                if(lifeMartrix[i][j] == 0)
                    printf("- ");
                else
                    printf("* ");
            }
            printf("\n");
        }
}
void evolution(int lifeMartrix[42][42], int n){ //main work
    int temp = n;
    printf("%d:\n",n - temp);
    printM(lifeMartrix);
    printf("\n");
    while(temp > 0){
        temp--;
        printf("%d:\n",n - temp);
        int i, j, cnt;
        for(i = 1; i <= 40; i++){
            for(j = 1; j <= 40; j++){
                cnt = lifeMartrix[i+1][j] + lifeMartrix[i+1][j+1] + lifeMartrix[i][j+1] +lifeMartrix[i-1][j+1] + lifeMartrix[i-1][j] + lifeMartrix[i-1][j-1] +lifeMartrix[i][j-1] + lifeMartrix[i+1][j-1];
                if(cnt < 2)
                    lifeMartrix_T[i][j]=0;
                else if(cnt == 3 && lifeMartrix[i][j] == 0)
                    lifeMartrix_T[i][j] = 1;
                else if(cnt > 3 && lifeMartrix[i][j] == 1)
                    lifeMartrix_T[i][j] = 0;
                else if((cnt == 2 || cnt == 3) && lifeMartrix[i][j] == 1)
                    lifeMartrix_T[i][j] = 1;
                else
                    lifeMartrix_T[i][j] = 0;
            }
        }
        for(i = 1; i <= 40; i++){
            for(j = 1; j <= 40; j++){
                lifeMartrix[i][j] = lifeMartrix_T[i][j];
            }
        }
        printM(lifeMartrix);
        printf("\n");
    }
    return ;
}

int main(){
    printf("Please enter the number of evolution of the life game:\n");
    scanf("%d",&n); //input
    init();
    evolution(lifeMartrix, n);
    return 0;
}