#include <bits/stdc++.h>

using namespace std;

int main(){
    string str; cin >> str;

    int l = 0, r = 0;
    int len = str.size();

    string ans = "";

    while(l < len && r < len){
        if(str[r] == 'W'){
            r++;
        }else if(str[r] == 'A'){
            ans += 'A';
            while(l < r){
                ans += 'C';
                l++;
            }
            l++;
            r++;
        }else{
            while(l < r){
                ans += 'W';
                l++;
            }
            ans += str[r];
            l++;
            r++;
        }
    }

    while(l < r){
        ans += 'W';
        l++;
    }

    cout << ans << endl;

    return 0;
}