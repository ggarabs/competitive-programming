#include <bits/stdc++.h>
#define MAXN 507

using namespace std;

pair <int, int> node[MAXN];
vector <int> mp;

void pre(int x){
	stack<int> st;
	st.push(x);

	while(!st.empty()){
		int curr = st.top();
		st.pop();
		cout << " " << mp[curr];

		if(node[curr].second != -1) st.push(node[curr].second);
		if(node[curr].first != -1) st.push(node[curr].first);
	}
}

void in(int x){
	stack<int> st;
	int curr = x;

	while(curr != -1 || !st.empty()){
		while(curr != -1){
			st.push(curr);
			curr = node[curr].first;
		}

		curr = st.top();
		st.pop();
		cout << " " << mp[curr];

		curr = node[curr].second;
	}
}

void pos(int x){
	stack <int> st1, st2;
	st1.push(x);

	while(!st1.empty()){
		int curr = st1.top();
		st1.pop();
		st2.push(curr);

		if(node[curr].first != -1) st1.push(node[curr].first);
		if(node[curr].second != -1) st1.push(node[curr].second);
	}

	while(!st2.empty()){
		cout << " " << mp[st2.top()];
		st2.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, it = 1; cin >> c;
	while(it <= c){
		int n; cin >> n;

		int root = -1;

		for(int i = 0; i < n; i++){
			int aux; cin >> aux;
			int curr = root;

			mp.push_back(aux);
			node[i] = {-1, -1};

			if(curr == -1){
				root = i;
				continue;
			}
			
			while(true){
				if(aux > mp[curr]){
					if(node[curr].second == -1){
						node[curr].second = i;
						break;
					}else curr = node[curr].second;	
				}else{
					if(node[curr].first == -1){
						node[curr].first = i;
						break;
					}else curr = node[curr].first;
				}
			}
		}

		cout << "Case " << it << ":" << endl;
		cout << "Pre.:";
		pre(root);
		cout << endl << "In..:";
		in(root);
		cout << endl << "Post:";
		pos(root);
		cout << endl << endl;

		it++;

		mp.clear();
	}
}
