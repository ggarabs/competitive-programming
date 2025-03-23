#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int MAXN = 17;

lli mtx[MAXN][MAXN], ans = 0x7fffffffffffffff;
int n, m;
bool vis[MAXN];

lli DFS(int x, lli value){
    if(x == n) return value;
    vis[x] = true;
    for(int i = 1; i <= n; i++){
        if(x == i || mtx[i][x] == -1 || vis[i]) continue;
        vis[i] = true;
        if(i == 1){
            ans = mtx[i][x];
            ans = min(ans, DFS(i, mtx[i][x]));
        }else ans = min(ans, DFS(i, value^mtx[i][x]));
        vis[i] = false;
    }
    return ans;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) mtx[i][j] = -1;

    for(int i = 0; i < m; i++){
        int u, v; lli w; cin >> u >> v >> w;
        mtx[u][v] = w;
        mtx[v][u] = w;
    }

    cout << DFS(1, 0) << endl;
    
    return 0;
}