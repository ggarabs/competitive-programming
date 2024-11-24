#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 16, maxm = (1 << 15) + 10;
const int INF = 1e9;

int n, m;
int mat[maxn][maxn], dp[maxm][maxn];

bool ligado(int n, int j){
	return n & (1 << j); // n é o número original e (1 << j) desloca o bit 1 j posições para a esquerda;
}

void ligar(int &n, int j){
	n = n | (1 << j); // liga o j-ésimo bit
}

int solve(int mask, int k){ // mask é conjunto de cidades já visitadas e k é a última que foi visitada
	if(mask == (1 << n) - 1) return dp[mask][k] = 0; // se todas já foram visitadas, a distancia atual é nula;
	
	if(dp[mask][k] != -1) return dp[mask][k];

	int ans = INF;

	for(int i = 0; i < n; i++){
		if(ligado(mask, i) || !mat[k][i]) continue; // se o vértice atual já existir ou não existir rota
		
		ans = min(ans, solve(mask | (1 << i), i) + mat[k][i]); // pego o mínimo entre ir para cada vizinho
	}

	return dp[mask][k] = ans;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m;

	while(m--)
	{
		int a, b, w;
		cin >> a >> b >> w;
		mat[a][b] = mat[b][a] = w;
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(1, 0) << "\n"; // começando da cidade 0

	return 0;
}
