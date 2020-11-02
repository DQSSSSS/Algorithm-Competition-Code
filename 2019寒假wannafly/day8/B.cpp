#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int use[SZ],zuo[SZ],match[SZ];
vector<int> g[SZ];

int dfs(int u,int p) {
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v < p) break;

        if(use[v]) continue;
        use[v] = 1;
        int x;
        if(match[v] == -1) {
            match[v] = u;
            return v;
        }
        else if((x=dfs(match[v],p)) != match[v]) {
            match[v] = u;
            return x;
        }
    }
    return u;
}

bool cmp(int a,int b) { return a > b; }

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        if(x > y) swap(x,y);
        g[x].push_back(y);
    }
    for(int i = 0;i < n;i ++) sort(g[i].begin(),g[i].end(),cmp),match[i] = -1;
    for(int i = 0;i < n;i ++) {
        if(match[i] != -1) {
            if(dfs(match[i],i) == match[i]) {printf("%d\n",i); return 0; }
            match[i] = -1;
        }
        if(dfs(i,i) == i) {printf("%d\n",i); return 0; }
        for(int j = i + 1;j < n;j ++) use[j] = 0;
        //for(int j = 0;j < n;j ++) cout << match[j] << " "; puts("");
    }
    printf("%d\n",n);
    return 0;
}
/**
4 5
0 1
1 2
2 3
0 2
1 3
*/
