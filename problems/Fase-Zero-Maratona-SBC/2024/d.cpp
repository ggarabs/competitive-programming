#include <bits/stdc++.h>
#define mod %

using namespace std;

int main(){
    int e, v; cin >> e >> v;

    int minutes = 60*e/v;

    int hours = minutes/60;
    int minutes2 = minutes%60;

    if((hours+19) % 24 < 10) cout << "0" << (hours+19)%24 << ":";
    else cout << (hours+19)%24 << ":";

    if(minutes2 < 10) cout << "0" << minutes2 << endl;
    else cout << minutes2 << endl;

    return 0;
}