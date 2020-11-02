#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
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

int n,m,G[33];
pii pre[1<<23];
int f[1<<23];

void dfs(int S) {
    if(f[S] != -1) return ;
    int ans = INF;
    for(int i = 0;i < n;i ++) {
        if(S>>i&1) {
            if((S|G[i]) == S) continue;
            dfs(S|G[i]);
            if(ans > f[S|G[i]] + 1) {
                ans = f[S|G[i]] + 1;
                pre[S] = make_pair(i,S|G[i]);
            }
        }
    }
    f[S] = ans;
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        x --; y --;
        G[x] |= 1 << y;
        G[y] |= 1 << x;
    }
    if(m == n*(n-1)/2) return puts("0"),0;
    for(int i = 0;i < (1<<n);i ++) f[i] = -1;
    f[(1<<n)-1] = 0;
    for(int i = 0;i < n;i ++) {
        f[0] = INF;
        for(int j = 0;j < n;j ++) {
            dfs(1<<j);
            if(f[0] > f[1<<j]) {
                f[0] = f[1<<j];
                pre[0] = make_pair(j,1<<j);
            }
        }
    }
    printf("%d\n",f[0]);
    for(int S = pre[0].second;S != (1<<n)-1;S = pre[S].second) {
        printf("%d ",pre[S].first+1);
        //printf("%d %d\n",pre[S].first+1,S);
    }
}
