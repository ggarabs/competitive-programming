#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector <int> list(n, 0);
    vector <int> sum;

    for(int i = 0; i < n; i++) cin >> list[i];

    sort(list.begin(), list.end());

    sum.push_back(0);
    for(int i = 0; i < n; i++){
        auto max_sum = upper_bound(sum.begin(), sum.end(), list[i]);
        max_sum--;

        if(abs(list[i] - *max_sum))
        sum.push_back(list[i] + sum[i]);
    }

    return 0;
}