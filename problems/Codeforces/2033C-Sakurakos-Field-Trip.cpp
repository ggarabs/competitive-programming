#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> a(n, 0);

		for(int i = 0; i < n; i++) cin >> a[i];

		int left = 1, right = n-2;
		while(left < right){
			if(a[left] == a[left-1] || a[right] == a[right+1]) swap(a[left], a[right]);
			left++; right--;
		}

		int last = a[0], ans = 1, cont = 0;

		for(int i = 1; i < n; i++){
			if(a[i] != last){
				ans++;
				last = a[i];
			}else cont
		}

		cout << ans << endl;
	}
	return 0;
}
