#include <bits/stdc++.h>
#define MAXN 107
#define INF 1000000007
#define pii pair<int, pair<int, int>>

using namespace std;

int l, c, k;
int graph[MAXN][MAXN], time_v[MAXN][MAXN], vis[MAXN][MAXN];
int desl_x[] = {-1, 1, 0, 0}, desl_y[] = {0, 0, -1, 1};

int in_tab(int x, int y){
    return x >= 1 && x <= l && y >= 1 && y <= c;
}

void Djikstra(int x_orig, int y_orig){
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    time_v[1][1] = 0;
    pq.push({0, {1, 1}});

    while(true){
        pair <int, int> cur = {-1, -1};

        while(!pq.empty()){
            pair <int, int> atual = pq.top().second;
            pq.pop();
            if(!vis[atual.first][atual.second]){
                cur = atual;
                break;
            }
        }

        if(cur == (pair<int, int>){-1,-1}) break;

        vis[cur.first][cur.second] = 1;

        for(int i = 0; i < 4; i++){
            int new_x = cur.first + desl_x[i], new_y = cur.second + desl_y[i];
            if(!in_tab(new_x, new_y)) continue;

            int var = (k+graph[new_x][new_y]-time_v[cur.first][cur.second]%k)%k;
            if(var == 0) var = k;

            if(graph[new_x][new_y] == -1) var = 1;
            else if(graph[cur.first][cur.second] != -1 && graph[new_x][new_y] != (graph[cur.first][cur.second]+1)%k) continue;

            if(time_v[new_x][new_y] > time_v[cur.first][cur.second] + var){
                time_v[new_x][new_y] = time_v[cur.first][cur.second] + var;
                pq.push({time_v[new_x][new_y], {new_x, new_y}});
            }
        }
    }
}

int main(){
    cin >> l >> c >> k;

    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= c; j++){
            cin >> graph[i][j];
            time_v[i][j] = INF;
        }
    }

    Djikstra(1, 1);

    if(time_v[l][c] == INF) cout << -1;
    else cout << time_v[l][c];

    cout << endl;

    return 0;
}