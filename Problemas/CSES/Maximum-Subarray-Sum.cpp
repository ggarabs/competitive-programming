#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector<long long int> array(n, 0);
    for(int i = 0; i < n; i++) cin >> array[i];

    long long int curr = array[0], ans = array[0];

    for(int i = 1; i < n; i++){
        curr = max(array[i], curr+array[i]);
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}