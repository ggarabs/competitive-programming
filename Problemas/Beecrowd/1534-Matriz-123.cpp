#include <bits/stdc++.h>
#define MAXN 77

using namespace std;

int main(){
	int n;
	while(cin >> n){
		int matriz[MAXN][MAXN];

		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) matriz[i][j] = 3;

		for(int i = 0; i < n; i++) matriz[i][i] = 1;

		for(int i = 0; i < n; i++) matriz[i][n-1-i] = 2;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) cout << matriz[i][j];
			cout << endl;
		}
	}
	return 0;
}
