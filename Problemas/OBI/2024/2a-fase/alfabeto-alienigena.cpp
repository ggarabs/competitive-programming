#include <bits/stdc++.h>

using namespace std;

int main(){
	int k, n; cin >> k >> n;

	set <char> dic;

	for(int i = 0; i < k; i++){
		char letter; cin >> letter;
		dic.insert(letter);
	}

	string msg; cin >> msg;

	for(char aux : msg){
		if(dic.find(aux) == dic.end()){
			cout << "N" << endl;
			return 0;
		}
	}

	cout << "S" << endl;

	return 0;
}
