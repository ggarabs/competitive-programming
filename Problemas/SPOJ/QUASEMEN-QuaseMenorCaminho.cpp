#include <bits/stdc++.h>
#define MAXN 507
#define pb push_back
#define INF 9999999

using namespace std;

int dist[2][MAXN], n, m;
vector <pair<pair <int, int>, bool> > graph[MAXN], aux_graph[MAXN];
bool vis[MAXN];

void Djikstra(int orig, vector <pair<pair <int, int>, bool> > grafo[], int mode){
    for(int i = 0; i < n; i++) dist[mode][i] = INF;
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > fila;
    dist[mode][orig] = 0;
    fila.push({dist[mode][orig], orig});

    while(true){
        int davez = -1;

        while(!fila.empty()){
            int atual = fila.top().second;
            fila.pop();
            if(!vis[atual]){
                davez = atual;
                break;
            }
        }

        if(davez == -1) break;

        vis[davez] = true;

        for(int i = 0; i < grafo[davez].size(); i++){
            int viz = grafo[davez][i].first.first;
            int w = grafo[davez][i].first.second;

            if(dist[mode][viz] > dist[mode][davez] + w && grafo[davez][i].second == false){
                dist[mode][viz] = dist[mode][davez] + w;
                fila.push({dist[mode][viz], viz});
            }
        }
    }
}

int main(){
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;

        int s, d;
        cin >> s >> d;

        for(int i = 0; i < m; i++){
            int u, v, p;
            cin >> u >> v >> p;

            graph[u].pb({{v, p}, false});
            aux_graph[v].pb({{u, p}, false});
        }

        memset(vis, 0, sizeof(vis));
        Djikstra(s, graph, 0);

        memset(vis, 0, sizeof(vis));
        Djikstra(d, aux_graph, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                int viz = graph[i][j].first.first;
                int w = graph[i][j].first.second;

                if(w + dist[0][i] + dist[1][viz] == dist[0][d]) graph[i][j].second = true;
            }
        }

        memset(vis, 0, sizeof(vis));
        Djikstra(s, graph, 0);

        if(dist[0][d] == INF) cout << -1 << endl;
        else cout << dist[0][d] << endl;

        for(int i = 0; i < n; i++){
            graph[i].clear();
            aux_graph[i].clear();
        }
    }

    return 0;
}