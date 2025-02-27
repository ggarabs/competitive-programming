#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;

        lli cont = 0;
        for(int i = 0; i < str.size(); i++) cont += (str[i] == '-');

        lli ans = 0;
        if(cont % 2 == 0) ans = (lli)(cont*cont)/4;
        else ans = (lli)((cont/2+1)*(cont/2));

        ans *= (n-cont);

        cout << ans << endl;
    }
    return 0;
}