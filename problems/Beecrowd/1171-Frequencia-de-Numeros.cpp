#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	map <int, int> freq;

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(freq.find(x) != freq.end()) freq[x]++;
		else freq[x] = 1;
	}

	for(map<int, int>::iterator it = freq.begin(); it != freq.end(); it++){
		cout << it->first << " aparece " << it->second << " vez(es)" << endl;
	}

	return 0;
}
