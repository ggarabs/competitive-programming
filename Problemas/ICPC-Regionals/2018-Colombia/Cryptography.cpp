#include <bits/stdc++.h>
#define MAXN 150
#define INF 199999999

using namespace std;

int dist[MAXN][MAXN];

int main(){
    string original, encrypted;
    cin >> original >> encrypted;

    int m;
    cin >> m;

    for(int i = 33; i <= 126; i++) for(int j = 33; j <= 126; j++) dist[i-33][j-33] = INF;
    for(int i = 33; i <= 126; i++) dist[i-33][i-33] = 0;

    for(int i = 0; i < m; i++){
        char u, v;
        int w;
        cin >> u >> v >> w;
        if(w < dist[u-33][v-33]){
            dist[u-33][v-33] = w;
        }
    }

    for(int i = 33; i <= 126; i++){
        for(int j = 33; j <= 126; j++){
            for(int k = 33; k <= 126; k++){
                dist[j-33][k-33] = min(dist[j-33][k-33], dist[j-33][i-33]+dist[i-33][k-33]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < original.size(); i++){
        if(dist[original[i]-33][encrypted[i]-33] == INF){
            cout << -1 << endl;
            return 0;
        }
        ans += dist[original[i]-33][encrypted[i]-33];
    }

    cout << ans << endl;

    return 0;
}