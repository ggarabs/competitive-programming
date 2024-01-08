#include <bits/stdc++.h>
#define MAXN 107
#define pb push_back

using namespace std;

struct edge{
    int u, v, w;  
};

int parent[MAXN], height[MAXN], dist[MAXN];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;

    if(height[u] > height[v]) parent[v] = u;
    else if(height[u] < height[v]) parent[u] = v;
    else{
        parent[u] = v;
        height[v]++;
    }
}

bool vis[MAXN];

vector <pair <int, int>> graph[MAXN];

bool comp(edge a, edge b){
    return a.w > b.w;
}

void dfs(int x){
    vis[x] = true;
    for(int i = 0; i < graph[x].size(); i++){
        if(!vis[graph[x][i].second]){
            if(dist[x] != 0) dist[graph[x][i].second] = min(dist[x], graph[x][i].first);
            else dist[graph[x][i].second] = graph[x][i].first;
            dfs(graph[x][i].second);
        }
    }
}

int main(){
    int n, r, it = 1;

    while(cin >> n >> r && n && r){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            height[i] = 1;
        }

        memset(dist, 0, sizeof(dist));
        memset(vis, 0, sizeof(vis));

        vector <edge> edges;

        for(int i = 1; i <= n; i++) graph[i].clear();

        for(int i = 0; i < r; i++){
            int c1, c2, p;
            cin >> c1 >> c2 >> p;

            edges.pb({c1, c2, p});
        }

        int origin, dest, pass;
        cin >> origin >> dest >> pass;

        sort(edges.begin(), edges.end(), comp);

        for(int i = 0; i < edges.size(); i++){
            if(find(edges[i].u) != find(edges[i].v)){
                merge(edges[i].u, edges[i].v);
                graph[edges[i].u].push_back({edges[i].w, edges[i].v});
                graph[edges[i].v].push_back({edges[i].w, edges[i].u});
            }
        }

        dfs(origin);

        cout << "Scenario #" << it << endl;
        cout << "Minimum Number of Trips = " << ceil(((double)pass)/(dist[dest]-1)) << endl;
        cout << endl;

        it++;

    }

    return 0;
}