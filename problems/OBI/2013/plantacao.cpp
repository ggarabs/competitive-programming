#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n, k; cin >> n >> k;

    vector <int> tree(k, 0);
    for(int i = 0; i < k; i++) cin >> tree[i];

    vector<char> saf(n, 'a');
    for(int i = 0; i < n; i++) cin >> saf[i];

    vector <lli> values(101, 0);
    for(int i = 1; i <= 100; i++){
        int curr = i;
        for(int j = 0; j < n; j++){
            if(saf[j]=='C') curr++;
            else curr--;
            if(!curr) break;
            values[i] += curr;
        }
    }

    lli ans = 0;
    for(int i = 0; i < k; i++) ans += values[tree[i]];

    cout << ans << endl;

    return 0;
}