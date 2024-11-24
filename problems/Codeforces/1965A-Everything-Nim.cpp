#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e9+7;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set<int> num;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			num.insert(x);
		}

		bool vic = true;

		for(int i = 1; i <= MAXV; i++){
			if(!num.count(i)){
				bool odd = (i % 2);
				bool empty = num.empty();
				if((odd && empty) || (!empty && !odd)) vic = false;
				break;
			}
			num.erase(i);
		}

		cout << (vic ? "Alice" : "Bob") << endl;
	}
	return 0;
}
