#include <bits/stdc++.h>
#define MAXN 1007
#define MAXH 15
#define pb push_back

using namespace std;

vector <int> tree[MAXN];
int anc[MAXN][MAXH], vis[MAXN], prof[MAXN];

void DFS(int x){
    vis[x] = 1;
    for(int i = 0; i < (int)tree[x].size(); i++){
        int viz = tree[x][i];
        if(!vis[viz]){
            prof[viz] = prof[x]+1;
            DFS(viz);
        }
    }
}

void calc_anc(int x){
    for(int i = 1; i < MAXH; i++){
        for(int j = 1; j <= x; j++){
            if(prof[j] >= (1 << i)) anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
}

int lca(int u, int v){
    if(prof[u] < prof[v]) swap(u, v);

    for(int i = MAXH-1; i >= 0; i--){
        if(prof[u] - (1 << i) >= prof[v]) u = anc[u][i];
    }

    if(u == v) return u;

    for(int i = MAXH-1; i >= 0; i--){
        if(anc[u][i] != -1 && anc[u][i] != anc[v][i]){
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return anc[u][0];
}

int main(){
    int t, it;
    cin >> t;
    it = t;

    while(t--){
        int n;
        cin >> n;

        memset(anc, -1, sizeof(anc));
        memset(vis, 0, sizeof(vis));

        for(int i = 1; i <= n; i++){
            int m;
            cin >> m;

            for(int j = 0; j < m; j++){
                int k;
                cin >> k;

                tree[k].pb(i);
                tree[i].pb(k);
                anc[k][0] = i;
            }
        }

        prof[1] = 0;
        DFS(1);

        calc_anc(n);

        int q;
        cin >> q;

        cout << "Case " << it-t << ":" << endl;

        for(int i = 0; i < q; i++){
            int u, v;
            cin >> u >> v;

            cout << lca(u, v) << endl;
        }
        cout << endl;

        for(int i = 1; i <= n; i++) tree[i].clear();
    }

    return 0;
}