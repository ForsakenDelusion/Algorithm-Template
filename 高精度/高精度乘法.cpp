#include <bits/stdc++.h>
using namespace std;

vector<int> C;

vector<int> stovec(string a) {
  vector<int> res;
  for (auto it = a.rbegin(); it < a.rend(); it++) {
    res.push_back(*it - '0');
  }
  return res;
}

void Great_mul(string a, int b) {
  vector<int> A = stovec(a);
  int t = 0;
  for (int i = 0; i < a.size() || t; i++) {
    int tmp;
    tmp = A[i] * b + t;
    C.push_back(tmp % 10);
    t = tmp / 10;
  }
  while (C.size() > 1 && C.back() == 0) C.pop_back();
}

int main() {
  string a;
  int b;
  cin >> a >> b;
  Great_mul(a, b);
  for (auto it = C.rbegin(); it != C.rend(); it++) {
    cout << *it;
  }

  return 0;
}