#include <bits/stdc++.h>
#define mod %

const int INF = 998244353;

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector <int> a(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];

        int beg = 0, mid = 0, end = 0;
        
        for(int i = 0; i < n; i++){
            if(a[i] == 1) beg = (beg mod INF + 1) mod INF;
            else if(a[i] == 2) mid = (beg + 2*mid mod INF) mod INF;
            else end = (end mod INF + mid) mod INF;
        }

        cout << end << endl;
    }
    return 0;
}