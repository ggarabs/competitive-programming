#include <bits/stdc++.h>
#define MAXN 10007
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
vector <pii> graph[MAXN];
int dist[MAXN];
bool vis[MAXN];

void DFS(int orig){
    vis[orig] = 1;
    for(int i = 0; i < graph[orig].size(); i++){
        if(!vis[graph[orig][i].second]){
            dist[graph[orig][i].second] = dist[orig] + graph[orig][i].first;
            DFS(graph[orig][i].second);
        }
    }
}

int main(){
    int n, a, b; cin >> n >> a >> b;

    for(int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        graph[u].pb({w, v});
        graph[v].pb({w, u});
    }

    dist[a] = 0;
    DFS(a);

    cout << dist[b] << endl;

    return 0;
}