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

const int MAXN = 200010;
struct max_flow {

    struct edge {
        int t;
        LL d;
        int rev;
    };
    vector<edge> G[MAXN];

    void insert(int f,int t,LL d) {
        G[f].push_back((edge){t,d,(int)G[t].size()});
        G[t].push_back((edge){f,0,(int)G[f].size()-1});
    }

    int n,deep[MAXN];
    bool bfs(int s,int t) {
        for(int i = 1;i <= n;i ++) deep[i] = 0;
        deep[s] = 1;
        queue<int> q; q.push(s);
        while(q.size()) {
            int u = q.front(); q.pop();
            for(edge &e : G[u]) {
                int v = e.t;
                if(e.d && !deep[v]) {
                    deep[v] = deep[u] + 1;
                    if(v == t) return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    LL dfs(int u,LL flow,int t) {
        if(u == t || flow == 0) return flow;
        LL ans = flow;
        for(edge &e : G[u]) {
            int v = e.t;
            if(e.d && deep[v] == deep[u] + 1) {
                LL f = dfs(v,min(ans,e.d),t);
                if(f > 0) {
                    e.d -= f; G[v][e.rev].d += f;
                    ans -= f;
                    if(ans == 0) break;
                }
                else deep[v] = 0;
            }
        }
        if(ans == flow) deep[u] = 0;
        return flow - ans;
    }

    LL dinic(int s,int t) {
        LL ans = 0;
        while(bfs(s,t)) {
            LL tmp = dfs(s,INF,t);
            if(tmp == 0) break;
            ans += tmp;
        }
        return ans;
    }

    void init(int nn) {
        n = nn;
        for(int i = 0;i <= nn;i ++) G[i].clear();
    }
}mf;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

char mp[44][44];

int n,m;

int id(int i,int j,int k) {
    return (i-1)*m+j+(k*n*m);
}

bool isin(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}

int main() {
    //freopen("K.in","r",stdin);
    while(1) {
        n = 1,m = 1;
        int mm = 1;
        int flag = 0;
        char lstc = 0;
        while(1) {
            char c = getchar();
            if(c == EOF) { flag = 1; break; }
            else if(c == '\n' || c == '\r') {
                if(lstc == '\n' || lstc == '\r') break;
                n++; m=1;
            }
            else {
                mm = max(mm,m);
                mp[n][m] = c;
                m ++;
            }
            lstc = c;
          //  cout << n << " " << m << " " << c << endl;
        }
        if(!flag) n --;
        m = mm;

        int s = 2*n*m+1,t = s + 1;
        mf.init(t);

        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                mf.insert(id(i,j,0),id(i,j,1),1);
            }
        }
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                if(mp[i][j] == 'N') mf.insert(id(i,j,1),t,1);
                if(mp[i][j] == 'W') {
                    mf.insert(s,id(i,j,0),1);
                    for(int k1 = 0;k1 < 4;k1 ++) {
                        for(int k2 = 0;k2 < 4;k2 ++) {
                            int x1 = i+dx[k1],y1 = j + dy[k1];
                            int x2 = x1+dx[k2],y2 = y1 + dy[k2];
                            if(isin(x1,y1) && isin(x2,y2) && mp[x1][y1] == 'I' && mp[x2][y2] == 'N') {
                                mf.insert(id(i,j,1),id(x1,y1,0),1);
                                mf.insert(id(x1,y1,1),id(x2,y2,0),1);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",mf.dinic(s,t));
        /*printf("%d %d\n",n,m);
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                printf("%c",mp[i][j]);
            }
            puts("");
        }
        cout << flag << endl;*/
        if(flag) break;
    }
}
