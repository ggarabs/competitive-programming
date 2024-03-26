#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

int main(){ _
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        long long int x, palp;
        cin >> x;

	palp = (sqrt(24)*sqrt(x)-1)/6;

	while(x == ((6*(palp+1)+1)*(6*(palp+1)+1)-1)/24.0) palp++;

        cout << palp << endl;
    }

    exit(0);
}
