#include <bits/stdc++.h>
#define INF 1000000009
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

typedef unsigned long long int ulli;

using namespace std;

ulli lsb(ulli x){
    return x & -x;
}

int main(){ _
    ulli n, q;

    cin >> n >> q;

    ulli pwr = 1ULL << n;
    ulli mask = pwr - 1;
    ulli final_ans = 0, acc = 1;

    for(int i = 0; i < q; i++){
        ulli ik, jk, ans = 0; cin >> ik >> jk;

        ik |= pwr;
        jk |= pwr;

        if(lsb(jk) < lsb(ik)) swap(ik, jk);

        while(lsb(ik) < lsb(jk)){
            ik = ((ik << 1) & mask) | pwr;
            ans++;
        }

        while(ik != jk){
            ik = ((ik << 1) & mask) | pwr;
            jk = ((jk << 1) & mask) | pwr;
            ans += 2;
        }

        final_ans = (final_ans + ((ans*acc) % INF)) % INF;
        acc = ((acc * n) % INF);
    }

    cout << final_ans << endl;

    return 0;
}