#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e5 + 3;
const LD eps = 1e-8;

int read() {
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}
int fp(int x,int y,int p){
    int ans = 1;
    while(y) {
        if(y&1) ans = 1ll*x * ans % p;
        x = 1ll*x * x % p;
        y >>= 1;
    }
    return ans;
}
int inv(int x,int p){
    return fp(x,p-2,p);
}

int head[SZ],nxt[SZ],tot = 0;
pii val[SZ];
vector<int> lst;
void add(int x,int y) {
    int k = x % mod;
    if(!head[k]) lst.push_back(k);
    val[++ tot] = make_pair(x,y);
    nxt[tot] = head[k];
    head[k] = tot;
}

bool exist(int x) {
    int k = x % mod;
    for(int i = head[k];i;i = nxt[i]) {
        if(val[i].first == x) return true;
    }
    return false;
}

int ask(int x) {
    int k = x % mod;
    for(int i = head[k];i;i = nxt[i]) {
        if(val[i].first == x) return val[i].second;
    }
}

LL n;
int x0,a,b,p,C[2000010];
int w33ha(){
    scanf("%lld",&n);
    x0=read();
    a=read();
    b=read();
    p=read();
    n=min(n,(p)*1ll);
    tot = 0;
    for(int x : lst) head[x%mod] = 0;
    lst.clear();

    int q=read();
    int B = sqrt(n * q);
    for(int i = 0,j = 1;i < B;i ++) {
        if(!exist(j)) add(j,i);
        j = 1ll * j * a % p;
    }

    C[0] = 1;
    for(int i = 1,x = inv(fp(a,B,p),p);i <= n / B;i ++) {
        C[i] = 1ll * C[i - 1] * x % p;
    }

    while(q--){
        int v=read();
        if(a==0){
            if(v==x0)puts("0");
            else if(b!=v)puts("-1");
            else puts("1");
        }
        else if(a==1){
            if(v==x0) {puts("0");continue;}
            if(b==0) puts("-1");
            else {
                v=(v-x0+p)%p;
                int pos=(1ll*v*inv(b,p))%p;
                if(pos>=n)puts("-1");
                else printf("%d\n",pos);
            }
        }
        else{
            if(v==x0){
                puts("0");
                continue;
            }
            int rc,ra,rb=inv(b,p);
            ra=inv(a-1,p);
            rc=(0LL+x0+((1LL*b*ra)%p)+p)%p;
            v=(v+(1ll*b*ra)%p)%p;
            v=(1ll*v*inv(rc,p))%p;
            int ans = 2e9;
            for(int i = 0;i <= n / B;i ++) {
                int x = 1ll * v * C[i] % p;
                if(exist(x)) {
                    ans = i * B + ask(x);
                    break;
                }
            }
            if(ans>=n) ans = -1;
            printf("%d\n",ans);
        }
    }
    return 0;
}
int main(){
    int T;scanf("%d",&T);
    while(T--)w33ha();
    return 0;
}
