#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}


int n,a[SZ],f[SZ],h[SZ];
vector<int> g[SZ];

LL work(LL x) { /// __gcd(s,n) = x
    for(int i = 0;i <= 2*n;i ++) f[i] = 0,h[i] = 0;
    for(int i = 0;i < x;i ++) {
        int maxn = 0;
        for(int j = i;j < n;j += x) {
            maxn = max(maxn,a[j]);
        }
        for(int j = i;j < n;j += x) {
            if(maxn == a[j])
                f[j] = 1;
        }
    }


    for(int s : g[x]) h[s] ++;

    for(int i = 1;i <= 2*n;i ++) {
        h[i] += h[i-1];
    }
    /// h[i]: 小于等于i的数中有多少数是s
    for(int i = 0;i < n;i ++) f[i + n] = f[i];
    for(int i = 1;i < 2*n;i ++) {
        if(f[i]) {
            f[i] += f[i-1];
        }
    }
    LL ans = 0;
    //cout << ans << endl;
    for(int i = n;i < 2*n;i ++) {
        int l = i-n+2,r = f[i];
        ans += h[r];
    }
  //  cout << x << " " << ans << endl;
  //  for(int i = 0;i < 2*n;i ++) printf("%d ",f[i]); puts("");
  //  for(int i = 0;i < 2*n;i ++) printf("%d ",h[i]); puts("");
    return ans;
}

int main() {
    n = read();
    for(int i = 0;i < n;i ++) a[i] = read();
    for(int s = 1;s < n;s ++) {
        g[__gcd(s,n)].push_back(s);
    }
    LL ans = 0;
    for(int i = 1;i < n;i ++) {
        if(n % i == 0) {
            ans += work(i);
        }
    }
    cout << ans << endl;
}
/*
10
1 1 1 1 1 1 1 1 1 1
6
1 1 1 1 1 1
4
1 1 1 1
*/
