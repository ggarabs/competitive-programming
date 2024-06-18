#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x; cin >> n >> x;

    vector <int> weights(n, 0);
    for(int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int l = 0, r = n-1, cont = 0;

    while(l >= 0 && r < n && l <= r){
        if(weights[l] + weights[r] <= x) l++;
        cont++;
        r--;
    }

    cout << cont << endl;

    return 0;
}