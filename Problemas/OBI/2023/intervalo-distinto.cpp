#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int main(){
    int n, seq[MAXN];
    cin >> n;

    for(int i = 0; i < n; i++) cin >> seq[i];

    int r, l;
    r = l = 0;

    set <int> conj;

    int ans = 0;

    while(r < n && l < n){
        if(conj.find(seq[r]) == conj.end()){
            conj.insert(seq[r++]);
            ans = max(ans, r-l);
        }else{
            while(conj.find(seq[r]) != conj.end()){
                conj.erase(seq[l++]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}