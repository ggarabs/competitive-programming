#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string seq;
    cin >> seq;

    seq += 'b';

    int cont = 0, ans = 0;
    for(int i = 0; i < seq.size(); i++){
        if(seq[i] == 'a') cont++;
        else{
            if(cont > 1) ans += cont;
            cont = 0;
        }
    }

    cout << ans << endl;

    return 0;
}