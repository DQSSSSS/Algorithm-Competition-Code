#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
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

LL n,k,A,B;
LL a[SZ];

LL dfs(int l,int r) {
    int L = lower_bound(a + 1,a + 1 + k,l) - a;
    int R = upper_bound(a + 1,a + 1 + k,r) - a; R --;
    if(L > R) {
        return A;
    }
    LL num = R - L + 1;
    if(l == r) {
        return B * num * (r-l+1);
    }
    //cout << l << " " << r << " " << L << " "<< R << endl;
    int mid = l + r >> 1;
    return min(dfs(l,mid)+dfs(mid+1,r),B*num*(r-l+1));
}

int main() {
    n = read(),k = read(),A = read(),B = read();
    for(int i = 1;i <= k;i ++) a[i] = read();
    sort(a +1,a + 1 + k);
    cout << dfs(1,1<<n);
    return 0;
}
