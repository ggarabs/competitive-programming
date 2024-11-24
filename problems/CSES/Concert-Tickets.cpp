#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, aux; cin >> n >> m;

    multiset <int> tickets;
    for(int i = 0; i < n; i++){ cin >> aux; tickets.insert(aux); }

    int customer;
    for(int i = 0; i < m; i++){
        cin >> customer;
        auto value = tickets.upper_bound(customer);

        if(value == tickets.begin()) cout << -1 << endl;
        else{
            cout << *(--value) << endl;
            tickets.erase(value);
        }
    }

    return 0;
}