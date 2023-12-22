#include <bits/stdc++.h>
#define MAXN 100007
#define INF 200000000000007
#define pb push_back
#define pii pair <long long int, int>

using namespace std;

vector <pair <int, int>> graph[2][MAXN];
vector <pair <int, pair <int, int>>> edges;
int n;
long long int dist[2][MAXN], ans[MAXN];
bool vis[MAXN];

void Djikstra(int orig, int x){
    for(int i = 1; i <= n; i++) dist[x][i] = INF;
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    dist[x][orig] = 0;
    pq.push({dist[x][orig], orig});
    while(true){
        int davez = -1;

        while(!pq.empty()){
            int atual = pq.top().second;
            pq.pop();
            if(!vis[atual]){
                davez = atual;
                break;
            }
        }

        if(davez == -1) break;

        vis[davez] = true;

        for(int i = 0; i < (int)graph[x][davez].size(); i++){
            int viz = graph[x][davez][i].second;
            int w = graph[x][davez][i].first;

            if(dist[x][viz] > dist[x][davez] + w){
                dist[x][viz] = dist[x][davez] + w;
                pq.push({dist[x][viz], viz});
            }
        }
    }
}

int main(){
    int m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[0][a].pb({c, b});
        graph[1][b].pb({c, a});
        edges.push_back({c, {a, b}});
    }

    Djikstra(1, 0);
    memset(vis, 0, sizeof(vis));
    Djikstra(n, 1);

    long long ans = INF;

    for(int i = 0; i < (int)edges.size(); i++){
        ans = min(ans, dist[0][edges[i].second.first]+dist[1][edges[i].second.second]+edges[i].first/2);
    }

    cout << ans << endl;

    return 0;
}