#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int zeros[MAXN], product[MAXN], elem[MAXN], n;

void z_updt(int i, int x){
    while(i <= n){
        zeros[i] += x;
        i += i & (-i);
    }
}

int z_query(int i){
    int z = 0;
    while(i > 0){
        z += zeros[i];
        i -= i & (-i);
    }
    return z;
}

void updt(int i){
    while(i <= n){
        product[i] *= -1;
        i += i & (-i);
    }
}

int query(int i){
    int ans = 1;
    while(i > 0){
        ans *= product[i];
        i -= i & (-i);
    }
    return ans;
}

int main(){
    int k;

    while(cin >> n >> k){
        for(int i = 0; i <= n; i++){
            product[i] = 1;
            elem[i] = 1;
            zeros[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            cin >> elem[i];
            if(elem[i] == 0) z_updt(i, 1);
            else elem[i] /= abs(elem[i]);
            if(elem[i] == -1) updt(i);
        }

        for(int i = 0; i < k; i++){
            char k;
            int l, r;

            cin >> k >> l >> r;

            if(k == 'C'){
                if(elem[l] == 0){
                    if(r != 0){
                        r /= abs(r);
                        z_updt(l, -1);
                        if(r == -1) updt(l);
                    }
                }else{
                    if(r == 0){
                        z_updt(l, 1);
                        if(elem[l] == -1) updt(l);
                    }else{
                        r /= abs(r);
                        if(elem[l] != r) updt(l);
                    }
                }
                elem[l] = r;
            }else{
                if(z_query(r) > z_query(l-1)) cout << '0';
                else{
                    char resp = query(r)/query(l-1) == 1 ? '+' : '-';
                    cout << resp;
                }
            }
        }
        cout << endl;
    }

    return 0;
}