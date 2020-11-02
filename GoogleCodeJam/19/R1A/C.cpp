#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int ch[SZ][27],tot,val[SZ],delta[SZ];

void insert(char *s) {
    int n = strlen(s);
    int p = 0;
    for(int i = n - 1;i >= 0;i --) {
        int c = s[i] - 'A';
        if(!ch[p][c]) ch[p][c] = ++ tot;
        p = ch[p][c];
        val[p] ++;
    }
}

int ans;

void dfs(int u) {
    for(int i = 0;i < 26;i ++) {
        int v = ch[u][i];
        if(!v) continue;
        dfs(v);
        delta[u] += delta[v];
    }
    //cout << u << " " << val[u] << " " << delta[u] << endl;
    val[u] += delta[u];
    if(u && val[u] >= 2) {
        ans += 2;
        val[u] -= 2;
        delta[u] -= 2;
    }
}

char s[SZ];

int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n = read();
        for(int i = 0;i <= tot;i ++) {
            memset(ch[i],0,sizeof ch[i]);
            val[i] = 0;
            delta[i] = 0;
        }
        tot = 0;
        ans = 0;
        for(int i = 1;i <= n;i ++) {
            scanf("%s",s);
            insert(s);
        }
        dfs(0);
        printf("Case #%d: %d\n",++ cc,ans);
    }
}
