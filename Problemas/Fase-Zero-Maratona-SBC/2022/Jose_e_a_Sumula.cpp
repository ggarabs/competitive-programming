#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	for(int i = 1; i <= n; i++){
		int a, b; cin >> a >> b;
		char c; cin >> c;
		if(b == 1 && a > 45) cout << 45 << '+' << a-45 << endl;
		else if(b == 2 && a > 45) cout << 90 << '+' << a-45 << endl;
		else if(b == 2) cout << 45+a << endl;
		else cout << a << endl;
	}

	return 0;
}
