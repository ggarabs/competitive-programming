#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, i = 0, x = 0; cin >> n;
		while(x + n >= 0 && n - x >= 0){
			x += pow(-1, i+1)*(2*i + 1);
			i++;
		}
		if(i % 2) cout << "Sakurako" << endl;
		else cout << "Kosuke" << endl;
	}
	return 0;
}
