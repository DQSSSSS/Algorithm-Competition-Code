#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

int pri[SZ];
bool vis[SZ];

void shai(int n) {
    int tot = 0;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) break;
        }
    }
}

LL get(LL n,int mi) {
    LL l = 0,r = n;
    while(r-l>1) {
        LL mid = l + r >> 1;
        LL x = n;
        for(int i = 1;i <= mi;i ++) x /= mid;
        if(x == 0) r = mid;
        else l = mid;
    }
    return l;
}

int main() {
//    freopen("1.in","w",stdout);
//    int N = 50000; printf("%d\n",N); while(N --) puts("996491788296388609");
    //freopen("1.in","r",stdin); freopen("1.out","w",stdout);
    shai(5000);
    int T = read();
    while(T --) {
        LL n; scanf("%lld",&n);
        int ans = INF;
        for(int k = 1;;k ++) {
            LL p = pri[k];
            if(p * p * p * p > n/p) break;
            int t = 0;
            while(n%p == 0) n/=p,t++;
            if(t) ans = min(ans,t);
        }
        if(n == 1) printf("%d\n",ans);
        else {
            LL x = get(n,4);
            if(x * x * x * x == n) ans = min(ans,4);
            else {
                x = get(n,3);
                if(x * x * x == n) ans = min(ans,3);
                else {
                    x = get(n,2);
                    if(x * x == n) ans = min(ans,2);
                    else ans = 1;
                }
            }
            printf("%d\n",ans);
        }
    }
}
