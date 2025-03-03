#include <bits/stdc++.h>

using namespace std;

int ans = 0x7fffffff;

bool solve(int x, string s){
    vector <int> cont('z'-'a'+1, 0);
    string s1 = s.substr(0, x+1), s2 = s.substr(x+1, s.size()-(x+1));

    for(int i = 0; i < s1.size(); i++) cont[s1[i]-'a']++;

    int l = 0;
    for(int i = s2.size()-1; i >= 0 && l < s1.size(); i--){
        if(cont[s2[i]-'a'] > 0){
            cont[s2[i]-'a']--;
            l++;
        }else return false;
    }

    if(s1.size() > s2.size()){
        if(s1.size() > l && ((s1.size()-l) % 2)){
            bool even = false;
            for(int i = l; i < s1.size(); i++){
                if(cont[s1[i]-'a'] % 2){
                    if(even) return false;
                    even = true;
                }
            }
        }else{
            for(int i = l; i < s1.size(); i++){
                if(cont[s1[i]-'a'] % 2) return false;
            }
        }    
    }else{
        for(int r = 0, l = s2.size()-s1.size()-1; r <= l ;r++, l--){
            if(s2[r] != s2[l]) return false;
        }
    }

    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        ans = 0x7fffffff;
        string s; cin >> s;
        for(int i = 0; i < 2; i++){
            int l = 0, r = s.size()-1;
            while(l < r && s[l] == s[r]){ l++, r--; }

            s = s.substr(l, (r-l)+1);

            if(!s.size()){
                ans = 0;
                continue;
            }

            l = 0, r = s.size()-1;
            while(l <= r){
                int mid = (l+r)/2;

                bool ans = solve(mid, s);
                if(ans) r = mid-1;
                else l = mid+1;
            }
            ans = min(l+1, ans);
            reverse(s.begin(), s.end());
        }
        cout << ans << endl;
    }
    
    return 0;
}