#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

pll a[SZ],b[SZ];

LL calc(int x,int y) {
    if(a[x].first < b[y].first && a[x].second < b[y].second)
        return (a[x].first - b[y].first) * (a[x].second - b[y].second);
    return -1;
}

LL dfs(int l,int r,int L,int R) {
    if(a[l].first > b[R].first) return 0;
    LL ans = 0;
    if(l == r) {
        for(int i = L;i <= R;i ++)
            ans = max(ans,calc(l,i));
        return ans;
    }
    if(L == R) {
        for(int i = l;i <= r;i ++)
            ans = max(ans,calc(i,L));
        return ans;
    }
    int M = L + R >> 1,m = -1;
    for(int i = l;i <= r;i ++) {
        if(ans < calc(i,M))
            ans = calc(i,M),m = i;
    }
    if(m == -1) {
        for(int i = l;i <= r;i ++)
            if(a[i].first < b[M].first)
                m = i;
        if(m == -1) return dfs(l,r,M+1,R);
        return max(dfs(l,m,L,M),dfs(m,r,M+1,R));
    }
    //cout << M << " " << m  " " << ans << endl;
    ans = max(ans,dfs(l,m,L,M));
    ans = max(ans,dfs(m,r,M+1,R));
    return ans;
}

pll tmp[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i].second = read(),a[i].first = read();
    for(int i = 1;i <= m;i ++) b[i].second = read(),b[i].first = read();
    sort(a + 1,a + 1 + n);
    sort(b + 1,b + 1 + m);

    int tot = 0;
    tmp[++tot] = a[1];
    for(int i = 2,maxn = a[1].second;i <= n;i ++) {
        if(a[i].second < maxn) maxn = a[i].second,tmp[++tot] = a[i];
    }
    for(int i = 1;i <= tot;i ++) a[i] = tmp[i]; n = tot;

    tot = 0;
    for(int i = 1;i <= m;i ++) {
        while(tot && b[i].second > tmp[tot].second) tot --;
        tmp[++ tot] = b[i];
    }
    for(int i = 1;i <= tot;i ++) b[i] = tmp[i]; m = tot;

    cout << dfs(1,n,1,m) << endl;
    return 0;
}
