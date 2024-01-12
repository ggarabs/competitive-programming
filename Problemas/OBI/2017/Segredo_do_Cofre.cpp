#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int prefix[MAXN][10], ans[10];

int main(){
    int n, m;
    cin >> n >> m;
    
    int barra[MAXN];
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 10; j++){
            prefix[i][j] = prefix[i-1][j];
        }
        cin >> barra[i];
        prefix[i][barra[i]]++;
    }
    
    int ini = 0, fim;
    
    for(int i = 0; i < m; i++){
        cin >> fim;
        
        for(int j = 0; j < 10; j++){
            if(fim > ini){
                ans[j] += abs(prefix[fim][j]-prefix[ini][j]);
            }else{
                ans[j] += abs(prefix[ini-1][j]-prefix[fim-1][j]);
            }
        }

        ini = fim;
    }
    
    for(int i = 0; i < 10; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
    
}