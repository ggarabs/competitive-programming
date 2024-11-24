#include <bits/stdc++.h>
#define MAXN 200007
 
using namespace std;
 
vector <int> graph[MAXN], path;
bool vis[MAXN];

void DFS(int x, int parent){
    vis[x] = 1;
    for(int i = 0; i < graph[x].size(); i++){
        int ngbr = graph[x][i];
        if(vis[ngbr] == 1 && ngbr != parent){
            path.push_back(ngbr);
            int k = 0;
            while(path[k] != ngbr) k++;
            cout << (int)path.size() - k << endl;
            while(k < (int)path.size()) cout << path[k++] << " ";
            cout << endl;
            exit(0);
        }else if(!vis[ngbr]){
            path.push_back(ngbr);
            DFS(ngbr, x);
            path.pop_back();
        }
    }
}
 
int main(){
    int n, m; cin >> n >> m;
 
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            path.push_back(i);
            DFS(i, i);
        }
        path.clear();
    }
 
    cout << "IMPOSSIBLE" << endl;
 
    return 0;
}