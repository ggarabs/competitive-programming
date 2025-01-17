#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        deque <int> l;
        int i = 1;
        for(; i <= n-5; i++) l.push_back(i);
        l.push_front(i+1);
        l.push_front(i);
        l.push_front(i);
        l.push_back(i);
        l.push_back(i+1);

        for(int i = 0; i < n; i++) cout << l[i] << " ";
        cout << endl;
    }

    return 0;
}