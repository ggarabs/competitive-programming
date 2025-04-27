#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265359;

int main(){
    int r[4]; 

    for(int i = 1; i <= 3; i++) cin >> r[i];

    cout.precision(10);
    cout.setf(ios::fixed);

    int n, q; cin >> n >> q;

    while(q--){
        int c1, l1, c2, l2; cin >> c1 >> l1 >> c2 >> l2;

        if(c1 > c2) swap(c1, c2);
        if(l1 > l2) swap(l1, l2);

        cout << min(min(l2-l1, l1-l2+n)*(2*PI*r[c1]/n) + (r[c2]-r[c1]), min(l2-l1, l1-l2+n)*(2*PI*r[1]/n) + r[c1] + r[c2] - 2*r[1]) << endl;
    }

    return 0;
}