#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 5e6 + 10;
const int INF = 1e9 + 10;
const LL mod = 1000000000000037ll;
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

char s[3][33];

void dfs(int d,LL now,int r,LL a[]) {
    if(d == r+1) {
        a[++a[0]] = now;
        return ;
    }
    for(int i = 0;i < 3;i ++) {
        LL nx = now * 127 % mod + s[i][d];
        dfs(d+1,nx,r,a);
    }
}

void get(int l,int r,LL a[],int &n) {
    if(l>r) { n = 1; a[1] = 0; return ; }
    a[0] = 0;
    dfs(l,0,r,a);
    n = a[0];
}

LL a[SZ],b[SZ];

inline LL mul(LL x,LL y,LL z) {
    return (x*y-(LL)(((long double)x*y+0.5)/(long double)z)*z+z)%z;
}

LL work(int len) {
    int l = len/2,r = len-l;
    int n,m;
    get(0,l-1,a,n); get(l,len-1,b,m);
   // cout << " !! " << endl;
    LL B = 1;

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= len-l;j ++) a[i] = a[i] * 127 % mod;
        //9a[i] = mul(a[i],B,mod);
    }
    //cout << " ?? " << endl;

    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    LL ans = mod;
    int p = m;
    //cout << n << " " << m <<endl;
    for(int i = 1;i <= n;i ++) {
        ans = min(ans,(a[i]+b[1])%mod);
        while(p-1>=1 && a[i]+b[p-1] >= mod) p --;
        ans = min(ans,(a[i]+b[p])%mod);
    }
  //  cout << ans <<endl;
    return ans;
}

int main() {
    int n = read(),m = read();
    for(int i = 0;i < 3;i ++) scanf("%s",s[i]);
    LL x = work(n);
    for(int i = 0;i < 3;i ++) scanf("%s",s[i]);
    LL y = work(m);
    if(x < y) puts("Owls");
    if(x == y) puts("Tie");
    if(x > y) puts("Goats");
}
