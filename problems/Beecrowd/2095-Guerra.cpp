#include <bits/stdc++.h>

using namespace std;

int main(){
	int s; cin >> s;
	vector <int> adv(s, 0), nlog(s, 0);
	for(int i = 0; i < s; i++) cin >> adv[i];
	for(int i = 0; i < s; i++) cin >> nlog[i];

	sort(adv.begin(), adv.end());
	sort(nlog.begin(), nlog.end());

	int my_soldier = s-1, adv_soldier = s-1, ans = 0;

	while(my_soldier >= 0 && adv_soldier >= 0){
		if(nlog[my_soldier] > adv[adv_soldier]){
			ans++; 	my_soldier--;
		}
		adv_soldier--;
	}

	cout << ans << endl;

	return 0;
}
