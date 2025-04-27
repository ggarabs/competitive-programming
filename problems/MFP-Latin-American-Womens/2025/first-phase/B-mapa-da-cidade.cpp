#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int MAXN = 1e5+7;

vector <int> graph[MAXN];
vector <pair<int, int>> edges, mst;
bool vis[MAXN];
int prt[MAXN];

int find(int x){
    if(prt[x] == x) return x;

    return prt[x] = find(prt[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    prt[x] = y;
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) prt[i] = i;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        edges.pb({u, v});
    }

    for(pair<int, int> &e : edges){
        if(find(e.first) != find(e.second)){
            mst.pb({e.first, e.second});
            join(e.first, e.second);
        }
    }

    set <int> comps;
    for(int i = 1; i <= n; i++){
        find(i);
        comps.insert(prt[i]);
    }

    if(comps.size() == 1 && mst.size() == m) cout << "BOM" << endl;
    else cout << "RUIM " << m-mst.size() << " " << comps.size()-1 << endl;

    return 0;
}