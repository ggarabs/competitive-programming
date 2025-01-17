#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int x0, y0; cin >> x0 >> y0;
        int xf = x0+m, yf = y0+m;
        for(int i = 1; i < n; i++){
            int aux1, aux2; cin >> aux1 >> aux2;
            xf += aux1, yf += aux2;
        }

        cout << 2*((yf-y0)+(xf-x0)) << endl;
    }
}