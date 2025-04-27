#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector <int> suffix_sum(m+2, 0);

    while(n--){
        int a; cin >> a;
        suffix_sum[a]++;
    }

    for(int i = m; i > 0; i--){
        suffix_sum[i] += suffix_sum[i+1];
    }

    for(int i = 1; i <= m; i++){
        cout << suffix_sum[i] << " ";
    }

    cout << endl;

    return 0;
}