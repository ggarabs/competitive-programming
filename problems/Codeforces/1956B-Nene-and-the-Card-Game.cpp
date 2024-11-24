#include <bits/stdc++.h>

using namespace std;

int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int>cards(n+1, 0);
    int pts = 0;
    for(int i = 0; i < n; i++){
      int aux; cin >> aux;
      cards[aux]++;
      if(cards[aux] == 2) pts++;
    }
  cout << pts << endl;
  }
  return 0;  
}
