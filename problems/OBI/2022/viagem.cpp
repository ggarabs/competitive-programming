#include <bits/stdc++.h>
#define MAXN 10007
#define MAXV 207
#define INF 99999999
#define tri pair<pair<int, int>, int>
#define pb push_back

using namespace std;

vector <tri> graph[MAXN];
int timev[MAXN][MAXV], vis[MAXN][MAXV], n, v;

void Djikstra(int orig){
    for(int i = 1; i <= n; i++) for(int j = 0; j < MAXV; j++) timev[i][j] = INF;
    memset(timev[orig], 0, sizeof(timev[orig]));
    priority_queue <tri, vector <tri>, greater <tri>> pq;
    pq.push({{0, 0}, orig});

    while(true){
        int cur = -1, cost;

        while(!pq.empty()){
            cost = pq.top().first.second;
            int at = pq.top().second;
            pq.pop();
            if(!vis[at][cost]){
                cur = at;
                break;
            }
        }

        if(cur == -1) break;

        vis[cur][cost] = 1;

        for(int i = 0; i < graph[cur].size(); i++){
            int viz = graph[cur][i].second;
            int t = graph[cur][i].first.first;
            int c = graph[cur][i].first.second;

            if(cost+c <= v && timev[viz][cost+c] > timev[cur][cost] + t){
                timev[viz][cost+c] = timev[cur][cost] + t;
                pq.push({{timev[viz][cost+c], cost+c}, viz});
            }
        }
    }
}

int main(){
    int m;
    cin >> v >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, t, p;
        cin >> a >> b >> t >> p;

        graph[a].pb({{t, p}, b});
        graph[b].pb({{t, p}, a});
    }

    int x, y, ans = INF;
    cin >> x >> y;

    Djikstra(x);

    for(int i = 0; i <= v; i++) ans = min(ans, timev[y][i]);

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}