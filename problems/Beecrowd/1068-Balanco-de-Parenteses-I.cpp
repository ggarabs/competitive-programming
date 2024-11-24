#include <bits/stdc++.h>

using namespace std;

int main(){
	string exp;
	while(cin >> exp){
		stack <char> st;
		bool flag = false;
		for(int i = 0; i < exp.size(); i++){
			if(exp[i] == '('){
				st.push('(');
			}else if(exp[i] == ')'){
				if(!st.empty() && st.top() == '(') st.pop();
				else{
					cout << "incorrect" << endl;
					flag = true;
					break;
				}
			}
		}

		if(flag) continue;

		if(!st.empty()) cout << "incorrect" << endl;
		else cout << "correct" << endl;
	}

	return 0;
}
