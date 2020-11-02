#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int a[SZ],c[SZ];
multiset<int> s;

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) s.insert(read());
    for(int i = 1;i <= n;i ++) {
        int x = a[i];
        auto it1 = s.lower_bound(0);
        auto it2 = s.lower_bound(n-x);
        if(it2 == s.end() || (*it1+x)%n < (*it2+x)%n) c[i] = (*it1+x)%n,s.erase(it1);
        else c[i] = (*it2+x)%n,s.erase(it2);
    }
    for(int i = 1;i <= n;i ++) printf("%d ",c[i]);
}

