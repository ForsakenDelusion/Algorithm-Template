#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];
int res = 0;

void merge_sort(int l, int r) {
  if (l == r) return;  // 递归终止
  int mid = (l + r) >> 1;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);  // 归并拆分成独立元素

  // 开始归并排序
  int i = l, j = mid + 1, k = l;  // 这里的i注意是从l开始，不是0！
  while (i <= mid && j <= r) {
    if (a[i] <= a[j])
      b[k++] = a[i++];
    else
      b[k++] = a[j++],res = mid - i + 1; // 逆序对思想的核心
  }
  while (i <= mid) b[k++] = a[i++];
  while (j <= r) b[k++] = a[j++];

  for (int i = l; i <= r; i++) a[i] = b[i];  // 这里的i注意是从l开始，不是0！
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  merge_sort(0, n - 1);

  cout << res;

  return 0;
}