#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	vector <int> num[2];

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		num[x%2].push_back(x);
	}

	for(int i = 0; i < 2; i++) sort(num[i].begin(), num[i].end());

	for(int i = 0; i < num[0].size(); i++) cout << num[0][i] << endl;
	for(int i = num[1].size()-1; i >= 0; i--) cout << num[1][i] << endl;

	return 0;
}
