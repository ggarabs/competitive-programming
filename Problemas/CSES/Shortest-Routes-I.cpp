#include <bits/stdc++.h>
#include <queue>
#define ll long long int
#define pii pair<ll, int>

using namespace std;

const int MAXN = 2e5+7;
ll INF = 2e14+7;

vector <pair<ll, int>> graph[MAXN];
ll dist[MAXN];
bool vis[MAXN];

void Djikstra(int orig){
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    dist[orig] = 0;
    pq.push({0, orig});
    while(true){
        pii curr = {-1, -1};

        while(!pq.empty()){
            pii aux = pq.top();
            pq.pop();
            if(!vis[aux.second]){
                curr = aux;
                break;
            }
        }

        if(curr == (pii){-1, -1}) break;

        vis[curr.second] = true;

        for(int i = 0; i < graph[curr.second].size(); i++){
            pii aux = graph[curr.second][i];
            if(dist[aux.second] > dist[curr.second] + aux.first){
                dist[aux.second] = dist[curr.second] + aux.first;
                pq.push({dist[aux.second], aux.second});
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) dist[i] = INF;

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }

    Djikstra(1);

    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}