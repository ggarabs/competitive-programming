#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        lli k; cin >> k;

        if(n <= 40 && k > (1LL << (n-1))){
            cout << -1 << endl;
            continue;
        }

        vector <int> ans(n, 0);
        vector <int> b_rep;

        for(lli aux = k-1; aux > 0; aux /= 2) b_rep.push_back(aux%2);
        for(int aux = b_rep.size(); aux < n-1; aux++) b_rep.push_back(0);
        reverse(b_rep.begin(), b_rep.end());

        int l = 0, r = n-1, cont = 1;
        for(int i = 0; i < b_rep.size(); i++){
            if(!b_rep[i]) ans[l++] = cont++;
            else ans[r--] = cont++;
        }

        ans[r] = cont;

        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;

    }
    return 0;
}