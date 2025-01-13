#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        string path; cin >> path;

        vector <vector<lli>> grid(n, vector <lli>(m, 0));

        vector <lli> r_sum(n, 0), c_sum(m, 0), r_fill(n, 0), c_fill(m, 0);

        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            r_sum[i] += grid[i][j];
            c_sum[j] += grid[i][j];
        }

        int x = 0, y = 0;
        for(int i = 0; i <= path.size(); i++){
            r_fill[x]++;
            c_fill[y]++;
            if(path[i] == 'D') x++;
            else y++;
        }

        x = 0, y = 0;
        for(int i = 0; i <= path.size(); i++){
            if(r_fill[x] == 1) grid[x][y] = -r_sum[x];
            else if(c_fill[y] == 1) grid[x][y] = -c_sum[y];

            r_sum[x] += grid[x][y];
            c_sum[y] += grid[x][y];
            r_fill[x]--;
            c_fill[y]--;
            
            if(path[i] == 'D') x++;
            else y++;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << grid[i][j] << " ";
            cout << endl;
        }

    }
    return 0;
}