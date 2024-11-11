#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

bool dp[MAXN][MAXN*MAXN];

int main(){
    int n, target = 0; cin >> n;

    vector <int> caramels(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> caramels[i];
        target += caramels[i];
    }

    if(target % 2){
        cout << -1 << endl;
        return 0;
    }
    target /= 2;

    sort(caramels.begin(), caramels.end());

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(caramels[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-caramels[i]];
        }
    }

    if(!dp[n][target]){
        cout << -1 << endl;
        return 0;
    }

    vector <int> a, b;
    int sum = target;
    for(int i = n; i > 0; i--){
        if(sum >= caramels[i] && dp[i-1][sum-caramels[i]]){
            a.push_back(caramels[i]);
            sum -= caramels[i];
        }else b.push_back(caramels[i]);
    }

    int sum_a = 0, sum_b = 0;
    for(int i = 0, j = 0; i < a.size() || j < b.size();){
        if(sum_a <= sum_b){
            cout << a[i] << " ";
            sum_a += a[i++];
        }else{
            cout << b[j] << " ";
            sum_b += b[j++];
        }
    }

    cout << endl;

    return 0;
}