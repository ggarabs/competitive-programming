#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q; 
	
	while(cin >> n >> q){
    	vector <int> nums;
    	for(int i = 0; i < n; i++){
    		int x; cin >> x;
    		nums.push_back(x);
    	}
    
    	sort(nums.begin(), nums.end(), greater<>());
    
    	for(int i = 0; i < q; i++){
    		int x; cin >> x;
    		cout << nums[x-1] << endl;
    	}
	}

	return 0;
}

