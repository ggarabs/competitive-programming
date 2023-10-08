#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, l, c;

  while(cin >> n >> l >> c){
    int car = 0, lines = 0;
  
    for(int i = 0; i < n; i++){
      string pal;
      cin >> pal;
  
      car += (int)pal.size();
  
      if(car > c){
        car = (int)pal.size()+1;
        lines++;
      }else if(car == c){
        car = 0;
        lines++;
      }else{
        car += 1;
      }
    }
  
    if(car > 0) lines++;
  
    cout << ceil((double)lines/l) << endl;
  }

  return 0;    
}