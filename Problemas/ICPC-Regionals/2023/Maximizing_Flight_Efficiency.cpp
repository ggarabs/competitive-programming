#include <bits/stdc++.h>
#define MAXN 107
#define INF 99999999

using namespace std;

int flight[MAXN][MAXN];
int dist[MAXN][MAXN];

int main(){
    int n, ans = 0;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> flight[i][j];
            dist[i][j] = flight[i][j];
        }
    }

    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
	            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(i != k && j != k && dist[i][j] == flight[i][j] && dist[i][j] == dist[i][k]+dist[k][j]){
                    ans++;
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dist[i][j] != flight[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}