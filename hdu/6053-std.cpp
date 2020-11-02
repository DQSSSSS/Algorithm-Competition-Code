#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f
#define random(a,b) ((a)+rand()%((b)-(a)+1))
#define ms(x,v) memset((x),(v),sizeof(x))
using namespace std;
const int MOD = 1e9+7;
const double eps = 1e-8;
typedef long long LL;
typedef long double DB;
typedef pair<int,int> Pair;
const int maxn = 1e5+10;

int mu[maxn],prime[maxn],cnt;
int sum[maxn];
void mobius(){
    cnt =0;
    mu[1] = 1;
    memset(prime,0,sizeof(prime));
    for(int i = 2 ; i<maxn ; ++i){
        if(!prime[i]){
            prime[cnt++] = i;
            mu[i] =-1;
        }
        for(int j=0 ; j<cnt && i*prime[j]<maxn ; ++j){
            prime[i*prime[j]] = 1;
            if(i%prime[j])mu[prime[j]*i] = -mu[i];
            else {
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }
    // sum_mu[0] = 0;
    // for(int i=1 ; i<maxn ; ++i)
    //     sum_mu[i] = sum_mu[i-1]+mu[i];
}
LL power_mod(LL x,LL n){
    LL ret =1;
    while (n) {
        if(n&1)ret = ret*x %MOD;
        x= x*x %MOD;
        n >>=1;
    }
    return ret;
}
int num[maxn];
inline LL F(){
    int sz =0;
    for(int i=1;  i<maxn ; ++i)
    if(num[i]){sz= i;break;}
    int maxv = 0;
    for(int i=maxn-1 ; i>=0 ; --i)
    if(num[i]){
        maxv = i;break;
    }
    maxv++;
    LL ans = 0;
    for(int d = 1 ; d <=sz; ++d){
        LL val =mu[d];
        if(val)
        for(int i=d; i<maxv ; i+=d){
            val *= power_mod(i/d,sum[min(i+d,maxv)-1]- sum[i-1]);
            val %= MOD;
        }
        ans += val;
        ans %=MOD;
    }
    return ans;
}

int main() {

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    int n;
    mobius();
    int T;
    scanf("%d",&T );
    int kase = 0;
    while (T--) {
        int n;
        scanf("%d",&n );

        ms(num,0);
        sum[0] = 0;
        for(int i=1;  i<=n ; ++i){
            int x; scanf("%d", &x);;num[x]++;
        }
        for(int i=1 ; i<maxn ; ++i){
            sum[i] = sum[i-1] + num[i];
        }
        LL ans = F();
        LL val = 1;
        for(int i=1 ; i<maxn ; ++i){
            val *= power_mod(i,num[i]);
            val %= MOD;
        }
        printf("Case #%d: %lld\n",++kase,(val-ans+MOD) %MOD );
    }
    return 0;
}
