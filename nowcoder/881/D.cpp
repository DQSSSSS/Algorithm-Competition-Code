#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e6 + 10;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

const int inv2 = ksm(2,mod-2);

void fwt_xor(int *a,int N,int opt) {
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k) {
                int X=a[j+k],Y=a[i+j+k];
                a[j+k]=(X+Y)%mod;a[i+j+k]=(X+mod-Y)%mod;
                if(opt==-1)a[j+k]=1ll*a[j+k]*inv2%mod,a[i+j+k]=1ll*a[i+j+k]*inv2%mod;
            }
}

vector<int> a;
int f[SZ];

void dfs(int p,int m,int t,int tt) {
    if(p == m) { f[t] += tt; return ; }
    dfs(p+1,m,t,tt);
    dfs(p+1,m,t^a[p],-tt);
}

int main() {
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)) {
        for(int i = 0;i < (1<<k);i ++) f[i] = 0;
        for(int i = 1;i <= n;i ++){
            a.resize(m);
            for(int j = 0;j < m;j ++) a[j] = read();
            dfs(0,m,0,1);
        }
        fwt_xor(f,1<<k,1);
        int ans = 0,inv = ksm(1<<m,mod-2);
        for(int i = 0,t = 1;i < (1<<k);i ++,t = t * 3ll % mod) {
            ans ^= 1ll * f[i] * inv % mod * t % mod;
        }
        printf("%d\n",ans);
    }
}
