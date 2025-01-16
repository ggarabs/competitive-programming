#include <bits/stdc++.h>
#define MAXN 12

using namespace std;

int vis[MAXN][MAXN];
int desl_x[4] = {-1, 1, 0, 0}, desl_y[4] = {0, 0, -1, 1};
int n, m;
pair <int, int> orig, dest;

bool in_grid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int DFS(int x, int y){
    if(make_pair(x, y) == dest){
        return 1;
    }
    vis[x][y] = true;
    int ans = 0;
    for(int i = 0; i < 4; i++){
        int new_x = x + desl_x[i], new_y = y + desl_y[i];
        if(!in_grid(new_x, new_y) || (new_x % 2 == 0 && new_y % 2 == 0)) continue;
        if(!vis[new_x][new_y]){
            vis[new_x][new_y] = true;
            ans = max(ans, 1 + DFS(new_x, new_y));
            vis[new_x][new_y] = false;
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    cin >> orig.first >> orig.second >> dest.first >> dest.second;

    cout << DFS(orig.first, orig.second) << endl;

    return 0;
}