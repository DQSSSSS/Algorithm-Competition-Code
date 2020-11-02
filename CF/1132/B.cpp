#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

LL a[SZ];

int main() {
    int n = read();
    LL sum = 0;
    for(int i = 1;i <= n;i ++) a[i] = read(),sum += a[i];
    sort(a + 1, a + 1 + n);
    int m = read();
    while(m --) {
        int x = read();
        printf("%lld\n",sum-a[n-x+1]);
    }
}

