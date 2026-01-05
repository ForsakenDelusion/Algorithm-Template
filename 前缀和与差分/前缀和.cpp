#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N], S[N];

void prefixed();

void prefixed(int n) {
  S[0] = 0;
  for (int i = 1; i <= n; i++) {
    S[i] = S[i - 1] + a[i];
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  prefixed(n);

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    cout << S[r] - S[l - 1] << endl;
  }

  return 0;
}