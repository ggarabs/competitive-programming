#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        lli n, m, k; cin >> n >> m >> k;
        vector <lli> a(m, 0), q(k, 0);

        for(int i = 0; i < m; i++) cin >> a[i];
        for(int i = 0; i < k; i++) cin >> q[i];

        if(n == k){
            for(int i = 0; i < m; i++) cout << '1';
            cout << endl;
            continue;
        }else if(n > k+1){
            for(int i = 0; i < m; i++) cout << '0';
            cout << endl;
            continue;
        }else if(n == k+1){
            lli qst = n*(n+1)/2;
            for(int i = 0; i < k; i++) qst -= q[i];
            for(int i = 0; i < m; i++){
                if(a[i] == qst) cout << '1';
                else cout << '0';
            }
            cout << endl;
        }
    }
    return 0;
}