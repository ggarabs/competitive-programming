#include <bits/stdc++.h>
#define lli long long int

const lli MAXN = 2*1e9;

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        
        vector <int> a(n, 0), b(n, 0);
        set <int> aux;
        for(int i = 0; i < a.size(); i++){
            cin >> a[i];
            aux.insert(a[i]);
        }
        for(int i = 0; i < b.size(); i++){
            cin >> b[i];
            aux.insert(b[i]);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long int ans = 0;

        for(set<int>::iterator pt = aux.begin(); pt != aux.end(); pt++){
            int value = *pt;
            long long int dontpay = lower_bound(b.begin(), b.end(), value) - b.begin();
            long long int neg = lower_bound(a.begin()+dontpay, a.end(), value) - a.begin() - dontpay;

            if(neg <= k){
                ans = max(ans, (n-dontpay)*value);
            }
        }

        cout << ans << endl;
    }

    return 0;
}