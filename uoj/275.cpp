#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 110;
const int mod = 1e9 + 7;
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

LL ni2,p;

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

bool checkbl(int n,int m) {
    while(n || m) {
        if(n%p<m%p) return false;
        n/=p; m/=p;
    }
    return true;
}
LL bl(int n,int m) {
    LL ans = 0;
    for(int i = 0;i <= n;i ++)
        for(int j = 0;j <= i;j ++)
            ans += checkbl(i,j);
    return ans;
}

LL a[SZ],b[SZ],f[SZ][2][2];
/// i,n,m
LL get(LL x,LL y) {
    x++; y++;
    y=min(x,y);
    return ((x-y)%mod*y%mod+y%mod*((y+1)%mod)%mod*ni2%mod%mod)%mod;
}

int main() {
    ni2 = ksm(2,mod-2);
    int T = read();
    p = read();
    while(T --) {
        LL n = read(),m = read();
        m = min(n,m);
        LL tmp = ((n+1)%mod*((m+1)%mod)%mod-(m%mod)*((m+1)%mod)%mod*ni2%mod+mod)%mod;

        //cout << bl(n,m) << endl;
        memset(f,0,sizeof f);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        int ln = 0,lm = 0;
        while(n) a[++ln]=n%p,n/=p;
        while(m) b[++lm]=m%p,m/=p;
        int len = max(ln,lm);
        reverse(a+1,a+1+len);
        reverse(b+1,b+1+len);

        //for(int i = 1;i <= len;i ++) printf("%4d",a[i]); puts("");
        //for(int i = 1;i <= len;i ++) printf("%4d",b[i]); puts("");


        f[0][1][1] = 1;
        for(int i = 1;i <= len;i ++) {
            (f[i][0][0] += f[i-1][0][0]*get(p-1,p-1)%mod) %= mod;

            (f[i][0][0] += f[i-1][0][1]*get(p-1,b[i]-1)%mod) %= mod;
            (f[i][0][1] += f[i-1][0][1]*((p-b[i])%mod)%mod) %= mod;

            (f[i][0][0] += f[i-1][1][0]*get(a[i]-1,p-1)%mod) %= mod;
            (f[i][1][0] += f[i-1][1][0]*((a[i]+1)%mod)%mod) %= mod;

            (f[i][0][0] += f[i-1][1][1]*get(a[i]-1,b[i]-1)%mod) %= mod;
            (f[i][0][1] += f[i-1][1][1]*(max(0ll,a[i]-b[i])%mod)%mod) %= mod;
            (f[i][1][0] += f[i-1][1][1]*(min(a[i]+1,b[i])%mod)%mod) %= mod;
            (f[i][1][1] += f[i-1][1][1]*(a[i]>=b[i])%mod) %= mod;
        }
      /*  for(int l = 0;l <= len;l ++) {
            printf("%3d:",l);
            for(int i = 0;i <= 1;i ++)
                for(int j = 0;j <= 1;j ++)
                    printf("%10d",f[l][i][j]);
            puts("");
        }*/
        LL ans = 0;
        ans += f[len][0][0];
        ans += f[len][0][1];
        ans += f[len][1][1];
        ans += f[len][1][0];
       // cout << tmp << " " << ans << endl;
        ans = ((tmp-ans)%mod+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
/**
100 79
92 96
83 22
*/
