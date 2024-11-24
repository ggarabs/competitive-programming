#include <bits/stdc++.h>
#define MAXN 10007

using namespace std;

int volunteers[MAXN];

int main(){
	int n, r;
	cin >> n >> r;

	for(int i = 0; i < r; i++){
		int aux;
		cin >> aux;
		volunteers[aux]++;
	}

	bool flag = false;

	for(int i = 1; i <= n; i++){
		if(!volunteers[i]){
			cout << i << " ";
			flag = true;
		}
	}

	if(!flag) cout << '*';
	cout << endl;

	return 0;
}
