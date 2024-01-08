#include <bits/stdc++.h>
#define MAXN 507
#define INF 999999999999999999

using namespace std;

long long int dist[MAXN][MAXN];

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dist[i][j] = INF;
    for(int i = 1; i <= n; i++) dist[i][i] = 0;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(w < dist[u][v]){
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
	            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        cout << (dist[u][v]==INF?-1:dist[u][v]) << endl;
    }

    return 0;
}