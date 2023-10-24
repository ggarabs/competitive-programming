#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		string word;
		cin >> word;
		int shift;
		cin >> shift;

		for(int j = 0; j < word.size(); j++){
			char letter = (word[j]-shift);
			letter = letter < 'A' ? letter+26 : letter;
			cout << letter;
		}
		cout << endl;
	}

	return 0;
}
