#include <bits/stdc++.h>
#define lli long long int
#define MAXV 2000000000

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        lli n; cin >> n;

        lli ini = 0, fim = MAXV;
 
        while(ini <= fim){
            lli mid = (ini + fim)/2;
            lli chips = (mid+1)*(mid+1);
            if(chips >= n) fim = mid - 1;
            else ini = mid + 1;
        }

        cout << ini << endl;
    }
    return 0;
}