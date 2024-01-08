#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100007

using namespace std;

vector <int> LIS(vector <int> &v){
    vector <int> st, resp;

    for(int i = 0; i < v.size(); i++){
        vector <int>::iterator it = lower_bound(st.begin(), st.end(), v[i]);

        int p = it-st.begin();

        if(it == st.end()) st.pb(v[i]);
        else *it = v[i];

        resp.pb(p+1);
    }

    return resp;
}

int main(){
    int m;
    cin >> m;

    vector <int> seq;

    for(int i = 0; i < m; i++){
        int x; cin >> x;
        seq.pb(x);
    }

    vector <int> lis, rlis;
    lis = LIS(seq);

    reverse(seq.begin(), seq.end());
    rlis = LIS(seq);

    reverse(rlis.begin(), rlis.end());

    int ans = 0;

    for(int i = 0; i < seq.size(); i++){
        if(lis[i] == rlis[i]) ans = max(ans, rlis[i]+lis[i]-1);
    }

    cout << ans << endl;

    return 0;
}