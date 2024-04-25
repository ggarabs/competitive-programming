#include <bits/stdc++.h>

using namespace std;

const string face = "F A C E";

bool is_palindrome(string test, string top){
	for(int i = 0; i < 7; i += 2) if(test[i] != top[6-i]) return false;
	return true;
}

int main(){
	int n; cin >> n;
	getchar();

	stack <string> placar;
	int ans = 0;

	for(int i = 0; i < n; i++){
		if(placar.empty()) placar.push(face);
		string aux;
		getline(cin, aux);
		if(is_palindrome(aux, placar.top())){
			placar.pop();
			ans++;
		}else placar.push(aux);
	}

	cout << ans << endl;

	return 0;
}
