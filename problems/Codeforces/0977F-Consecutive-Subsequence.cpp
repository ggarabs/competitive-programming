#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1e5+7;

int dp[MAXN];

int main(){
    int n; cin >> n;
    vector <int> a(n, 0);
    map <int, int> dp;
    int ans = 0, lastv = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[a[i]] = dp[a[i]-1] + 1;
        if(dp[a[i]] > ans){
            ans = dp[a[i]];
            lastv = a[i];
        }
    }

    cout << ans << endl;

    vector <int> lst;

    for(int i = n-1; i >= 0; i--){
        if(lastv == a[i]){
            lst.push_back(i+1);
            lastv--;
        }
    }
    reverse(lst.begin(), lst.end());

    for(int i = 0; i < lst.size(); i++) cout << lst[i] << " ";
    cout << endl;

    return 0;
}