#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector <int> seq(n), st;
    for(int i = 0; i < n; i++){
        cin >> seq[i];
        auto ptr = lower_bound(st.begin(), st.end(), seq[i]);

        if(ptr == st.end()) st.push_back(seq[i]);
        else *ptr = seq[i];
    }

    cout << (int)st.size() << endl;

    return 0;
}