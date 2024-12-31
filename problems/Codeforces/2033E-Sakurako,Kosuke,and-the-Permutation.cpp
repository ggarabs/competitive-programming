#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+7;

int DFS(int x, vector<int> &g, vector<bool> &vis){
    if(vis[x] || g[x] == -1) return 0;
    vis[x] = 1;
    return 1 + DFS(g[x], g, vis);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> graph(n+1, -1);
        vector <bool> vis(n+1, 0);
        for(int i = 1; i <= n; i++){
            int aux; cin >> aux;
            if(aux != i) graph[aux] = i;
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                int cycle_len = DFS(i, graph, vis);
                ans += (cycle_len - 1)/2;
            }
        }
        
        cout << ans << endl;

    }
    return 0;
}