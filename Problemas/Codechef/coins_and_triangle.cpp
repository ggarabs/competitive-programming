#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int coins; cin >> coins;

        double answer = (sqrt(8*coins+1)-1)/2.0;

        cout << (long long int)floor(answer) << endl;
    }
}