#include <bits/stdc++.h>

const int MAXN = 1e5+7, INF = 1e9+7;

using namespace std;

vector <int> graph[MAXN][2];
int dist[MAXN][2][2];
int parent[MAXN], s[2];

void DFS(int x, bool mode, int d, int prt, bool extr){
    dist[x][mode][extr] = d;
    parent[x] = prt;

    for(auto ngbr : graph[x][mode]){
        if(ngbr != prt) DFS(ngbr, mode, d+1, x, extr);
    }
}

pair<int, int> get_diam(int mode){
    int size = s[mode];

    dist[1][mode][0] = 0;
    DFS(1, mode, 0, -1, 0);

    int maxv = -1, u;
    for(int i = 1; i <= size; i++){
        if(dist[i][mode][0] > maxv) maxv = dist[i][mode][0], u = i;
    }

    dist[u][mode][0] = 0;
    DFS(u, mode, 0, -1, 0);

    maxv = -1;
    int v;

    for(int i = 1; i <= size; i++){
        if(dist[i][mode][0] > maxv) maxv = dist[i][mode][0], v = i;
    }

    return {u, v};
}

int find_center(int u, int v, bool mode){
    DFS(u, mode, 0, -1, 0);
    DFS(v, mode, 0, -1, 1);

    int curr = u, minv = INF, center = u;

    while(curr != -1){
        if(max(dist[curr][mode][0], dist[curr][mode][1]) < minv){
            minv = max(dist[curr][mode][0], dist[curr][mode][1]);
            center = curr;
        }
        curr = parent[curr];
    }

    return center;
}

int main(){
    for(int i = 0; i < 2; i++) cin >> s[i];

    int centers[2];

    for(int j = 0; j < 2; j++){
        for(int i = 0; i < s[j]-1; i++){
            int a, b; cin >> a >> b;
            graph[a][j].push_back(b);
            graph[b][j].push_back(a);
        }
    
        pair <int, int> diam = get_diam(j);

        centers[j] = find_center(diam.first, diam.second, j);
    }

    cout << centers[0] << " " << centers[1] << endl;

    return 0;
}