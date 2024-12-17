#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n, 0);

        set<int> values;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            values.insert(a[i]);
        }

        vector <int> not_in;
        for(int i = 1; i <= n; i++) if(!values.count(i)) not_in.push_back(i);
        
        set <int> in;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(in.count(a[i])) cout << not_in[j++] << " ";
            else cout << a[i] << " ";
            in.insert(a[i]);
        }

        cout << endl;

    }
    return 0;
}