#include <bits/stdc++.h>
#define MAXN 100007
#define pb push_back

using namespace std;

int n, dist[MAXN], vis[MAXN];
vector <int> tree[MAXN];

void BFS(int orig){
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));

    queue <int> q;
    q.push(orig);

    while(!q.empty()){
        int f = q.front();
        q.pop();

        vis[f] = 1;

        for(int i = 0; i < tree[f].size(); i++){
            int viz = tree[f][i];
            if(vis[viz] == 0){
                dist[viz] = dist[f] + 1;
                q.push(viz);
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;

        tree[u].pb(v);
        tree[v].pb(u);
    }

    BFS(1);

    int maior = -1, v = -1;

    for(int i = 1; i <= n; i++){
        if(dist[i] > maior){
            maior = dist[i];
            v = i;
        }
    }

    BFS(v);

    int diameter = -1, u = -1;

    for(int i = 1; i <= n; i++){
        if(dist[i] > diameter){
            diameter = dist[i];
            u = i;
        }
    }

    cout << diameter << endl;

    return 0;
}