#include  <bits/stdc++.h>
using namespace std;

vector<int> stovec(string &a){
    vector<int> res;
    for(auto it = a.rbegin(); it != a.rend(); it++){
        res.push_back(*it - '0');
    }
    return res;
}

vector<int>  BigNumPlus(string &a, string& b){

    if(b.size() > a.size()) return BigNumPlus(b, a); // 如果b比a大（b可能比a长了），这时候调转顺序，因为我们要以长的那个数为基准来模拟加的次数

    vector<int> va,vb;
    vector<int> res;
    va = stovec(a);
    vb = stovec(b);
    int cn = 0; // 进位

    for (int i = 0;i < a.size();i++) {
        int c;
        c = cn + va[i];
        if (i < b.size()) c += vb[i];
        res.push_back(c%10);
        cn = c/10;
    }

    if(cn) res.push_back(1);
    return res;
}

int main(){

    string a,b;
    cin >> a >> b;
    vector<int> res;
    res = BigNumPlus(a, b);

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];  
    }

    return 0;
}