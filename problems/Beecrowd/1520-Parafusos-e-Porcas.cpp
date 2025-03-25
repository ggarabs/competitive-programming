#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+7;

int main(){
    int n;
    while(cin >> n){
        vector <int> p_sum(MAXN, 0);

        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y;

            p_sum[x]++;
            p_sum[y+1]--;
        }

        for(int i = 1; i < MAXN; i++) p_sum[i] += p_sum[i-1];
 
        vector <int> pos(MAXN, 0);

        for(int i = 1; i < MAXN; i++) pos[i] = pos[i-1] + p_sum[i];
 
        int q; cin >> q;

        if(p_sum[q] == 0) cout << q << " not found" << endl;
        else cout << q << " found from " << pos[q-1] << " to " << pos[q]-1 << endl;
    }
    return 0;
}