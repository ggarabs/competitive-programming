#include <bits/stdc++.h>

using namespace std;

int main(){
    string seq; cin >> seq;
    seq += '.';

    int cont = 0, ans = 0; char curr = ' ';
    for(int i = 0; i < (int)seq.size(); i++){
        if(seq[i] != curr){
            curr = seq[i];
            ans = max(cont, ans);
            cont = 1;
        }else cont++;
    }
    
    cout << ans << endl;

    return 0;
}