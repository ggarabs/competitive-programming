#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, d;
	while(cin >> n >> d && n && d){
		vector<char> dig(n, 0);
		for(int i = 0; i < n; i++){
			cin >> dig[i];
			dig[i] -= '0';
		}

		vector<int> ans;
		int erased = 0;
		for(int i = 0; i < n; i++){
			while(ans.size() && ans.back() < dig[i] && erased < d){
				ans.pop_back();
				erased++;
			}
			ans.push_back(dig[i]);
		}

		while(erased < d){
			ans.pop_back();
			erased++;
		}

		for(int i = 0; i < ans.size(); i++) cout << ans[i];
		cout << endl;
	}
	return 0;
}
