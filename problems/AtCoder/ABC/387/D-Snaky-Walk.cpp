#include <bits/stdc++.h>
#define MAXN 1007

const int INF = 1e6+7;

using namespace std;

pair<int, int> desl[2][2] = {{{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}}};

int dist[MAXN][MAXN][2];

int main(){
    int h, w; cin >> h >> w;

    vector<vector<char>> grid(h+2, vector<char>(w+2, 'x'));

    pair <int, int> beg, end;

    for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++){
        cin >> grid[i][j];
        if(grid[i][j] == 'S'){
            beg = {i, j};
            grid[i][j] = '.';
        }
        else if(grid[i][j] == 'G'){
            end = {i, j};
            grid[i][j] = '.';
        }
    }

    for(int i = 0; i <= h+1; i++) for(int j = 0; j <= w+1; j++) for(int k = 0; k < 2; k++) dist[i][j][k] = INF;

    queue <pair<pair<int, int>, int>> q;
    q.push({beg, 0});
    q.push({beg, 1});
    dist[beg.first][beg.second][0] = 0;
    dist[beg.first][beg.second][1] = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front().first;
        int mode = q.front().second;
        q.pop();

        for(int i = 0; i < 2; i++){
            pair<int, int> ngbr = {curr.first+desl[(mode+1)%2][i].first, curr.second+desl[(mode+1)%2][i].second};
            if(grid[ngbr.first][ngbr.second] == '.' && dist[ngbr.first][ngbr.second][(mode+1)%2] > dist[curr.first][curr.second][mode]+1){
                dist[ngbr.first][ngbr.second][(mode+1)%2] = dist[curr.first][curr.second][mode]+1;
                q.push({ngbr, (mode+1)%2});
            }
        }
    }

    int ans = min(dist[end.first][end.second][0], dist[end.first][end.second][1]);

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}