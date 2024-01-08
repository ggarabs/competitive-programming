#include <bits/stdc++.h>
#define MAXN 200007
#define pb push_back

using namespace std;

vector <int> tree[MAXN];
bool vis[MAXN];
int dist[MAXN], desc[MAXN], aux[MAXN], ext;

void BFS(int orig){
    memset(vis, 0, sizeof(vis));

    queue <int> fila;
    fila.push(orig);

    while(!fila.empty()){
        int cur = fila.front();
        fila.pop();

        vis[cur] = 1;

        for(int i = 0; i < tree[cur].size(); i++){
            if(tree[cur].size() == 1) ext = cur;
            int viz = tree[cur][i];
            if(!vis[viz]) fila.push(viz);
        }
    }
}

void DFS(int orig){
    vis[orig] = 1;
    for(int i = 0; i < tree[orig].size(); i++){
        int viz = tree[orig][i];
        if(!vis[viz]){
            DFS(viz);
            desc[orig] += desc[viz]+1;
            aux[orig] += aux[viz]+desc[viz]+1;
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    BFS(1);

    cout << ext << endl;

    memset(vis, 0, sizeof(vis));

    DFS(ext);

    for(int i = 1; i <= n; i++){
        dist[i] = aux[i];
        cout << dist[i] << " ";
    }
    cout << endl;

    BFS(ext);

    cout << ext << endl;

    memset(vis, 0, sizeof(vis));
    memset(desc, 0, sizeof(desc));
    memset(aux, 0, sizeof(aux));

    DFS(ext);

    for(int i = 1; i <= n; i++){
        dist[i] += aux[i];
        cout << aux[i] << " ";
    }

    cout << endl;

    return 0;
}