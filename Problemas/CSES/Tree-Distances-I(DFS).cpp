#include <bits/stdc++.h>
#define pb push_back

const int MAXN = 2e5+7;

using namespace std;

vector <int> tree[MAXN];
int main_leafs[2] = {-1, -1}, dist[MAXN][2], maxdist;
bool vis[MAXN];

void DFS(int x, int mode){
    vis[x] = 1;
    for(int i = 0; i < (int)tree[x].size(); i++){
        int ngbr = tree[x][i];
        if(!vis[ngbr]){
            dist[ngbr][mode] = dist[x][mode] + 1;
            if(dist[ngbr][mode] > maxdist){
                main_leafs[mode] = ngbr;
                maxdist = dist[ngbr][mode];
            }
            DFS(ngbr, mode);
        }
    }
}

int main(){
    int n; cin >> n;

    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;

        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS(1, 0);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) dist[i][0] = 0;
    maxdist = 0;

    DFS(main_leafs[0], 1);
    memset(vis, 0, sizeof(vis));
    maxdist = 0;

    DFS(main_leafs[1], 0);

    for(int i = 1; i <= n; i++) cout << max(dist[i][0], dist[i][1]) << " ";
    cout << endl;

    return 0;
}