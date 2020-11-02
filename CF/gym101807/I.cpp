#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
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

vector<int> g[SZ];
int a[SZ],b[SZ],use[SZ],mark[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1;i <= n;i ++) b[i] = read();
    if(b[1] < n) mark[1] = 1;

    set<int> S;
    use[b[1]] = 1;
    for(int u : g[b[1]]) S.insert(u),use[u] = 1;
    for(int i = 2;i <= n;i ++) {
        if(S.lower_bound(b[i]) == S.end()) break;
        if(S.upper_bound(b[i]) != S.end()) mark[i] = 1;
        if(*S.lower_bound(b[i]) != b[i]) { mark[i] = 1; break; }
        auto it = S.lower_bound(b[i]);
        S.erase(it);
        for(int v : g[*it]) {
            if(!use[v]) use[v] = 1,S.insert(v);
        }
    }

    int flag = 0;
    for(int i = 1;i <= n;i ++) if(mark[i]) flag = i;
    if(!flag) return puts("-1"),0;

    if(flag == 1) {
        for(int i = 1;i <= n;i ++) use[i] = 0;
        S.clear();
        S.insert(b[1]+1); use[b[1]+1] = 1;
        while(S.size()) {
            int u = *S.begin();S.erase(S.begin());
            a[++a[0]] = u;
            for(int v : g[u]) {
                if(!use[v]) use[v] = 1,S.insert(v);
            }
        }
    }
    else {
        for(int i = 1;i <= n;i ++) use[i] = 0;
        S.clear();
        S.insert(b[1]); use[b[1]] = 1;
        bool ff = 0;
        while(S.size()) {
            int u;
            a[0] ++;
            if(a[0] < flag) u = b[a[0]],S.erase(b[a[0]]);
            else if(a[0] == flag) {
                auto it = S.upper_bound(b[a[0]]);
                u = *it; S.erase(it);
            }
            else u = *S.begin(),S.erase(S.begin());

            a[a[0]] = u;
            for(int v : g[u]) {
                if(!use[v]) use[v] = 1,S.insert(v);
            }
        }
    }
    for(int i = 1;i <= n;i ++) printf("%d ",a[i]);
}

/**
6 7
1 2
1 3
2 3
3 4
4 5
4 6
5 6
1 2 3 4 5 6
*/

