#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string word, new_word; cin >> word;

		new_word = word;

		reverse(new_word.begin(), new_word.end());
		new_word += word;

		if(word < new_word) cout << word << endl;
		else cout << new_word << endl;
	}
	return 0;
}
