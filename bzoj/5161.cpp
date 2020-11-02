#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
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
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
/*
int tmp[2333],num[233],use[233];

void dfs(int d,int n) {
    if(d == n + 1) {
        int tt[n+1] = {0};
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j < i;j ++) {
                if(num[j] < num[i])
                    tt[num[i]] = max(tt[num[i]],tt[num[j]]+1);
            }
        }
        for(int i = 1;i <= n;i ++) tt[i] = max(tt[i],tt[i-1]);
        int S = 0;
        for(int i = 2;i <= n;i ++)
            S |= (tt[i]-tt[i-1]) << (i-2);
        tmp[S] ++;
        return ;
    }
    for(int i = 1;i <= n;i ++) {
        if(!use[i]) {
            use[i] = 1;
            num[d] = i;
            dfs(d+1,n);
            use[i] = 0;
        }
    }
}
*/
/*
int f[2][134217730];

void work(int n) {
    memset(f,0,sizeof f);
    f[1][0] = 1;
    for(int i = 2,cur = 0,fac=2;i <= n;i ++,cur^=1,fac=1ll*fac*i%mod) {
        memset(f[cur],0,sizeof f[cur]);
        for(int S = 0;S < (1 << (i-2));S ++) {
            int pre[33] = {0};
            for(int j = i - 2,ans = -1;j >= 0;j --) {
                if(S >> j & 1) ans = j;
                pre[j] = ans;
            }
            for(int j = 1;j <= i;j ++) {
                int di = -1,gao = -1,one = -1;
                if(j == 1)
                    one = S << 1;
                else if(j == i)
                    one = S ^ (1 << (j-2));
                else {
                    di = S & ((1<<(j-2))-1);
                    if(pre[j-2] != -1) gao = ((S ^ di ^ (1<<pre[j-2])) << 1);
                    else gao = ((S ^ di) << 1);
                    one = di ^ gao ^ (1<<(j-2));
                }
                (f[cur][one] += f[cur^1][S]) %= mod;
            }
        }
        int ans = 0;
        for(int S = 0;S < (1<<(i-1));S ++) {
            int t = 1;
            for(int j = 0;j < n-1;j ++)
                if(S >> j & 1) t ++;
            (ans += 1ll * f[cur][S] * t % mod) %= mod;
        }
        cout << ans *ksm(fac,mod-2)%mod<< ",";
    }
}
*/
int biao[] = {0,1,499122178,2,915057326,540715694,946945688,422867403,451091574,317868537,200489273,976705134,705376344,662845575,331522185,228644314,262819964,686801362,495111839,947040129,414835038,696340671,749077581,301075008,314644758,102117126,819818153,273498600,267588741};

int main() {
    int n = read();
    printf("%d\n",biao[n]);
    return 0;
}
