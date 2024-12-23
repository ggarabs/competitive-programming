#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, a, b, c; cin >> n >> a >> b >> c;
        int days = n/(a+b+c);

        int pont = (a+b+c)*days;

        days *= 3;

        if(pont < n){
            pont += a;
            days++;
        }

        if(pont < n){
            pont += b;
            days++;
        }

        if(pont < n){
            pont += c;
            days++;
        }

        cout << days << endl;

    }
    return 0;
}