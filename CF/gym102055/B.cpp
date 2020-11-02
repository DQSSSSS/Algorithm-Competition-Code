#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

vector<int> g[SZ],node[SZ];

int c[SZ];

bool dfs(int u,int col,int id) {
    node[id].push_back(u);
    c[u] = col;
    for(int v : g[u]) {
        if(c[v] != -1) {
            if(c[v] == c[u]) return false;
        }
        else {
            if(!dfs(v,col^1,id)) return false;
        }
    }
    return true;
}


multiset<int> s;
pii a[SZ][2];

struct haha {
    int mn,id,d;
}l[SZ];

bool use[SZ];
int L[SZ],D[SZ];

bool cmp(haha a,haha b) { return a.mn < b.mn; }

int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) {
            g[i].clear(),c[i] = -1,use[i] = 0;
            node[i].clear();
        }
        s.clear();
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for(int i = 1;i <= n;i ++) L[i] = read(),D[i] = read();

        int tot = 0,flag = 0,len = 0;
        for(int i = 1;i <= n;i ++) {
            if(c[i] == -1) {
                if(!dfs(i,0,++ tot)) {
                    flag = 1;
                    break;
                }
                pii mxa = make_pair(1e9+1,0);
                pii mxb = make_pair(1e9+1,0);
                for(int x : node[tot]) {
                    if(c[x] == 0) {
                        mxa.first = min(mxa.first,L[x]); mxa.second = max(mxa.second,L[x]);
                        mxb.first = min(mxb.first,D[x]); mxb.second = max(mxb.second,D[x]);
                    }
                    else {
                        mxa.first = min(mxa.first,D[x]); mxa.second = max(mxa.second,D[x]);
                        mxb.first = min(mxb.first,L[x]); mxb.second = max(mxb.second,L[x]);
                    }
                }
                a[tot][0] = mxa;
                a[tot][1] = mxb;
                if(mxa.second < mxb.second) use[tot] = 0;
                else use[tot] = 1;
                l[++ len] = (haha){mxa.first,tot,0};
                l[++ len] = (haha){mxb.first,tot,1};
            }
        }

        if(flag) { printf("Case %d: IMPOSSIBLE\n",++ cc); continue; }

        sort(l+1,l+1+len,cmp);
       /* for(int i = 1;i <= tot;i ++) {
            cout << a[i][0].first << " " << a[i][0].second << "     ";
            cout << a[i][1].first << " " << a[i][1].second << endl;
        }*/
        for(int i = 1;i <= tot;i ++) s.insert(a[i][use[i]].second);
        int ans = 1e9;
        for(int i = 1;i <= len;i ++) {
            if(use[l[i].id] != l[i].d) { /// ц╩сп
                multiset<int> :: iterator it;
                it = s.find(a[l[i].id][l[i].d^1].second); s.erase(it);
                s.insert(a[l[i].id][l[i].d].second);
                it = s.end(); it --;
                int mx = *it;
                ans = min(ans,mx - l[i].mn);
                it = s.find(a[l[i].id][l[i].d].second); s.erase(it);
                s.insert(a[l[i].id][l[i].d^1].second);
            }
            else { /// сп
                multiset<int> :: iterator it = s.end(); it --;
                int mx = *it;
                ans = min(ans,mx - l[i].mn);
                it = s.find(a[l[i].id][l[i].d].second); s.erase(it);
                if(a[l[i].id][l[i].d^1].first <= l[i].mn) break;
                s.insert(a[l[i].id][l[i].d^1].second);
                use[l[i].id] ^= 1;
            }
        }

        printf("Case %d: %d\n",++ cc,ans);
    }
}
/**
3
3 1
1 2
1 2
3 4
5 6
4 3
1 2
2 3
1 3
1 2
3 4
5 6
7 8
2 0
2 1
3 5

*/

