#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100100;
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

LL ksm(LL a,LL b,LL mod)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b == 0)
    {
        x = 1; y = 0;
        return a;
    }
    LL d = exgcd(b,a % b,x,y);
    LL t = x; x = y; y = t - a / b * y;
    return d;
}

LL get_exgcd(LL a,LL b,LL c) //ax+by=c
{
    LL x,y;
    LL d = exgcd(a,b,x,y);
    if(c % d) return -1;
    return ((x * (c / d)) % (b / d) + (b / d)) % (b / d);
}

map<LL,LL> h;

LL BSGS(LL a,LL b,LL mod) //a^x = b (% mod)
{
    if(a == 0 && b == 0) return 1;
    else if(a == 0) return -1;
    h.clear();
    LL m = ceil(sqrt(mod));
    LL amni = ksm(a,mod - m - 1,mod);
    LL t = 1;
    h[t] = 0;
    for(int i = 1;i < m;i ++)
    {
        t = (t * a) % mod;
        if(t != 1 && !h[t])
            h[t] = i;
    }
    for(int i = 0;i <= m - 1;i ++)
    {
        LL ans = h[b];
        if(b == 1 || ans)
        {
            return i * m + ans;
        }
        b = (b * amni) % mod;
    }
    return -1;
}

struct matrix {
    int n,m;
    LL num[110][110];
}f,ans;

matrix operator *(const matrix &a,const matrix &b) {
    matrix ans;
    memset(ans.num,0,sizeof ans.num);
    ans.n = a.n; ans.m = b.m;
    for(int i = 1;i <= a.n;i ++)
        for(int j = 1;j <= b.m;j ++)
            for(int k = 1;k <= a.m;k ++)
                (ans.num[i][j] += a.num[i][k] * b.num[k][j] % (mod-1)) %= (mod-1);
    return ans;
}

LL b[233];

int main() {
    int k = read();
    for(int i = 1;i <= k;i ++) {
        b[k-i+1] = read();
    }
    int n = read(),fn = read();
    fn = BSGS(3,fn,mod);


    f.n = f.m = k;
    ans.n = ans.m = k;
    for(int i = 1;i <= k;i ++) f.num[k][i] = b[i];
    for(int i = 1;i < k;i ++) f.num[i][i+1] = 1;

    for(int i = 1;i <= k;i ++) ans.num[i][i] = 1;
    n --;
    while(n) {
        if(n & 1) ans = ans * f;
        f = f * f;
        n >>= 1;
    }
    LL A = ans.num[1][k],K,x;
    LL d = exgcd(A,mod-1,x,K);

    if(fn % d) { puts("-1"); return 0; }
    x %= mod - 1;
    x = fn / d * x % (mod - 1);
    x += mod-1; x %= mod-1;
    cout << ksm(3,x,mod) << endl;
    return 0;
}
