void prefix(int x){
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

void infix(int x){
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

void posfix(int x){
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
