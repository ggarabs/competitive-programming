#include <bits/stdc++.h>
#define MAXN 200007

using namespace std;

int main(){
	int n, hab[MAXN];
	cin >> n;

	for(int i = 0; i < n; i++) cin >> hab[i];
	sort(hab, hab+n);

	int l = 0, r = 0, ans = 0;

	while(l <= r && l < n && r < n){
		int dif = hab[r] - hab[l];
		cout << r << " " << l << " " << ans << endl;
		if(dif <= 5){
			ans = max(ans, r-l+1);
			r++;
		}else l++;
	}

	cout << ans << endl;

	return 0;
}
