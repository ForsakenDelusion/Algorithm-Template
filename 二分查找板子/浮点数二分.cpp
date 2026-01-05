#include <bits/stdc++.h>

using namespace std;

double bs_float(double a) {
  double min = -50;
  double max = 50;
  double mid;
  while (abs(mid * mid * mid - a) > 1e-9) {  // 这里开得也太大了
    mid = (min + max) / 2;
    if (mid * mid * mid >= a) {
      max = mid;
    } else {
      min = mid;
    }
  }
  return mid;
}

int main() {
  double elem;
  cin >> elem;
  double res = bs_float(elem);
  printf("%.6f", res);
  return 0;
}