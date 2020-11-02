#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4000010;
const int INF = 1e9 + 10;
const int mod = 10007;
const LD eps = 1e-8;
LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

char s[111];

int main() {
    int n = read();
    vector<int> a;
    for(int i = 1;i <= n;i ++) {
        scanf("%s",s);
        string ss = s;
        if(ss.size() >= 10) continue;
        else if(ss[0] == '-') continue;
        else {
            int x = 0;
            for(int j = 0;j < ss.size();j ++) {
                x = x * 10 + ss[j] - '0';
            }
            a.push_back(x);
        }
    }
    sort(a.begin(),a.end());
    for(int i = 0;i < a.size();i ++) {
        if(a[i] != i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << a.size() << endl;
}

