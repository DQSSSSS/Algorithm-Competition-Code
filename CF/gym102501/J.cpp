#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

int fac[2*SZ],incFac[2*SZ];

int C(int n,int m) {
    return 1ll * fac[n] * incFac[m] % mod * incFac[n-m] % mod;
}

int f(int n) {
    return (C(2*n,n) - C(2*n,n-1) + mod) % mod;
}

int n,st[22][SZ],a[SZ];

int get(int x,int y) {
    return a[x] <= a[y] ? x : y;
}

void get_st(int a[]) {
    for(int i = 1;i <= n;i ++) st[0][i] = i;
    for(int j = 1;j <= log2(n);j ++) {
        for(int i = 1;i+(1<<(j-1)) <= n;i ++) {
            st[j][i] = get(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
    }
}

int ask(int l,int r) {
    int k = log2(r-l+1);
    return get(st[k][l], st[k][r-(1<<k)+1]);
}

LL ans = 1;
int nx[SZ];

void dfs(int l,int r) {
    if(l >= r) return ;
   // cout << l << " " << r << endl;
    int id = ask(l,r);
    int t = 0,lst = l;
    for(int i = id;i <= r;i = nx[i]) {
        t ++;
        dfs(lst,i-1);
        lst = i + 1;
    }
    dfs(lst, r);
    ans = 1ll * ans * f(t) % mod;
}


int main() {

    n = read();
    fac[0] = 1; incFac[1] = 1;
    for(int i = 1;i <= 2*n;i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    for(int i = 2;i <= 2*n;i ++) incFac[i] = 1ll*(mod-mod/i) * incFac[mod%i] % mod;
    incFac[0] = 1;
    for(int i = 1;i <= 2*n;i ++) incFac[i] = 1ll * incFac[i-1] * incFac[i] % mod;

    //for(int i = 1;i <= n;i ++) cout << f(i) <<endl;
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
     //   a[i] = rand()%5+1;
    }
    map<int,int> mp;
    for(int i = n;i >= 1;i --) {
        nx[i] = mp[a[i]] == 0 ? n+1 : mp[a[i]];
        mp[a[i]] = i;
    }
    get_st(a);
    dfs(1,n);
    cout << ans << endl;
}
/*
8
3 1 2 1 3 2 3 1

4
3 1 2 1
*/
