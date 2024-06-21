#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector <pair <int, bool>> customers(2*n, {0, 0});
    for(int i = 0; i < 2*n; i++){
        cin >> customers[i].first;
        if(i % 2 == 0) customers[i].second = true;
    }

    sort(customers.begin(), customers.end());
    
    int ans = 0, curr = 0;
    for(int i = 0; i < 2*n; i++){
        curr += customers[i].second;
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}