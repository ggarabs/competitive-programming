#include <bits/stdc++.h>
#define lli long long int 

using namespace std;

lli n;

lli calc(lli x){
    lli ans = 0;
    for(int i = 1; i <= n; i++) ans += min(n, x/i);
    return ans;
}

int main(){
    cin >> n;
    lli ini = 1, fim = n*n;

    lli target = (n*n/2)+1;

    while(ini <= fim){
        lli mid = (ini+fim)/2;
        
        lli sol = calc(mid);

        if(sol >= target) fim = mid-1;
        else ini = mid+1;
    }

    cout << ini << endl;

    return 0;
}