#include <bits/stdc++.h>
#define MAXN 100007
#define INF 200000000000007
#define pb push_back
#define pii pair <pair <long long int, int>, bool>

using namespace std;

vector <pair <int, int>> graph[MAXN];

int n;
long long int dist[MAXN][2];
bool vis[MAXN][2];

void Djikstra(int orig){
    for(int i = 1; i <= n; i++) dist[i][0] = dist[i][1] = INF;

    priority_queue <pii, vector <pii>, greater <pii>> pq;
    dist[orig][0] = dist[orig][1] = 0;

    pq.push({{0, orig}, 0});
    pq.push({{0, orig}, 1});

    while(true){
        int davez = -1, stt;

        while(!pq.empty()){
            int atual = pq.top().first.second;
            stt = pq.top().second;
            pq.pop();
            if(!vis[atual][stt]){
                davez = atual;
                break;
            }
        }

        if(davez == -1) break;

        vis[davez][stt] = true;

        for(int i = 0; i < (int)graph[davez].size(); i++){
            int viz = graph[davez][i].second;
            int w = graph[davez][i].first;

            if(dist[viz][stt] > dist[davez][stt] + w){
                dist[viz][stt] = dist[davez][stt] + w;
                pq.push({{dist[viz][stt], viz}, stt});
            }
            if(!stt && dist[viz][1] > dist[davez][0] + w/2){
                dist[viz][1] = dist[davez][0] + w/2;
                pq.push({{dist[viz][1], viz}, true});
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
        graph[a].pb({c, b});
    }

    Djikstra(1);

    cout << dist[n][1] << endl;

    return 0;
}
