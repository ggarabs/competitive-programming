#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

char building_map[MAXN][MAXN];

int desl_x[4] = {-1, 1, 0, 0}, desl_y[4] = {0, 0, -1, 1};

void visit_room(int x, int y){
    queue <pair <int, int>> q;
    building_map[x][y] = 'R';
    q.push({x, y});
    while(!q.empty()){
        pair <int, int> aux = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int new_x = aux.first + desl_x[i], new_y = aux.second + desl_y[i];
            if(building_map[new_x][new_y] == '.'){
                building_map[new_x][new_y] = 'R';
                q.push({new_x, new_y});
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> building_map[i][j];

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(building_map[i][j] == '.'){
                visit_room(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}