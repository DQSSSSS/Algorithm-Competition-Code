#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 1e17;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

vector<int> G[SZ];
LL a[SZ];
int ans[SZ];

struct haha {

    map<LL,int> mp;
    int ans;

    void add(int x) {
        if(!mp[x]) ans ++;
        mp[x] ++;
    }

    void del(int x) {
        if(mp[x] == 1) ans --;
        mp[x] --;
    }
}ds;

void dfs(int u,int f) {
    ds.add(a[u]);
    ans[u] = ds.ans;
    for(int v : G[u]) {
        if(v == f) continue;
        dfs(v,u);
    }
    ds.del(a[u]);
}


int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1;i <= n;i ++) a[i] = read();
    int rt = n;
    dfs(n,0);
    //for(int i = 1;i <= n;i ++) printf("%d%c",ans[i],i==n?'\n':' ');
    for(int i = 1;i <= n;i ++) printf("%d ",ans[i]);
}
/*
5
3 1
3 2
4 1
5 1
-2147483648 2147483647 2147483647 -2147483648 -2147483648
*/
