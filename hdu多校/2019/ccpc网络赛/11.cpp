#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 5e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int ksm(int a,int b,int p) {
    int ans = 1;
    while(b) {
        if(b&1) ans = 1ll * a * ans % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return ans;
}

int pri[] = {2,7,17};
int pk[] = {8388608,7,17};
int phi[] = {4194304,6,16};

int fac[8388608+10];
int fac7[110];
int fac17[110];

pii f[3][SZ];

const int B = 0;

void pre() {
    int p = 8388608 - 1;
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 3;i <= 8388607;i += 2) {
        fac[i] = (1ll * fac[i-2] * i) & p;
        fac[i-1] = fac[i-2];
    }
    fac7[0] = 1;
    for(int i = 1;i < 7;i ++) fac7[i] = 1ll * fac7[i-1] * i % 7;
    fac17[0] = 1;
    for(int i = 1;i < 17;i ++) fac17[i] = 1ll * fac17[i-1] * i % 17;

    for(int i = 0;i < 3;i ++) {
        f[i][0].first = 1;
        for(int j = 1;j <= B;j ++) {
            int x = j,t = 0;
            while(x % pri[i] == 0) x /= pri[i],t ++;
            f[i][j].first = 1ll * f[i][j-1].first * x % pk[i];
            f[i][j].second = f[i][j-1].second + t;
        }
    }
}

pii dfs(int n,int p) {
    if(n <= B) {
        int id;
        if(p == 7) id = 1;
        else if(p == 17) id = 2;
        else id = 0;
        return f[id][n];
    }
    if(p == 7 || p == 17) {
        if(n < p) {
            return make_pair(p == 7 ? fac7[n] : fac17[n],0);
        }
        pii ans = dfs(n/p,p);
        (ans.first *= (n/p)&1 ? (p == 7 ? fac7[6] : fac17[16]) : 1) %= p;
        ans.first = ans.first * (p == 7 ? fac7[n%p] : fac17[n%p]) % p;
        ans.second += n / p;
        return ans;
    }
    else {
        if(n == 0) return make_pair(1,0);
        if(n == 1) return make_pair(1,0);
        //if(mp.count(make_pair(n,mod))) return mp[make_pair(n,mod)];
        pii ans = dfs(n >> 1,p);
        p --;
        ans.second += n >> 1;
        ans.first = (1ll * ans.first * fac[n & p]) & p;
        return ans;
    }
}

pii get_fac(int n,int p) {
    pii ans;
    if(p == 7 || p == 17) ans = dfs(n,p);
    else ans = dfs(n,8388608);
    /*int t = 1,mi = 0,mm = p == 2 ? 8388608 : p;
    for(int i = 1;i <= n;i ++) {
        int x = i;
        while(x%p==0) x/=p,mi++;
        t = 1ll * t * x % mm;
    }
    printf("%d! = %lld * %d^%lld\n",n,ans.first,p,ans.second);
    assert(t == ans.first); assert(mi == ans.second);*/
    return ans;
}

LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    LL d = exgcd(b,a%b,x,y);
    LL t = x; x = y; y = t - a / b * y;
    return d;
}

LL excrt(LL *r,LL *a,int n){ // x%r=a
    LL M=a[1],R=r[1],x,y,d;
    for(int i=2;i<=n;i++){
        d=exgcd(M,a[i],x,y);
        x=(R-r[i])/d * x % a[i];
        R -= M*x;
        M = M/d * a[i];
    }
    return (R%M+M)%M;
}

int calc(int n,int a,int b,int c) {
    LL r[5],M[5];
    for(int i = 0;i < 3;i ++) {
        pii N = get_fac(n,pri[i]);
        pii A = get_fac(a,pri[i]);
        pii B = get_fac(b,pri[i]);
        pii C = get_fac(c,pri[i]);
        LL ans = 1ll * N.first
            * ksm(A.first,phi[i]-1,pk[i]) % pk[i]
            * ksm(B.first,phi[i]-1,pk[i]) % pk[i]
            * ksm(C.first,phi[i]-1,pk[i]) % pk[i];
        N.second -= A.second;
        N.second -= B.second;
        N.second -= C.second;
        ans = ans * ksm(pri[i],N.second,pk[i]) % pk[i];
        r[i+1] = ans;
        M[i+1] = pk[i];
    }
    return excrt(r,M,3);
}

struct FastIO{
  static const int S=1310720;
  int wpos,pos,len;char wbuf[S];
  FastIO():wpos(0){}
  inline int xchar(){
    static char buf[S];
    if(pos==len)pos=0,len=fread(buf,1,S,stdin);
    if(pos==len)return -1;
    return buf[pos++];
  }
  inline int xuint(){
    int c=xchar(),x=0;
    while(c<=32&&~c)c=xchar();
    if(c==-1)return -1;
    for(;'0'<=c&&c<='9';c=xchar())x=x*10+c-'0';
    return x;
  }
}io;

int main() {
  // freopen("1.in","r",stdin);
    //cout << (mod-1) / 2 / 7 * 6 / 17 * 16 << endl;
    pre();
/*
    int x;
    while(cin >> x) {
        for(int i = 0;i < 3;i ++) {
            get_fac(x,pri[i]);
        }
    }
*/
    int t1,t2,p,q,n,m;
    //while(~scanf("%d%d%d%d%d%d",&t1,&t2,&p,&q,&n,&m)) {
    while(1) {
        t1 = io.xuint();
        if(t1 == -1) break;
        t2 = io.xuint();
        p = io.xuint();
        q = io.xuint();
        n = io.xuint();
        m = io.xuint();
        LL ans = 1;
        for(int i = 1;i <= m;i ++) {
            //int x = read(),y = read(),v = read();
            //int x,y,v; scanf("%d%d%d",&x,&y,&v);
            int x = io.xuint(),y = io.xuint(),v = io.xuint();// scanf("%d%d%d",&x,&y,&v);
            if(x%p) continue;
            if(y%q) continue;
            int a = x / p,b = y / q,c = n - a - b;
            if(c<0) continue;
            int mi = calc(n,a,b,c);
            mi = 1ll * mi * ksm(t1,a,mod-1) % (mod-1) * ksm(t2,b,mod-1) % (mod-1);
        //    cout << mi << endl;
            ans = ans * ksm(v,mi,mod) % mod;
        }
        printf("%lld\n",ans);
    }
}

/**
1 1 1 1000000000 2 6
0 0 2
0 1 3
0 2 4
1 0 4
1 1 2
2 0 2

503044
*/
