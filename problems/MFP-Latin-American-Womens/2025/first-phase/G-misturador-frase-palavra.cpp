#include <bits/stdc++.h>

using namespace std;

int main(){
    string str; cin >> str;

    string s[2] = {"", ""};

    for(int i = 0; i < str.size(); i+=2){
        s[i%2] += str[i];
        s[i%2+1] += str[i+1];
    }

    cout << s[0] << endl << s[1] << endl;

    return 0;
}