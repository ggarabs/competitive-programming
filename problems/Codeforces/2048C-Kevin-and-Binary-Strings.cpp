#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int dig = 0;
        for(int i = 0; i < s.size();  i++){
            if(s[i] == '0') break;
            dig++;
        }
        dig = s.size() - dig;
        if(dig == 0) dig = 1;
        int maxv = 0, l = 1, r = s.size();
        for(int i = 0; i <= s.size()-dig; i++){
            string x = s.substr(i, dig);
            reverse(x.begin(), x.end());
            for(int j = 0; j < s.size()-dig; j++) x += '0';
            reverse(x.begin(), x.end());

            int pont = s.size();
            for(int j = 0; j < s.size(); j++){
                if(x[j] == s[j]){
                    pont = j;
                    break;
                }
            }

            if(pont > maxv){
                l = i+1;
                r = i+dig;
                maxv = pont;
            }
        }
        cout << 1 << " " << s.size() << " " << l << " " << r << endl;
    }
    return 0;
}