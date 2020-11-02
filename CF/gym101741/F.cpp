#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,int> pli;
typedef pair<int,int> pii;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 +a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL mul(LL a,LL b,LL p) {
    LL ans = 0;
    while(b) {
        if(b&1) ans = (a + ans) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ans;
}

LL ksm(LL a,LL b,LL p) {
    LL ans = 1 % p;
    while(b) {
        if(b&1) ans = mul(a,ans,p);
        a = mul(a,a,p);
        b >>= 1;
    }
    return ans;
}

namespace MR {
    bool check(LL a,LL n,LL x,LL t) {
        LL ans = ksm(a,x,n),lst = ans;
        for(int i = 1;i <= t;i ++) {
            ans = mul(ans,ans,n);
            if(ans == 1 && lst != 1 && lst != n - 1) return true;
            lst = ans;
        }
        if(ans != 1) return true;
        return false;
    }
    const int S = 8;
    bool Miller_Rabin(LL n) {
        if(n < 2) return false;
        if(n == 2) return true;
        if((n & 1) == 0) return false;
        LL x = n - 1,t = 0;
        while((x & 1) == 0) x >>= 1,t ++;
        for(int i = 0;i < S;i ++) {
            LL a = rand() % (n - 1) + 1;
            if(check(a,n,x,t)) return false;
        }
        return true;
    }
}

namespace Pr {
    LL Pollard_rho(LL x,LL c) {
        LL i = 1,k = 2,x0 = rand() % (x - 1) + 1,y = x0;
        while(1) {
            i ++;
            x0 = (mul(x0,x0,x) + c) % x;
            LL d = __gcd(abs(y-x0),x);
            if(d != 1 && d != x) return d;
            if(y == x0) return x;
            if(i == k) y = x0,k <<= 1;
        }
    }

    void findfac(LL n,LL factor[]) {
        if(n == 1) return ;
        if(MR :: Miller_Rabin(n)) {
            factor[++ factor[0]] = n;
            return ;
        }
        LL p = n;
        while(p >= n) p = Pollard_rho(n,rand() % (n - 1) + 1);
        findfac(p,factor); findfac(n/p,factor);
    }
}

int n,k,sum;
LL num[SZ];
pli a[SZ];
vector<pli> g;
int f[SZ];
vector<int> tmp[SZ];

int get_id(vector<int> &t) {
    int now = 1,ans = 0;
    for(int i = t.size()-1;i >= 0;i --) {
        ans += t[i] * now;
        now *= g[i].second + 1;
    }
    return ans;
}

LL work(int id) {
    swap(a[1],a[id]);
    LL fac[111]; fac[0] = 0;
    Pr::findfac(a[1].first,fac);
    sort(fac+1,fac+1+fac[0]);
    g.clear();
    for(int i = 1,j = 1;i <= fac[0];i ++) {
        if(i == fac[0] || fac[i] != fac[i+1]) {
            int t = 0;
            while(j <= i) t ++,j ++;
            g.push_back(make_pair(fac[i],t));
        }
    }

   // puts("--------");
   // for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");

    int N = 1;
    for(int i = 0;i < g.size();i ++) N *= g[i].second + 1;
    for(int i = 0;i < N;i ++) f[i] = 0;

   // cout << N << endl;

    for(int j = 2;j <= n;j ++) {
        LL d = __gcd(a[1].first,a[j].first);
        vector<int> tmp;
        for(int i = 0;i < g.size();i ++) {
            LL p = g[i].first;
            int t = 0;
            while(d%p==0) d/=p,t ++;
            t = min(t,g[i].second);
            tmp.push_back(t);
        }
        int x = get_id(tmp);
      //  printf("add: %lld %d\n",__gcd(a[1],a[j]),x);
        int v = a[j].second;
        f[x] += v;
    }

    for(int j = 0;j < N;j ++) {
        tmp[j].clear();
        int id = j,now = N;
        for(int k = 0;k < g.size();k ++) {
            now /= g[k].second + 1;
            tmp[j].push_back(id / now); id %= now;
        }
    }


    for(int i = 0;i < g.size();i ++) {
        for(int j = 0;j < N;j ++) {
            if(tmp[j][i] < g[i].second) {
                tmp[j][i] ++;
                int pre = get_id(tmp[j]);
                f[j] += f[pre];
                tmp[j][i] --;
              //  printf("%d -> %d\n",pre,j);
            }
        }
    }

    vector<LL> G[111];
    for(int k = 0;k < g.size();k ++) {
        LL p = 1;
        for(int i = 1;i <= g[k].second + 1;i ++) {
            G[k].push_back(p);
            p *= g[k].first;
        }
    }

   // for(int j = 0;j < N;j ++) printf("%d ",f[j]); puts("");

    LL ans = 0;
    for(int j = 0;j < N;j ++) {
        if(f[j]+a[1].second < sum-k) continue;
        LL t = 1;
        for(int k = 0;k < g.size();k ++) {
            t *= G[k][tmp[j][k]];
        }
     //   printf("%lld %d %d\n",t,j,f[j]-f2[j]);
        ans = max(ans,t);
    }
  //  cout << ans << endl;
    return ans;
}

mt19937 rd(1111);

int main() {
    sum = n = read(),k = read();
    for(int i = 1;i <= n;i ++){
        num[i] = read();
    }
    sort(num+1,num+1+n);
    int tot = 0;
    for(int i = 1,j = 1;i <= n;i ++){
        /*if(i == n || num[i] != num[i+1]) {
            a[++ tot] = make_pair(num[i],i - j + 1);
            j = i + 1;
        }*/
        a[++ tot] = make_pair(num[i],1);
    }
    n = tot;

    LL ans = 1;
    for(int i = 1;i <= 20;i ++) {
        int id = rd() % n + 1;
        ans = max(ans,work(id));
    }
    cout << ans << endl;
}
/*
10 0
483329799500486400 483329799500486400 897612484786617600 897612484786617600 483329799500486400 483329799500486400 483329799500486400 483329799500486400 483329799500486400 1
*/
