#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n, k; cin >> n >> k;

    vector <lli> pre_sum(k+1, 0);
    vector <int> trees(k+1, 0);

    for(int i = 1; i <= k; i++) cin >> trees[i];

    sort(trees.begin(), trees.end());

    for(int i = 1; i <= k; i++) pre_sum[i] = pre_sum[i-1] + trees[i];

    int sld = 0, it = 0;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        char op; cin >> op;

        if(op == 'C') sld++;
        else sld--;

        if(it >= k) continue;

        ans += max(pre_sum[k]-pre_sum[it]+(k-it)*sld, (lli)0);

        vector<int>::iterator pt = upper_bound(trees.begin()+it, trees.end(), -sld);
        if(pt > trees.begin()+it) pt--;

        it = max(it, (int)(pt - trees.begin()));
    }

    cout << ans << endl;

    return 0;
}