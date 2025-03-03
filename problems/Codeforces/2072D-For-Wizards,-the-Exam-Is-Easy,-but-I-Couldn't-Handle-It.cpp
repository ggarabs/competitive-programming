#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector <int> a(n, 0);
        for(int &x : a) cin >> x;
        pair <int, int> range = {0, 0};
        lli sol = 0;

        for(int i = 0; i < n; i++){
            int inv = 0, n_inv = 0;
            for(int j = i+1; j < n; j++){
                inv += (a[i] > a[j]);
                n_inv += (a[i] < a[j]);

                if(inv-n_inv > sol){
                    sol = inv-n_inv;
                    range = {i, j};
                }
            }
        }
        cout << range.first+1 << " " << range.second+1 << endl;
    }
    return 0;
}