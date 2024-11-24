#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

long long int BIT[MAXN];
int seq[MAXN], n;

void update(int i, int x){
    while(i <= n){
        BIT[i] += x;
        i += i & (-i);
    }
}

long long int sum(int i){
    long long int aux = 0;
    while(i > 0){
        aux += BIT[i];
        i -= i & (-i);
    }
    return aux;
}

int main(){
    while(cin >> n){
        if(n == 0) break;
        memset(BIT, 0, sizeof(BIT));
        memset(seq, 0, sizeof(seq));

        for(int i = 1; i <= n; i++){
            cin >> seq[i];
        }

        long long int ans = 0;

        for(int i = n; i >= 1; i--){
            ans += sum(seq[i]);
            update(seq[i], 1);
        }

        cout << (ans % 2 == 0 ? "Carlos" : "Marcelo") << endl;
    }
    return 0;
}