int tsp(int mask, int i)
{

	if(mask == (1 << n) - 1) return dp[mask][i] = 0; // caso todas as cidades já tenham sido visitadas

	if(dp[mask][i] != -1) return dp[mask][i]; // se a DP ja foi calculada
	
	int ans = 1e9;
	
	for(int v = 0; v < n; v++)
	{
		if(mask & (1 << v) or !dp[i][v]) continue; // se a cidade atual já foi visitada ou não há rota de i à v

		ans = min(ans, tsp((mask | (1 << v)), v) + dp[i][v]); //pego o minimo entre ir para cada vizinho

	}

	return dp[mask][i] = ans;
}
