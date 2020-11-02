#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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

pii a[SZ];
multiset<int> s;

int main() {
    int n = read();
    int ans = 0;
    for(int i = 2;i < n;i ++) ans += i * (i+1);
    cout << ans << endl;
}
/**
5 3
100 1
10 2
5 3
2 4
6 5
*/

