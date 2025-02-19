#include <bits/stdc++.h>

using namespace std;

int main(){
    int b, l; cin >> b >> l;

    vector <int> n(l, 0);

    int sum = 0;

    for(int i = 0; i < l; i++){
        cin >> n[i];
        sum += pow(-1, l-1-i)*n[i];
    }

    sum %= (b+1);

    if(sum == 0){
        cout << "0 0" << endl;
        return 0;
    }

    for(int i = 0; i < l; i++){
        int aux = sum - pow(-1, l-1-i)*n[i];
        int parc = aux % (b+1);
        int ans = (b+1)-parc;
        if((l-1-i) % 2) ans *= -1;

        ans = (ans%(b+1)+(b+1))%(b+1);

        if(ans < n[i]){
            cout << i+1 << " " << ans << endl;
            return 0;
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}