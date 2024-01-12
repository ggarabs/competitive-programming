#include <bits/stdc++.h>
#define MAXN 200007
  
using namespace std;
  
long long int prefix_sum[MAXN];
  
int busca_b(long long int total, int n){
  int ini = 0, fim = n;
  while(ini < fim){
    int meio = (ini+fim)/2;
    if(prefix_sum[meio] == total/2) return meio;
    else if(prefix_sum[meio] > total/2) fim = meio-1;
    else ini = meio+1;
  }
  return ini;
}
  
int main(){
  int n, array[MAXN];
  cin >> n;
  
  array[0] = prefix_sum[0] = 0;
  for(int i = 1; i <= n; i++){
    cin >> array[i];
    prefix_sum[i] = array[i] + prefix_sum[i-1];
  }
  
  int r, l;
  r = l = busca_b(prefix_sum[n], n);
  
  for(;l >= 0 && r <= n;){
    long long int sum3 = prefix_sum[n]-prefix_sum[r], sum1 = prefix_sum[l]-prefix_sum[0];
    if(sum1 == sum3){
      cout << sum1 << endl;
      return 0;
    }else if(sum1 > sum3) l--;
    else r++;
  }
  
  cout << 0 << endl;
  
  return 0;  
}
