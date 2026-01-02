#include  <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> stovec(const string &a){
    vector<int> res;
    for(auto it = a.rbegin(); it != a.rend(); it++){
        res.push_back(*it - '0');
    }
    return res;
}

bool cmp(const vector <int> &A, const vector <int> &B){ // 判断是否A ≥ B
    if(A.size() != B.size()) return A.size() > B.size(); // 如果A、B长度不相同，长度长的那个数大
    for(int i = A.size() - 1;i >= 0;i --){ // 否则就要从最高位开始看（因为执行这个函数前，A和B数组都已经倒序，所以这里要从后往前看）
        if(A[i] != B[i]) return A[i] > B[i]; // 如果A的当前位和B的当前位不相等，当前位大的更大
    }
    return true; // 如果A、B数组都相等，这里可以直接返回true，当然也可以直接输出0
}


vector<int>  BigNumSub(const string &a, const string& b){


    vector<int> va,vb;
    vector<int> res;
    va = stovec(a);
    vb = stovec(b);
    if(!cmp(va,vb)) return BigNumSub(b, a); // 小数字减大数，不够减，转换为倒过来最后补一个负号

    int cn = 0; // 借位

    for (int i = 0;i < a.size();i++) {
        int c;
        c = va[i] - cn;
        if(i < b.size()) c -= vb[i];
        cn = 0;
        if(va[i] < vb[i]) cn = 1;
        res.push_back((c+10)%10);
    }
    return res;
}

int main(){

    string a,b;
    cin >> a >> b;
    vector<int> res;
    res = BigNumSub(a, b);
    if(!cmp(stovec(a),stovec(b))) cout << '-';
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];  
    }

    return 0;
}