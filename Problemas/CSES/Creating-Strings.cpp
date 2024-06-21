#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string word; cin >> word;

    vector <string> ans;

    sort(word.begin(), word.end());

    do ans.push_back(word); while(next_permutation(word.begin(), word.end()));

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;

    return 0;
}