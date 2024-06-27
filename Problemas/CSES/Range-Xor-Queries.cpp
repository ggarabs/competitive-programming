#include <bits/stdc++.h>
#define XOR ^

using namespace std;

int main(){
    int n, q; cin >> n >> q;

    vector <int> prefix_sum(n+1, 0);

    for(int i = 1; i <= n; i++){
        int value; cin >> value;
        prefix_sum[i] = prefix_sum[i-1] XOR value;
    }

    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        cout << (prefix_sum[b] XOR prefix_sum[a-1]) << endl;
    }

    return 0;
}