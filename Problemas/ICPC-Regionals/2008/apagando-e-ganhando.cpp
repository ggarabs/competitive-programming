#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

int main(){
    int n, d;
    while(cin >> n >> d && n && d){
        string num; cin >> num;

        stack <char> st;
        int cont = 0;

        for(char dig : num){
            while(!st.empty() && dig > st.top() && cont++ < d) st.pop();
            if(st.size() < n-d) st.push(dig);
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        cout << ans << endl;
    }

    return 0;
}