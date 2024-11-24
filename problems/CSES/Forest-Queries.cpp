#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int prefix_matrix[MAXN][MAXN];

int main(){
    int n, q; cin >> n >> q;

    char forest_map[MAXN][MAXN];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0) forest_map[i][j] = '.';
            else cin >> forest_map[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefix_matrix[i][j] = prefix_matrix[i][j-1] + prefix_matrix[i-1][j] - prefix_matrix[i-1][j-1] + (forest_map[i][j] == '*');
        }
    }

    for(int i = 0; i < q; i++){
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix_matrix[y2][x2] + prefix_matrix[y1-1][x1-1] - prefix_matrix[y1-1][x2] - prefix_matrix[y2][x1-1] << endl;
    }

    return 0;
}