#include <stdio.h>
#include <vector>

using namespace std;

//c[i][j] = min(c[i-1][j], 1+c[j][j-d[i]]);
int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}
int dinamic(vector< pair<int, int> > d, int t){
    int x = d.size();
    int y = t+1;
    int c[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(i == 0 && j == 0)
                c[i][j] = 0;
            else if(i == 0 && j != 0)
                c[i][j] = d[i].second;
            else if(j < d[i].first)
                c[i][j] = c[i-1][j];
            else
                c[i][j] = max(c[i-1][j], c[i-1][j-d[i].first] + d[i].second);
        }
    } 

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    } 

    return c[x-1][t];
}

int main(){
    vector< pair<int, int> >objetos;
    int a = -1, b = -1;
    while(a != 0 && b != 0){
        scanf("%d %d", &a, &b);
        objetos.push_back(make_pair(a, b));
    }
        
    int cap;
    scanf(" %d", &cap);
    
    printf("Resultado = %d\n", dinamic(objetos, cap));
}