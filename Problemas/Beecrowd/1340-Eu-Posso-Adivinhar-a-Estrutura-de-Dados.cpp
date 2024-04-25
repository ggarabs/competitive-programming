#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		stack <int> s; queue <int> q; priority_queue <int, vector<int>> pq;
		bool is_stack = true, is_queue = true, is_pq = true;
		for(int i = 0; i < n; i++){
			int op, x; cin >> op >> x;
			if(op == 1){ s.push(x); q.push(x); pq.push(x); }
			else{
				if(is_stack && !s.empty() && s.top() == x) s.pop();
				else is_stack = false;

				if(is_queue && !q.empty() && q.front() == x) q.pop();
				else is_queue = false;

				if(is_pq && !pq.empty() && pq.top() == x) pq.pop();
				else is_pq = false;
			}
		}
		if(!is_stack && !is_queue && !is_pq) cout << "impossible" << endl;
		else if(is_stack && !is_queue && !is_pq) cout << "stack" << endl;
		else if(!is_stack && is_queue && !is_pq) cout << "queue" << endl;
		else if(!is_stack && !is_queue && is_pq) cout << "priority queue" << endl;
		else cout << "not sure" << endl;
	}
}
