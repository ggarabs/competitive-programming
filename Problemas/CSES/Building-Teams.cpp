#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

vector <int> graph[MAXN];
int color[MAXN];

bool DFS(int x){
    bool ans = true;
    for(int i = 0; i < graph[x].size(); i++){
        if(color[graph[x][i]] == -1){
            color[graph[x][i]] = 1-color[x];
            ans &= DFS(graph[x][i]);
        }else{
            if(color[graph[x][i]] != 1-color[x]) return false;
        }
    }
    return ans;
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) color[i] = -1;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!DFS(i)){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << 1+color[i] << " ";
    cout << endl;

    return 0;
}