#include <bits/stdc++.h>
#define MAXN 207

using namespace std;

int graph[MAXN][MAXN], cont;
int h[MAXN], vis[MAXN];

void DFS(int x){
    vis[x] = 1;
    for(int i = 0; i < MAXN; i++){
        if(graph[x][i] == 1 && !vis[i] && h[x] > h[i]){
            cont++;
            DFS(i);
        }
    }
}

int main(){
    int s, t, p;
    cin >> s >> t >> p;

    for(int i = 1; i <= s; i++) cin >> h[i];

    for(int i = 0; i < t; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    DFS(p);
    cout << cont << endl;

    return 0;
}