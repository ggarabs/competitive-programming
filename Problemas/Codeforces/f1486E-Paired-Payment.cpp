#include <bits/stdc++.h>
#define MAXN 100007
#define pb push_back
#define INF 999999999
#define tii tuple <int, int, int, int>

using namespace std;

vector <pair <int, int>> graph[MAXN];
int dist[MAXN], n, m;
bool vis[MAXN];

void Djikstra(int orig){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue <tii, vector <tii>, greater<tii>> fila;
    dist[orig] = 0;
    fila.push({dist[orig], 0, orig, 0});

    while(true){
        tii aux = {-1, -1, -1, -1};

        while(!fila.empty()){
            tii atual = fila.top();
            fila.pop();
            if(!vis[get<2>(atual)] || get<3>(atual)%2==1){
                aux = atual;
                break;
            }
        }

        if(get<2>(aux) == -1) break;

        if(get<3>(aux)%2 == 0) vis[get<2>(aux)] = true;

        for(int i = 0; i < graph[get<2>(aux)].size(); i++){
            int viz = graph[get<2>(aux)][i].first;
            int w = graph[get<2>(aux)][i].second;

            if(get<3>(aux)%2 == 0){
                fila.push({get<0>(aux), w, viz, get<3>(aux)+1});
            }else{
                if(dist[viz] > get<0>(aux) + pow((get<1>(aux)+w), 2)){
                    dist[viz] = get<0>(aux) + pow((get<1>(aux)+w), 2);
                    fila.push({dist[viz], 0, viz, get<3>(aux)+1});
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, p;
        cin >> u >> v >> p;
        graph[u].pb({v, p});
        graph[v].pb({u, p});
    }

    Djikstra(1);

    for(int i = 1; i <= n; i++) cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    cout << endl;

    return 0;
}