#include <stdio.h>
#include <vector>
using namespace std;

//c[i][j] = min(c[i-1][j], 1+c[j][j-d[i]]);
int min(int a, int b){
    return a < b ? a : b;
}
int dinamic(vector<int> d, int t){
    int x = d.size();
    int y = t+1;
    int c[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(i == 0 && j == 0)
                c[i][j] = 0;
            else if(i == 0 && j != 0)
                c[i][j] = 1+c[0][j-d[0]];
            else if(j < d[i])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = min(c[i-1][j], 1+c[i][j-d[i]]);
        }
    } 

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    } 

    return c[x-1][t];
}

int main(){
    int coin;
    vector<int> coins;
    printf("Informe o conjunto de moedas: ");
    scanf(" %d", &coin);
    
    while(coin != 0){
        coins.push_back(coin);
        scanf(" %d", &coin);
    }

    int change;
    printf("Informe o troco desejado: \n");
    scanf(" %d", &change);

    printf("Serão nescessárias %d moedas.\n", dinamic(coins, change));
}