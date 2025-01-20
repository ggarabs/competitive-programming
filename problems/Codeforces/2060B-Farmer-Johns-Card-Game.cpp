#include <bits/stdc++.h>

using namespace std;

int ans[2007];

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector <vector<int>> cows(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> cows[i][j];
            }
        }

        bool has_sol = true;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if((cows[i][j] % n) != (cows[i][0]) % n){
                    has_sol = false;
                    break;
                }
            }
            sort(cows[i].begin(), cows[i].end());
        }

        if(!has_sol){
            cout << -1 << endl;
            continue;
        }

        for(int i = 1; i <= n; i++) ans[cows[i-1][0]] = i;

        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;

    }
    return 0;
}