#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e6 + 3;
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

LL ksm(LL a,LL b,LL p) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int find(int a,int p) {
    int ans = p;
    for(int i = 1;i * i <= p-1;i ++) {
        if((p-1) % i == 0) {
            if(ksm(a,i,p) == 1) ans = min(ans,i);
            if(ksm(a,(p-1)/i,p) == 1) ans = min(ans,(p-1)/i);
        }
    }
    return ans;
}

int n,m,num[SZ];
LL ans;
vector<pii> pri;
map<pii,bool> mp;

void dfs(int d,int now) {
    if(d == pri.size()) {
        if(now > n) return ;
        int mint = 0,p,id;
        for(int i = 0;i < pri.size();i ++) {
            assert(num[i]);
            int k = (pri[i].second + num[i] - 1) / num[i];
            if(mint < k)
                mint = k,p = pri[i].first,id = i;
        }
        if(mp[make_pair(id,num[id])]) return;
        mp[make_pair(id,num[id])] = 1;
        int t = n/now-n/now/p;
      //  cout << p << " " << now << " " << (m - mint + 1ll) << " " << t << endl;
        if(mint == 1) return ;
        ans += (m - mint + 1ll) * t;
        return ;
    }
    int p = pri[d].first;
    for(int i = 1;i <= pri[d].second;i ++) {
        num[d] = i;
        dfs(d+1,now*p);
        p *= pri[d].first;
    }
}

LL get(int r) {
    pri.clear();
    for(int i = 2;i * i <= r;i ++) {
        if(r % i == 0) {
            int t = 0;
            while(r%i==0) r/=i,t++;
            pri.push_back(make_pair(i,t));
        }
    }
    if(r != 1) {
        pri.push_back(make_pair(r,1));
    }
    mp.clear();
   // for(int i = 0;i < pri.size();i ++) printf("%d^%d ",pri[i].first,pri[i].second); puts("");
    dfs(0,1);
}

int baoli(int r,int n,int m) {
    int ans = 0,num[max(0,m)+10] = {};
    for(int i = 1;i <= n;i ++) {
        int now = 1,tmp = 0;
        for(int j = 1;j <= m;j ++) {
            now = 1ll * now * i % r;
            if(now == 0) tmp ++;
        }
        ans += tmp;
        if(tmp) {
       //     cout << i << " " << tmp << endl;
            num[tmp] ++;
        }
    }
   // for(int i = 1;i <= m;i ++) if(num[i]) printf("%d %d\n",i,num[i]);
    return ans;
}

mt19937 rd(time(0));

int randlr(int l,int r) {
    int len = r-l+1;
    return rd() % (r-l+1);
}

bool isprime(int p) {
    if(p <= 1) return false;
    for(int i = 2;i * i <= p;i ++) {
        if(p%i == 0) return false;
    }
    return true;
}

int main() {
    int T = read();
    while(T --) {
        int p = read(); n = read(),m = read();
        //int p = randlr(1,1e4); while(!isprime(p)) p = randlr(1,1e4); n = randlr(1,1e4); m = randlr(1,1e4); printf("%d %d %d\n",p,n,m);
        if(p == 2 || p == 5) { puts("0"); continue; }

        int r = p == 3 ? 3 : find(10,p);
        assert(r);
      //  cout << r << endl;
        ans = 1ll * (n/r) * m;
        get(r);
        printf("%lld\n",ans);
        //int bl;printf("baoli: %d\n",bl = baoli(r,n,m));while(bl != ans);
    }
}
/**
233
9829 8800 5637

3331 2388 9584

97 235 654

*/

