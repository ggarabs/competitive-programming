#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+7, INF = 0x7fffffff;

char graph[MAXN][MAXN];

int main(){
    int n; cin >> n;

    vector <vector <int>> ans(n+1, vector<int>(n+1, INF));

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> graph[i][j];

    queue<pair<int, int>> q;

    for(int i = 1; i <= n; i++){
        q.push({i, i});
        ans[i][i] = 0;
    }

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
        if(i == j) continue;
        if(graph[i][j] != '-'){
            q.push({i, j});
            ans[i][j] = 1;
        }
    }

    while(!q.empty()){
        auto curr = q.front(); 
        q.pop();
        int first = curr.first, second = curr.second;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][first] != '-' && graph[second][j] != '-' && graph[i][first] == graph[second][j] && ans[i][j] == INF){
                    ans[i][j] = ans[first][second]+2;
                    q.push({i, j});
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << (ans[i][j] == INF ? -1 : ans[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;
}