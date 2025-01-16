#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    map<string, vector<int>> prefix, sufix;

    for(int k = 0; k < n; k++){
        string curr; cin >> curr;

        for(int i = 0; i < 11; i++){
            string p = curr.substr(0, i), s = curr.substr(i, 11);
            if(prefix[s].size() && sufix[p].size()){
                if(prefix[s].size() > 1  || sufix[p].size() > 1){
                    cout << curr << endl;
                    return 0;
                }
                else if(prefix[s][0] != sufix[p][0]){
                    cout << curr << endl;
                    return 0;
                }else if(prefix[s][0] == sufix[p][0] && (i == 0 || i == 10)){
                    cout << curr << endl;
                    return 0;
                }
            }
        }

        for(int i = 0; i < 11; i++){
            string pref = curr.substr(0, i), suf = curr.substr(i, 11);
            prefix[pref].push_back(k);
            sufix[suf].push_back(k);
        }
    }

    cout << "ok" << endl;

    return 0;
}