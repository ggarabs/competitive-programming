#include <bits/stdc++.h>
#define MAXN 507
#define INF 250007

using namespace std;

int l, c, patio[MAXN][MAXN];
int saltos[MAXN][MAXN];

bool esta_dentro(int x, int y){
    return x >= 1 && x <= l && y >= 1 && y <= c;
}

void BFS(){
    queue <pair <int, int>> fila;
    fila.push({1, 1});

    while(!fila.empty()){
        int x = fila.front().first, y = fila.front().second;
        fila.pop();

        for(int i = x-2; i <= x+2; i++){
            for(int j = y-2; j <= y+2; j++){
                if(esta_dentro(i,j) && patio[i][j] == 1 && saltos[i][j] > 1 + saltos[x][y]){
                    saltos[i][j] = 1 + saltos[x][y];
                    fila.push({i, j});
                }
            }
        }

    }
}

int main(){
    cin >> l >> c;

    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= c; j++){
            cin >> patio[i][j];
            saltos[i][j] = INF;
        }
    }

    saltos[1][1] = 0;
    BFS();

    cout << (saltos[l][c] == INF ? -1 : saltos[l][c]) << endl;

    return 0;
}