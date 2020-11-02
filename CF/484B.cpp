#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 5000100;
const LL INF = 1e18 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[SZ],b[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read(),b[a[i]]=a[i];
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-a-1;
    for(int i = 1;i <= 2e6;i ++) b[i] = max(b[i],b[i-1]);
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        int x = a[i];
        for(int j = 2*x;j <= 2e6;j += x)
            ans = max(ans,b[j-1]%x);
    }
    cout << ans << endl;
}
