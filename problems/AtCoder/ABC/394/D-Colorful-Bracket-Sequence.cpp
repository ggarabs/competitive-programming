#include <bits/stdc++.h>

using namespace std;

int main(){
    string t; cin >> t;

    stack <char> st;
    map <char, char> mp;

    mp.insert({'<', '>'});
    mp.insert({'(', ')'});
    mp.insert({'[', ']'});

    for(char c : t){
        if(c == '(' || c == '[' || c == '<') st.push(c);
        else{
            if(!st.empty() && mp[st.top()] == c) st.pop();
            else{
                cout << "No" << endl;
                return 0;
            }
        }
    }

    if(!st.empty()){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}