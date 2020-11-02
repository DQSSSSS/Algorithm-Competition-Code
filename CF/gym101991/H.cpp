#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL mod;

LL ksm(LL a,LL b) {
    a %= mod;
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL ksm(LL a,LL b,LL mod)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1) ans = ((ans % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
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

map<LL,LL> Hash;

LL BSGS(LL a,LL b,LL mod) //a^x = b (% mod)
{
    a %= mod; b %= mod;
    if(a == 0 && b == 0) return 1;
    else if(a == 0) return -1;
    Hash.clear();
    LL m = ceil(sqrt(mod));
    LL amni = ksm(a,mod - m - 1,mod);
    LL t = 1;
    Hash[t] = 0;
    for(int i = 1;i < m;i ++)
    {
        t = (t * a) % mod;
        if(t != 1 && !Hash[t])
            Hash[t] = i;
    }
    for(int i = 0;i <= m - 1;i ++)
    {
        LL ans = Hash[b];
        if(b == 1 || ans)
        {
            return i * m + ans;
        }
        b = (b * amni) % mod;
    }
    return -1;
}


int main() {
    freopen("hawawshi.in","r",stdin);
    int T = read();
    while(T --) {
        LL N,X,A,B,a,b;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&N,&X,&A,&B,&a,&b,&mod);
        int ans = 0;
        for(int R0 = A;R0 <= B;R0 ++) {
            if(a == 1) {
                LL k = (X - R0) * ksm(b,mod-2) % mod;
                k %= mod; k += mod; k %= mod;
                if(k < N) ans ++;
            }
            else {
                LL you = (X - b * ksm(1-a,mod-2) % mod) % mod;
                LL zuo = (R0-b*ksm(1-a,mod-2)%mod) % mod;
                if(zuo == 0) {
                    if(you == 0) ans ++;
                }
                else {
                    LL D = you * ksm(zuo,mod-2) % mod;
                    LL x = BSGS(a,D,mod);
                    //cout << a << " " << D << " " << x << endl;
                    if(x != -1 && x < N) ans ++;
                }
            }
        }
        int len = B-A+1,d = __gcd(len,ans);
        printf("%d/%d\n",ans/d,len/d);
    }
}

/**
5
2 2 4 5 2 1 7
6 3 4 5 2 1 7
2 2 1 5 2 1 7
4 5 5 5 4 7 11
4 6 5 5 4 7 11

5
4 5 5 5 4 7 11

*/
