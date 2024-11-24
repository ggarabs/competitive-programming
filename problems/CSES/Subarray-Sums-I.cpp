#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n, x; cin >> n >> x;

    vector <int> list(n, 0);
    vector <lli> prefix_sum;

    prefix_sum.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> list[i];
        prefix_sum.push_back(prefix_sum[i] + list[i]);
    }

    int l = 0, r = 0;
    lli cont = 0;

    while(l <= n && r <= n){
        lli sum = prefix_sum[r] - prefix_sum[l];
        if(sum == x){ cont++; r++; l++; }
        else if(sum < x) r++;
        else l++;
    }

    cout << cont << endl;

    return 0;
}