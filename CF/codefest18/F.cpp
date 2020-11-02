#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int a[SZ],L[SZ],R[SZ],S[SZ],top,n,k;

LL ask_sum(LL a1,LL m,LL d) {
    a1 %= mod; m %= mod; d %= mod;
    return (a1 * m % mod + 1ll * m * (m - 1) % mod * 500000004 % mod * d % mod) % mod;
}
/*
int t[SZ];

LL baoli(int a[],LL n,LL k) {
	if(n < k) return 0;
    int b[n + k] = {0};
    LL ans = 0;
    for(int i = 1;i <= n - k + 1;i ++) {
    	int tmp = a[i];
    	for(int j = i;j <= i + k - 1;j ++)
			tmp = max(tmp,a[j]);
		b[++ b[0]] = tmp;
		ans += tmp;
		t[tmp] ++;
    }
    return ans + baoli(b,b[0],k);
}
*/
LL calc(LL l,LL r) {
    if(r - l + 1 < k) return 0;
    LL n = r - l + 1,t = (n - k) / (k - 1) + 1;
    n %= mod; t %= mod;
    return n * t % mod - t * (t + 1) % mod * 500000004 % mod * (k - 1) % mod;
}

int main() {
    n = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
	S[top = 0] = 0;
    for(int i = 1;i <= n;i ++) {
        while(top && a[S[top]] <= a[i]) top --;
        L[i] = top ? S[top] + 1 : 1;
        S[++ top] = i;
    }
	S[top = 0] = 0;
    for(int i = n;i >= 1;i --) {
        while(top && a[S[top]] < a[i]) top --;
        R[i] = top ? S[top] - 1 : n;
        S[++ top] = i;
    }

    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        int l = L[i],r = R[i];
        LL num = calc(l,r) - calc(i + 1,r) - calc(l,i - 1);
        (ans += num % mod * a[i] % mod) %= mod;
    }
    ans += mod; ans %= mod;
    cout << ans << endl;
   // cout << baoli(a,n,k) << endl;
    return 0;
}
/**
5 2
16 9 5 8 7

5 4
1 1 1 1 1
*/
