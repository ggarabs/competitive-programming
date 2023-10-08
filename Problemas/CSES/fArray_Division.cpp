#include <bits/stdc++.h>
#define MAXN 200007
#define INF 200000000000007

using namespace std;

int n, k, arr[MAXN];

bool solve(long long int x, bool *state){
	long long atual = 0;
	int cont = 0;
	for(int i = 0; i <= n; i++){
		atual += arr[i];
		if(atual >= x){
			if(atual == x){
				cout << "entrei" << endl;
				*state = true;
				atual = 0;
				if(i == n-1 || i == n) break;
			}else{
				atual = arr[i];
				if(atual > x) return false;
			}
			cont++;
		}
	}
	cout << cont << endl;
	return (cont < k);
}

long long int b_search(){
	long long int ini = 0, fim = INF;
	long long int ans = 0;
	while(ini <= fim){
		long long int meio = (ini+fim)/2;
		cout << ini << " " << fim << " " << meio << endl;
		bool soma = false;
		if(solve(meio, &soma)){
			fim = meio-1;
			if(soma) ans = meio;
		}
		else ini = meio+1;
	}
	return ans;
}

int main(){
	int maxv = 0;
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> arr[i];
		maxv = max(maxv, arr[i]);
	}
	arr[n] = 0;

	if(n == k) cout << maxv << endl;
	else cout << b_search() << endl;

	return 0;
}
