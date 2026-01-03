#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

void quick_sort(int A[], int l, int r, int target) {
  if (l == r) {
      cout << A[l];
      return;  // 递归终止
}
  // 两个边界要向外面扩大一格，因为我们后面做的是do while
  int i = l - 1;
  int j = r + 1;
  int x = (i + j) /
          2;  // 确定枢轴元素，第一次我们就干到中间，这样就能让一趟有两次递归了
  int pivot = A[x];

  while (i < j) {
    do i++;
    while (A[i] < pivot);
    do j--;
    while (A[j] > pivot);
    if (i < j) swap(A[i], A[j]);
  }
  if(target <= j) return quick_sort(A,l,j,target); // 剪枝操作，因为排序完的序列肯定是递增的，所以我们只需要对第k的元素所在的区间用快排就行了，最后top k肯定落在那一段上
  else return quick_sort(A,j+1,r,target);
}

int main() {
  int a[N];
  int n;
  int target_idx;
  cin >> n;
  cin >> target_idx;
  target_idx -= 1; // 适应数组下标
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  quick_sort(a, 0, n - 1,target_idx );


  return 0;
}