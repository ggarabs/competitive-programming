#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n; cin >> n;

    vector <int> array(n, 0);
    for(int i = 0; i < n; i++) cin >> array[i];

    sort(array.begin(), array.end());

    int ini = (n-1)/2;
    long long int ans = -1;

    for(int j = 0; j < 2; j++){
        long long int min_v = 0;
        for(int i = 0; i < n; i++) min_v += abs(array[i] - (array[ini] + j));
        if(ans == -1) ans = min_v;
        ans = min(ans, min_v);
    }

    cout << ans << endl;

    return 0;
}