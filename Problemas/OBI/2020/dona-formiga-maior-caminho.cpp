#include <bits/stdc++.h>
#define MAXN 207

using namespace std;

int graph[MAXN][MAXN], ans;
int h[MAXN], nivel[MAXN];

void DFS(int x){
    for(int i = 0; i < MAXN; i++){
        if(graph[x][i] == 1 && h[x] > h[i] && nivel[x] + 1 > nivel[i]){
            nivel[i] = nivel[x] + 1;
            ans = max(ans, nivel[i]);
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
    cout << ans << endl;

    return 0;
}