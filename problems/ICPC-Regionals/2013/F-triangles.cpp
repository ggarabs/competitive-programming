#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int prefix_sum[MAXN];

int binary_search(int begin, int end, int x){
	while(begin <= end){
		int mid = (begin+end)/2;

		if(prefix_sum[mid] == x) return mid;
		else if(prefix_sum[mid] < x) begin = mid+1;
		else end = mid-1;
	}
	return -1;
}

int main(){ _
	int n, dist[MAXN], sum = 0;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> dist[i];
		sum += dist[i];
		prefix_sum[i] = dist[i]+prefix_sum[i-1];
	}

	if(sum % 3 != 0){
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;

	set<int>aux;

	for(int i = 0; i <= n; i++){
		int first = binary_search(i+1, n, prefix_sum[i]+sum/3);
		if(first == -1) continue;
		if(aux.find(first) != aux.end()) break;
		int second = binary_search(first+1, n, prefix_sum[first]+sum/3);
		if(second != -1){
			ans++;
			aux.insert(second);
		}
	}

	cout << ans << endl;

	exit(0);
}
