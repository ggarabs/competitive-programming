#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, q; cin >> n >> q;

		vector <int> prefix_max(n+1, 0);
		for(int i = 1; i <= n; i++){
			int elem; cin >> elem;
			prefix_max[i] = max(elem, prefix_max[i-1]);
		}

		vector <char> dir(n+1, 0);
		for(int i = 1; i <= n; i++) cin >> dir[i];

		set <int> red_lines;

		for(int i = 1; i < n; i++){
			if(dir[i] == 'L' && dir[i+1] == 'R'){
				if(prefix_max[i] > i) red_lines.insert(i);
			}
		}

		while(q--){
			int upd; cin >> upd;
			if(dir[upd] == 'L'){
				if(dir[upd+1] == 'R' && red_lines.count(upd)) red_lines.erase(upd);
				if(dir[upd-1] == 'L' && prefix_max[upd-1] > upd-1) red_lines.insert(upd-1);
				dir[upd] = 'R';
			}else{
				if(dir[upd-1] == 'L' && red_lines.count(upd-1)) red_lines.erase(upd-1);
				if(dir[upd+1] == 'R' && prefix_max[upd] > upd) red_lines.insert(upd);
				dir[upd] = 'L';
			}
			if(red_lines.size()) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	return 0;
}
