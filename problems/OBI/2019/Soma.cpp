#include <bits/stdc++.h>
#define MAXN 500007

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    long long int prefix_sum[MAXN];

    prefix_sum[0] = 0;
    for(int i = 1; i <= n; i++){
        int aux;
        cin >> aux;
        prefix_sum[i] = prefix_sum[i-1] + aux;
    }

    long long int ans = 0;

    for(int i = 1; i <= n; i++){
        ans += upper_bound(prefix_sum+i, prefix_sum+n+1, k+prefix_sum[i-1]) - lower_bound(prefix_sum+i, prefix_sum+n+1, k+prefix_sum[i-1]);
    }

    cout << ans << endl;

    return 0;
}