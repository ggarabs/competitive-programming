#include <bits/stdc++.h>
#define MAXN 100007
#define INF 5000000007

using namespace std;

vector <int> graph[MAXN];
long long int dist[MAXN];
bool vis[MAXN];

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) dist[i] = INF;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue <int> q;
    q.push(1);
    dist[1] = 1;
    vis[1] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i < graph[curr].size(); i++){
            int ngbr = graph[curr][i];
            if(vis[ngbr]) continue;
            dist[ngbr] = min(dist[ngbr], dist[curr]+1);
            q.push(ngbr);
            vis[ngbr] = true;
        }
    }

    if(dist[n] == INF){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector <int> ans;
    int curr = n;

    ans.push_back(curr);

    while(curr != 1){
        for(int i = 0; i < graph[curr].size(); i++){
            if(dist[graph[curr][i]] == dist[curr]-1){
                curr = graph[curr][i];
                ans.push_back(curr);
                break;
            }
        }
    }

    cout << dist[n] << endl;

    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
    cout << endl;

    return 0;
}