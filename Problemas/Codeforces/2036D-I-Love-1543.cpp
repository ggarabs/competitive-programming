#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

char carpet[MAXN][MAXN];

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> carpet[i][j];

        vector <string> layers(max(n, m), "");

        for(int k = 0; k < min(n, m)/2; k++){
            for(int i = 0+k; i < m-k; i++) layers[k] += carpet[0+k][i];
            for(int i = 1+k; i < n-k; i++) layers[k] += carpet[i][m-1-k];
            for(int i = m-2-k; i >= 0+k; i--) layers[k] += carpet[n-1-k][i];
            for(int i = n-2-k; i >= 1+k; i--) layers[k] += carpet[i][0+k];
        }

        for(int i = 0; i < min(n, m)/2; i++) for(int j = 0; j < 3; j++) layers[i] += layers[i][j]; 

        int ans = 0;

        for(int i = 0; i < min(n, m)/2; i++){
            for(int j = 0; j < layers[i].size()-3; j++){
                if(layers[i][j] == '1' && layers[i][j+1] == '5' && layers[i][j+2] == '4' && layers[i][j+3] == '3') ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}