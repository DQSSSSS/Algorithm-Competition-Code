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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL k;
int a[SZ],m,b[SZ];
LL f[SZ][2];

LL dfs(int l,int b) {
    if(f[l][b] != -1) return f[l][b];
    if(b == 1) return f[l][b] = (k-1)*dfs(l-1,0)%mod;
    else return f[l][b] = (dfs(l-1,1)+(k-2)*dfs(l-1,0)%mod)%mod;
}

LL work(int n) {
    //for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
    LL ans = 1;
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i < n && a[i] == a[i + 1] && a[i] != -1) return 0;
        if(a[i] == -1 && (i == n || a[i+1] != -1)) {
            int len = i - lst + 1;
            LL d;
            if(a[lst-1] == 0 && a[i+1] == k+1) {
                d = k * ksm(k-1,len-1) % mod;
            }
            else if(a[lst-1] == 0 || a[i+1] == k+1) {
                d = ksm(k-1,len);
            }
            else if(a[lst-1] == a[i+1]) d = dfs(len,1);
            else d = dfs(len,0);
            ans = ans * d % mod;
       //     cout << lst << " "<< i << " " << d << endl;
        }
        if(a[i] != -1) lst = i + 1;
    }
    return ans;
}

int main() {
    m = read(),k = read();
    for(int i = 1;i <= m;i ++) b[i] = read();

    memset(f,-1,sizeof f);
    f[1][0] = k - 2; f[1][1] = k - 1;

    LL ans = 1;

    int n = 0;
    for(int i = 1;i <= m;i ++) if(i%2) a[++ n] = b[i]; a[n+1]=k+1;
    ans = ans * work(n) % mod;

    n = 0;
    for(int i = 1;i <= m;i ++) if(i%2==0) a[++ n] = b[i]; a[n+1]=k+1;
    ans = ans * work(n) % mod;

    cout << ans << endl;
}



