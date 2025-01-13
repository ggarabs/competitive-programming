#include <bits/stdc++.h>

const int INF = 1e9+7;

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector <int> a(n, 0), b(n, 0), dif(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n; i++){
            cin >> b[i];
            dif[i] = a[i]-b[i];
        }

        int cont = 0;
        int minv = dif[0], maxv = INF;
        for(int i = 0; i < n; i++){
            if(dif[i] < 0) cont++;
            if(dif[i] >= 0) maxv = min(dif[i], maxv);
            minv = min(dif[i], minv);
        }

        if((cont == 0) || (cont == 1 && maxv >= abs(minv))) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}