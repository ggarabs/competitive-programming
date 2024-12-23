#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long int x, y; cin >> x >> y;

        long long int sum = 0;
        vector <int> a(n, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());

        long long int sum_n = 0;

        for(int i = 0; i < n; i++){
           long long int lim_inf = sum-a[i]-y, lim_sup = sum-a[i]-x;
           int minv = lower_bound(a.begin(), a.end(), lim_inf) - a.begin();
           int maxv = upper_bound(a.begin(), a.end(), lim_sup) - a.begin();
        //    cout << minv << " " << maxv << endl;

           minv = max(minv, i+1);

           sum_n += ((maxv - minv) > 0 ? maxv - minv : 0);
        }

        cout << sum_n << endl;

    }
    return 0;
}