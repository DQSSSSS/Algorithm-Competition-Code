#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
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

int ch[SZ][27],fg[SZ],sz,val[SZ],len[SZ];

string str[SZ];
vector<int> a[SZ];
vector<int> g[SZ];

void ins(int id) {
    int p = 0;
    for(int i = 0;i < str[id].length();i ++) {
        int c = str[id][i] - 'a';
        if(!ch[p][c]) {
            ch[p][c] = ++ sz;
            len[sz] = len[p] + 1;
        }
        p = ch[p][c];
        val[p] = max(val[p],a[id][i]);
        fg[p] ++;
    }
}

queue<int> q;
int fail[SZ];

void build_ac() {
    for(int i = 0;i < 26;i ++) {
        int u = ch[0][i];
        if(u) { fail[u] = 0; q.push(u); }
    }

    while(q.size()) {
        int f = q.front(); q.pop();
        for(int c = 0;c < 26;c ++) {
            int u = ch[f][c];
            if(!u) { ch[f][c] = ch[fail[f]][c]; continue; }
            q.push(u);
            fail[u] = ch[fail[f]][c];
        }
    }

    for(int i = 1;i <= sz;i ++) {
        g[fail[i]].push_back(i);
        //cout << fail[i] << " " << i << endl;
    }
}

LL dfs(int u) {
    LL ans = 0;
    for(int v : g[u]) {
        ans = max(ans,dfs(v));
        val[u] = max(val[u],val[v]);
    }
    //cout << u << " " << fg[u] << " " << len[u] << " " << val[u] << endl;
    ans = max(ans,1ll*fg[u]*len[u]*val[u]);
    return ans;
}

char s[SZ];

int main() {
    freopen("exciting.in","r",stdin);

    int T = read();
    while(T --) {
        int n = read();

        for(int i = 0;i <= sz;i ++) {
            fail[i] = 0;
            g[i].clear();
            len[i] = fg[i] = val[i] = 0;
            for(int j = 0;j < 26;j ++) ch[i][j] = 0;
        }
        sz = 0;
        for(int i = 1;i <= n;i ++) str[i] = "",a[i].clear();

        for(int i = 1;i <= n;i ++) {
            scanf("%s",s);
            str[i] = s;
        }
        for(int i = 1;i <= n;i ++) {
            int len = str[i].length();
            for(int j = 0;j <len;j ++) {
                int x = read();
                a[i].push_back(x);
            }
        }
        for(int i = 1;i <= n;i ++) ins(i);
        build_ac();

        LL ans = dfs(0);
        printf("%lld\n",ans);
    }
}
