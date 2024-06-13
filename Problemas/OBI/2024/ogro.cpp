#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

int main(){ _
    int e, d; cin >> e >> d;

    if(e > d) cout << e + d << endl;
    else cout << 2*(d - e) << endl; 

    return 0;
}