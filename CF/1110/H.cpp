#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800*2*10+800+10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int ch[SZ][11],sz,ln,rn;
int tpf[SZ][2010];

void insert(char s[],int l,char c,int d) {
   // cout << d << " "; for(int i = 0;i < l;i ++) cout << s[i]; cout << c; puts("");
    int p = 0;
    for(int i = 0;i < l;i ++) {
        int c = s[i] - '0';
        if(!ch[p][c]) ch[p][c] = ++ sz;
        p = ch[p][c];
    }
    c = c - '0';
    if(!ch[p][c]) ch[p][c] = ++ sz;
    p = ch[p][c];
    tpf[p][d] ++;
}

int fail[SZ];
queue<int> q;
vector<int> g[SZ];

void build_ac() {
    fail[0] = 0;
    for(int i = 0;i < 10;i ++) {
        int u = ch[0][i];
        if(u) fail[u] = 0,q.push(u);
    }
    while(q.size()) {
        int f = q.front(); q.pop();
        for(int c = 0;c < 10;c ++) {
            int u = ch[f][c];
            if(!u) ch[f][c] = ch[fail[f]][c];
            else q.push(u),fail[u] = ch[fail[f]][c];
        }
    }
    for(int i = 1;i <= sz;i ++) {
        g[fail[i]].push_back(i);
    }
}

void dfs(int u) {
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        for(int j = 0;j <= rn;j ++)
            tpf[v][j] += tpf[u][j];
        dfs(v);
    }
}

char L[810],R[810];
int f[SZ][2010];
bool fuck[SZ][2010];

void insert_str() {
    if(ln != rn) {
        for(int i = 0;i < ln;i ++) {
            char b = i + 1 == ln ? L[i] : L[i] + 1;
            for(int j = b;j <= '9';j ++) {
                insert(L,i,j,ln-i-1);
            }
        }
        for(int i = 0;i < rn;i ++) {
            char b = i + 1 == rn ? R[i] : R[i] - 1;
            for(int j = i == 0 ? '1' : '0';j <= b;j ++) {
                insert(R,i,j,rn-i-1);
            }
        }
        for(int i = ln + 1;i < rn;i ++) {
            for(int j = '1';j <= '9';j ++) {
                insert(NULL,0,j,i-1);
            }
        }
    }
    else {
        int f = 0;
        for(int i = 0;i < ln;i ++) {
            if(L[i] != R[i] || f) {
                if(!f) {
                    if(i + 1 != ln)
                        for(int j = L[i] + 1;j <= R[i] - 1;j ++)
                            insert(L,i,j,ln-i-1);
                    else
                        for(int j = L[i];j <= R[i];j ++)
                            insert(L,i,j,ln-i-1);
                    f = 1;
                }
                else {
                    char b = i + 1 == ln ? L[i] : L[i] + 1;
                    for(int j = b;j <= '9';j ++)
                        insert(L,i,j,ln-i-1);
                    b = i + 1 == rn ? R[i] : R[i] - 1;
                    for(int j = i == 0 ? '1' : '0';j <= b;j ++)
                        insert(R,i,j,rn-i-1);
                }
            }
        }
        if(!f) {
            insert(L,ln-1,L[ln-1],0);
        }
    }
    ch[0][0] = ++ sz;
}

int main() {
    scanf("%s%s",L,R);
    ln = strlen(L);
    rn = strlen(R);
    int n = read();

    insert_str();

    build_ac();
    dfs(0);
    for(int i = 0;i <= sz;i ++)
        for(int j = 1;j <= n;j ++)
            tpf[i][j] += tpf[i][j-1];


    for(int i = 0;i <= sz;i ++)
        for(int j = 0;j <= n;j ++)
            f[i][j] = -INF;
    f[0][0] = 0;
    for(int i = 1;i <= n;i ++) {
        for(int u = 0;u <= sz;u ++) {
            for(int c = 0;c < 10;c ++) {
                int v = ch[u][c];
                if(!v) continue;
                if(f[v][i] < f[u][i-1] + tpf[v][n-i]) {
                    f[v][i] = f[u][i-1] + tpf[v][n-i];
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0;i <= sz;i ++) ans = max(ans,f[i][n]);
    cout << ans << endl;

    for(int i = 0;i <= sz;i ++)
        if(f[i][n] == ans)
            fuck[i][n] = 1;
    for(int i = n;i >= 1;i --) {
        for(int u = 0;u <= sz;u ++) {
            for(int c = 0;c < 10;c ++) {
                int v = ch[u][c];
                if(!v) continue;
                if(fuck[v][i] && f[v][i] == f[u][i-1] + tpf[v][n-i]) {
                    fuck[u][i-1] = 1;
                }
            }
        }
    }

    int u = 0;
    for(int i = 1;i <= n;i ++) {
        for(int c = 0;c < 10;c ++) {
            int v = ch[u][c];
            if(!v) continue;
            if(fuck[v][i] && f[v][i] == f[u][i-1] + tpf[v][n-i]) {
                putchar(c+'0');
                u = v;
                break;
            }
        }
    }
    return 0;
}

