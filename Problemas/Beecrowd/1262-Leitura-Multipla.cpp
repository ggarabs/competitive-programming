#include <bits/stdc++.h>

using namespace std;

int main(){
	string rastro; int num;
	while(cin >> rastro >> num){
		int ans = 0, part = 0;
		for(int i = 0; i < rastro.size(); i++){
			if(rastro[i] == 'W'){
				if(part > 0){
					ans++;
					part = 0;
				}
				ans++;
			}else{
				if(part == num){
					part = 0;
					ans++;
				}
				part++;
			}
		}
		if(part > 0) ans++;
		cout << ans << endl;
	}
	return 0;
}
