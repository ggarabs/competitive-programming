#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector <pair<int, string>> str(n, {0, ""});

    for(int i = 0; i < n; i++){
        cin >> str[i].second;
        str[i].first = str[i].second.size();
    }

    sort(str.begin(), str.end());

    for(int i = 0; i < n; i++) cout << str[i].second;

    cout << endl;

    return 0;
}