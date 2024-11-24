#include <bits/stdc++.h>
#define MAXN 60
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

int n;
char** matriz;

bool in_map(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

int count_live_cells(char** matriz, int x, int y){
    int count = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            int new_x = x + i, new_y = y + j;
            if(in_map(new_x, new_y) && matriz[new_x][new_y] == '1') count++;
        }
    }
    return count;
}

char** next_state(char** matriz){
    char** aux = (char**)calloc(n, sizeof(char*));
    for(int i = 0; i < n; i++) aux[i] = (char*)calloc(n, sizeof(char));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int live_cells = count_live_cells(matriz, i, j);
            if(matriz[i][j] == '0'){
                if(live_cells == 3) aux[i][j] = '1';
                else aux[i][j] = '0';
            }else{
                if(live_cells >= 2 && live_cells <= 3) aux[i][j] = '1';
                else aux[i][j] = '0';
            }
        }
    }
    return aux;
}

int main(){ _
    int q; cin >> n >> q;

    char** matriz = (char**)calloc(n, sizeof(char*));
    for(int i = 0; i < n; i++) matriz[i] = (char*)calloc(n, sizeof(char));    

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> matriz[i][j];

    for(int i = 0; i < q; i++) matriz = next_state(matriz);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << matriz[i][j];
        cout << endl;
    }

    return 0;
}