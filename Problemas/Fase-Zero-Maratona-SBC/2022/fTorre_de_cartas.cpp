#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        long long int x;
        cin >> x;

        cout << (unsigned long long int)(sqrt((unsigned long long int)(24*x + 1)) - 1)/6 << endl;
    }

    return 0;
}