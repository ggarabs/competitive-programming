#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> pairs(n, 0);
    for(int i = 1; i < n; i++){
        int j;
        for(j = 1; j*j < i; j++){
            if(i % j == 0) pairs[i] += 2;
        }
        if(j*j == i) pairs[i]++;
    }

    lli ans = 0;
    for(int i = 1; i < n; i++) ans += pairs[i]*pairs[n-i];
    
    cout << ans << endl;

    return 0;
}