#include <bits/stdc++.h>
#define MAXN 307
#define pb push_back
#define INF 15625007

using namespace std;

vector <pair <int, int>> graph[MAXN];
int dist[MAXN], n, c;
bool vis[MAXN];

void Djikstra(int orig){
    for(int i = 0; i < n; i++) dist[i] = INF;
    priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> fila;
    dist[orig] = 0;
    fila.push({dist[orig], orig});
    while(true){
        int aux = -1;

        while(!fila.empty()){
            int atual = fila.top().second;
            fila.pop();
            if(!vis[atual]){
                aux = atual;
                break;
            }
        }

        if(aux == -1) break;

        vis[aux] = true;

        bool service = aux < c;

        for(int i = 0; i < graph[aux].size(); i++){
            int viz = graph[aux][i].first;
            int w = graph[aux][i].second;

            if(service && viz != aux+1) continue;

            if(dist[viz] > dist[aux] + w){
                dist[viz] = dist[aux] + w;
                fila.push({dist[viz], viz});
            }
        }
    }
}

int main(){
    int m, k;
    while(cin >> n >> m >> c >> k){
        if(n == 0 && m == 0 && c == 0 && k == 0) break;

        for(int i = 0; i < n; i++){
            graph[i].clear();
            vis[i] = false;
        }

        for(int i = 0; i < m; i++){
            int u, v, p;
            cin >> u >> v >> p;
            graph[u].pb({v, p});
            graph[v].pb({u, p});
        }

        Djikstra(k);

        cout << endl << dist[c-1] << endl;
    }

    return 0;
}