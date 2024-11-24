#include <bits/stdc++.h> 

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        unsigned long long int x, y, ans; cin >> y >> x;

        if(y >= x){
            if(y % 2 == 1) ans = y*y-2*y+x+1;
            else ans = y*y-x+1;
        }else{
            if(x % 2 == 0) ans = x*x-2*x+y+1;
            else ans = x*x-y+1;
        }

        cout << ans << endl;
    }

    return 0;
}