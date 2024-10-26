void tsp(int n){
	dp[1][0] = 0;

	int mask;

	for (mask = 1; mask < (1 << n); mask+=2) {
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) continue;

			for (int j = 0; j < n; j++) {
				if (mask & (1 << j) || !dist_pc[i][j]) continue;

				dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist_pc[i][j]);
			}
		}
	}
}