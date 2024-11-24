#include <bits/stdc++.h>

using namespace std;

long long solve(long long x){
    if(x == 1) return 1;
    if(x % 2){
        return 1 + solve(3*x+1);
    }else{
        return 1 + solve(x/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while(cin >> a >> b){
        if(b < a) swap(a, b);
        long long c = a, ans = 0;
        while(c <= b){
            ans = max(ans, solve(c));
            c++;
        }
        cout << a << " " << b << " " << (long long)ans << endl;
    }
    return 0;
}