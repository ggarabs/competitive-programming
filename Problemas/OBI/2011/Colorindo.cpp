#include <bits/stdc++.h>
#define MAXN 207

using namespace std;

int livro[MAXN][MAXN], n, m, ans = 0;
int desl_x[] = {1, 0, -1, 1, -1, 1, 0, -1};
int desl_y[] = {1, 1, 1, 0, 0, -1, -1, -1};

bool in_mapa(int i, int j){
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void DFS(int x, int y){
    if(!in_mapa(x, y)) return;
    livro[x][y] = 1;
    ans++;
    for(int i = 0; i < 8; i++){
        int new_x = x + desl_x[i], new_y = y + desl_y[i];
        if(livro[new_x][new_y] == 0){
            DFS(new_x, new_y);
        }
    }
}

int main(){
    int x, y, k;
    cin >> n >> m >> x >> y >> k;

    memset(livro, 0, sizeof(livro));

    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        livro[x][y] = -1;
    }

    DFS(x, y);
    cout << ans << endl;

    return 0;
}