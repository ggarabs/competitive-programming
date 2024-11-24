#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, pont = 100, ans = 100;
    cin >> c;

    for(int i = 0; i < c; i++){
        int v;
        cin >> v;
        pont += v;
        ans = max(ans, pont);
    }

    cout << ans << endl;

    return 0;
}