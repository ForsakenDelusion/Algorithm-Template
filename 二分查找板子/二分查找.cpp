#include <bits/stdc++.h>

using namespace std;
int a[100010];

int bs_min(int *a,int n, int t){
     int l=-1,r=n+1;//开区间
  while(l+1<r){ //l+1=r时结束，因为有一个指针在可行区域，有一个指针不在
    int mid=(l+r)>>1;
    if(a[mid]>=t) r=mid; //中间值大于tarfet，说明t在左边，故让r逼近mid，最小化
    else l=mid;
  }
  return a[r]==t ? r : -1;
}

int bs_max(int *a,int n, int t){
     int l=-1,r=n;//开区间
  while(l+1<r){ //l+1=r时结束，因为有一个指针在可行区域，有一个指针不在
    int mid=(l+r)>>1;
    if(a[mid]<=t) l=mid; //中间值小于tarfet，说明t在右边，故让l逼近mid，最大化
    else r=mid;
  }
  return a[l]==t ? l : -1;
}

int main(){
    int n;
    int q_num;
    cin >> n >> q_num;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    for(int i = 0;i<q_num;i++){
        int q_elem;
        cin >> q_elem;
        int min = bs_min(a, n, q_elem);
        int max = bs_max(a, n, q_elem);
        cout << min << ' ' << max << endl;
    }

}