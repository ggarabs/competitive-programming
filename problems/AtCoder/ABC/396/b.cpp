#include <bits/stdc++.h>

using namespace std;

int main(){
    int q; cin >> q;

    stack <int> st;
    for(int i = 1; i <= 100; i++) st.push(0);

    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            st.push(x);
        }else{
            cout << st.top() << endl;
            st.pop();
        }
    }

    return 0;
}