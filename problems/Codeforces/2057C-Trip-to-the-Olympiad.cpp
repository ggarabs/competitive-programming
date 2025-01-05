#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;

        int lc = l, rc = r, pos = 0, cont = 0;

        int a = 0, b = 0, c = 0;

        while(lc || rc){
            if((lc % 2) != (rc % 2)) pos = cont;
            lc = (lc >> 1);
            rc = (rc >> 1);
            cont++;
        }

        a = pow(2, pos), b = pow(2, pos)-1;

        if(a < l){
            lc = l;
            lc = (lc >> (pos+1));

            int cont = pos+1;
            while(lc){
                a += (lc % 2)*pow(2, cont++);
                lc = (lc >> 1);
            }
        }
        if(b < l){
            lc = l;
            lc = (lc >> (pos+1));

            int cont = pos+1;
            while(lc){
                b += (lc % 2)*pow(2, cont++);
                lc = (lc >> 1);
            }
        }

        if(b == l) c = b+2;
        else if(a == r) c = a-2;
        else c = l;

        cout << a << " "  << b << " " << c << endl;
    }
    return 0;
}