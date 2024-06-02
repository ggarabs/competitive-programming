#include <bits/stdc++.h>
#define MAXN 507

using namespace std;

char matriz[MAXN][MAXN];

int desl_x[8] = {1, 1, -1, -1}, desl_y[8] = {1, -1, 1, -1};

int main(){
    int n, m; cin >> n >> m;
    int k, l; cin >> k >> l;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> matriz[i][j];

    int maxv = 0;
    int ans_x = -1, ans_y = -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int values = 0;

            if(ans_x == -1 && ans_y == -1 && matriz[i][j] == '.'){ ans_x = i; ans_y = j; }

            if(matriz[i][j] == '.'){
                for(int k = 0; k < 8; k++) if(matriz[i+(l-1)*desl_x[k]][j+(k-1)*desl_y[k]] == '*') values++;
            }

            if(values > maxv){
                ans_x = i;
                ans_y = j;
                maxv = values;
            }

        }
    }

    cout << ans_x+1 << " " << ans_y + 1 << endl;

    return 0;
}