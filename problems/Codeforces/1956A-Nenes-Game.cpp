#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int k, q; cin >> k >> q;
        vector <int> a(k+1, 0);

        for(int i = 0; i < k; i++) cin >> a[i];
        int minvalue = a[0];
        minvalue--;

        for(int i = 0; i < q; i++){
          int aux; cin >> aux;
          cout << min(aux, minvalue) << " ";
        }

        cout << endl;
    }

    return 0;
}