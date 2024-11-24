#include <bits/stdc++.h>
#define MAXN 2007

using namespace std;

struct area{
    int x, y, rad;
};

int mat[MAXN][MAXN], pts[MAXN];

int main(){
    int n, m, s;
    cin >> n >> m >> s;

    vector <area> v;

    for(int i = 0; i < s; i++){
        int x1, y1, rad1;
        cin >> x1 >> y1 >> rad1;
        v.push_back({x1, y1, rad1});
    }

    for(int i = 0; i < s; i++){
        int y_inf = max(v[i].y-v[i].rad, 1), y_sup = min(v[i].y+v[i].rad+1, m+1);
        for(int x = max(v[i].x-v[i].rad, 1); x <= min(v[i].x+v[i].rad, m); x++){
            mat[x][y_inf]++;
            mat[x][y_sup]--;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mat[i][j] += mat[i][j-1];
            pts[mat[i][j]]++;
        }
    }

    int ans = 0;

    for(int i = 0; i <= s; i++) ans += pts[i]*i;

    cout << ans/(n*m) << endl;

    return 0;
}