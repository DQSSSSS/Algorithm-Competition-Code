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

int dist[SZ],pre[SZ],du[SZ],mp[SZ],n;
vector<int> g[SZ];

void dfs(int u,int f) {
    dist[u] = dist[f] + 1;
    pre[u] = f;
    for(int v : g[u]) {
        if(v == f) continue;
        dfs(v,u);
    }
}

bool check(int id2) {
    dfs(id2,0);
    for(int i = 0;i <= 2*n;i ++) mp[i] = -1;
    bool flag = 0;
    for(int i = 1;i <= n;i ++) {
        int x = du[i],y = dist[i];
        if(mp[y] == -1) mp[y] = x;
        else if(mp[y] != x) return false;
    }
    return true;
}

int check() {
    if(n == 1) return 1;
    dfs(1,0);
    int maxdist = -1,id = -1;
    for(int i = 1;i <= n;i ++) {
        if(dist[i] > maxdist) id = i,maxdist = dist[i];
    }

    dfs(id,0);
    maxdist = -1;
    int id2 = -1;
    for(int i = 1;i <= n;i ++) {
        if(dist[i] > maxdist) id2 = i,maxdist = dist[i];
    }

    maxdist /= 2;
    while(maxdist --) id2 = pre[id2];

    if(id2 <= n && check(id2)) return id2;
    check(id2);

    memset(mp,0,sizeof mp);
    int sum = 0,sum0 = 0;
    for(int i = 1;i <= n;i ++) {
        int x = du[i],y = dist[i];
        if(x == 1) {
            if(mp[y] == 0) sum0 ++;
            mp[y] ++,sum ++;
        }
    }

    if(sum0 > 2) return -1;

    //for(int i = 1;i <= n;i ++) cout << pre[i] << " "; puts("");
    //for(int i = 1;i <= n;i ++) cout << du[i] << " "; puts("");

    for(int i = 1;i <= n;i ++) {
        if(du[i] == 1) {
            int x = i;
            x = pre[x];
            while(x != id2 && du[x] == 2) x = pre[x];
        //    cout << i << " " << x << endl;
            if(x == id2) {
                if(check(i)) return i;
                else break;
            }
        }
    }

    if(sum0 == 2) {
        check(id2);
        id2 = -1;
        for(int i = 1;i <= n;i ++) mp[dist[i]] = 0;
        for(int i = 1;i <= n;i ++) if(du[i] == 1) mp[dist[i]] ++;
        for(int i = 1;i <= n;i ++) {
            int x = du[i],y = dist[i];
            if(x == 1 && mp[y] == 1) id2 = i;
        }
        if(id2 == -1) return -1;
        if(check(id2)) return id2;
        return -1;
    }
    return -1;
}

int main() {
    n = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(i+n);
        g[i+n].push_back(x);
        g[y].push_back(i+n);
        g[i+n].push_back(y);
        du[x] ++;
        du[y] ++;
        du[i+n] ++;
        du[i+n] ++;
    }

    cout << check() << endl;
}
/**
6
6 1
1 2
2 3
3 4
3 5

5
1 2
2 3
3 4
3 5

9
1 2
1 4
1 9
2 5
2 6
9 7
4 8
4 3

8
1 2
1 4
1 7
2 5
2 6
4 8
4 3

6
1 2
1 3
1 4
3 5
4 6

*/
