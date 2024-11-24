#include <bits/stdc++.h>
#define MAXN 1007
#define INF 1000007

using namespace std;

char labyrinth[MAXN][MAXN];
int solution[MAXN][MAXN];

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
char dir[4] = {'L', 'R', 'D', 'U'};

void BFS(pair <int, int> beg){
    queue <pair <int, int>> q;
    q.push(beg);
    labyrinth[beg.first][beg.second] = 'V';
    while(!q.empty()){
        pair <int, int> curr = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int new_x = curr.first + dy[i], new_y = curr.second + dx[i];
            if(labyrinth[new_x][new_y] == '.' || labyrinth[new_x][new_y] == 'B'){
                solution[new_x][new_y] = min(solution[new_x][new_y], 1 + solution[curr.first][curr.second]);
                labyrinth[new_x][new_y] = 'V';
                q.push({new_x, new_y});
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;

    pair<int, int> begin, end;

    for(int i = 0; i <= n+1; i++) for(int j = 0; j <= m+1; j++) solution[i][j] = INF;

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        cin >> labyrinth[i][j];
        if(labyrinth[i][j] == 'A') begin = {i, j};
        else if(labyrinth[i][j] == 'B') end = {i, j};
    }

    solution[begin.first][begin.second] = 0;

    BFS(begin);

    if(solution[end.first][end.second] == INF){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl << solution[end.first][end.second] << endl;

    string ans = "";
    int cont = solution[end.first][end.second];
    pair <int, int> pos = end;

    while(cont--){
        for(int i = 0; i < 4; i++){
            pair<int, int> prev = {pos.first + dy[i], pos.second + dx[i]};
            if(solution[prev.first][prev.second] + 1 == solution[pos.first][pos.second]){
                ans += dir[i];
                pos = prev;
                break;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}