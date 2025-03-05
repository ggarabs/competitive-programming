#include <bits/stdc++.h>
#define pii pair<int, int>

const int INF = 0x7fffff;

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;

        int x = -INF, y = -INF;

        vector <pii> ans;

        while(k > 0){
            int ini = 0, fim = 500;
            while(ini <= fim){
                int mid = (ini+fim)/2;
    
                if((mid*(mid-1)/2) > k) fim = mid-1;
                else ini = mid+1;
            }

            for(int i = 0; i < fim; i++){
                ans.push_back({x, y});
                y++;
            }
            x++;

            k -= fim*(fim-1)/2;
        }

        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    return 0;
}