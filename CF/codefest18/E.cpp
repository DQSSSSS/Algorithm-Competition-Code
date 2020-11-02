#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

set<int> g[SZ];

int ff[SZ],tt[SZ],Ans[SZ],n,m,k,ans;
int vis[SZ];

void del(int x) {
	vis[x] = 1;
	ans --;
    for(set<int> :: iterator it = g[x].begin();it != g[x].end();it ++) {
        g[*it].erase(x);
        if(!vis[*it] && g[*it].size() < k)
        	del(*it);
    }
    g[x].clear();
}

int main() {
    n = read(),m = read(),k = read();
    for(int i = 1;i <= m;i ++){
		int x = read(),y = read();
   		g[x].insert(y);
   		g[y].insert(x);
    	ff[i] = x; tt[i] = y;
    }
    ans = n;
    for(int i = 1;i <= n;i ++)
    	if(!vis[i] && g[i].size() < k)
            del(i);

    for(int i = m;i >= 1;i --) {
        Ans[i] = ans;
        int x = ff[i],y = tt[i];
        //for(int j = 1;j <= n;j ++) cout << g[j].size() << " "; puts("");
       	if(vis[x] || vis[y]) continue;
       // cout << i << endl;
        g[x].erase(y); g[y].erase(x);
		if(!vis[x] && g[x].size() < k) del(x);
		if(!vis[y] && g[y].size() < k) del(y);
    }
    for(int i = 1;i <= m;i ++) printf("%d\n",Ans[i]);
    return 0;
}
/**
6 7 3
1 2
2 3
3 1
4 5
5 6
6 4
3 4

8 12 3

*/
