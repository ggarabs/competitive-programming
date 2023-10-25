#include <bits/stdc++.h>
#define MAXN 87

using namespace std;

int value[MAXN];

int main(){
	string matring[4];

	for(int i = 0; i < 4; i++) cin >> matring[i];

	for(int i = 0; i < matring[0].size(); i++){
		for(int j = 0; j < 4; j++) value[i] += (matring[j][i] - '0')*pow(10, 3-j);
	}

	for(int i = 1; i+1 < matring[0].size(); i++){
		cout << (char)((value[0]*value[i]+value[matring[0].size()-1])%257);
	}
	cout << endl;

	return 0;
}
