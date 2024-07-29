#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	getchar();
	while(t--){
		string msg; getline(cin, msg);
		for(int i = msg.size()/2-1; i >= 0; i--) cout << msg[i];
		for(int i = msg.size()-1; i >= msg.size()/2; i--) cout << msg[i];
		cout << endl;
	}
	return 0;
}
