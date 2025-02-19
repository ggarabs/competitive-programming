#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        vector <vector <int>> mtx(n, vector<int>(m, 0));

        vector <int> cost(n*m+1, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mtx[i][j];
                if(cost[mtx[i][j]] == 0) cost[mtx[i][j]] = 1;
                if(i > 0 && mtx[i-1][j] == mtx[i][j]) cost[mtx[i][j]] = 2;
                if(j > 0 && mtx[i][j-1] == mtx[i][j]) cost[mtx[i][j]] = 2;
            }
        }

        int sum = 0, maxv = 0;
        for(int i = 0; i < cost.size(); i++){
            sum += cost[i];
            maxv = max(maxv, cost[i]);
        }

        cout << sum - maxv << endl;
    }
    return 0;
}