#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main() {
  char aux;
  int x_0, x_f, y_0, y_f, cont = 0;

  cin >> aux;
  x_0 = aux - 'a';
  cin >> y_0;

  cin >> aux;
  x_f = aux - 'a';
  cin >> y_f;

  vector <string> steps;

  while (x_f != x_0 || y_f != y_0) {
    if (x_f > x_0) {
      if (y_f > y_0) {
        steps.pb("RU");
        y_0++;
      } else if (y_f < y_0) {
        steps.pb("RD");
        y_0--;
      } else {
        steps.pb("R");
      }
      x_0++;
    } else if (x_f < x_0) {
      if (y_f > y_0) {
        steps.pb("LU");
        y_0++;
      } else if (y_f < y_0) {
        steps.pb("LD");
        y_0--;
      } else {
        steps.pb("L");
      }
      x_0--;
    } else {
      if (y_f > y_0) {
        steps.pb("U");
        y_0++;
      } else if (y_f < y_0) {
        steps.pb("D");
        y_0--;
      }
    }
    cont++;
  }
  cout << cont << endl;
  for(int i = 0; i < steps.size(); i++) cout << steps[i] << endl;
  return 0;
}