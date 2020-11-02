#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

vector<int> G[SZ];
vector<pii> add[SZ];
int n,rd[SZ],value[SZ],R[SZ],L[SZ];
vector<int> topo;

bool check(int mid) {
    for(int i = 1;i <= n;i ++) add[i].clear();
    for(int i = 1;i <= n;i ++) rd[i] = 0;
    for(int i = 1;i <= n;i ++) {
        int maxid = mid - value[i];
        if(maxid < 1) return false;
        maxid = min(maxid,n);
        R[i] = maxid;
    }
    for(int i = 1;i <= n;i ++) L[i] = 1;

    for(int i = 0;i < topo.size();i ++) {
        int u = topo[i];
        for(int v : G[u]) {
            L[v] = max(L[v],L[u] + 1);
        }
    }

    for(int i = topo.size() - 1;i >= 0;i --) {
        int u = topo[i];
        for(int v : G[u]) {
            R[u] = min(R[u],R[v] - 1);
        }
    }

   // for(int i = 1;i <= n;i ++) printf("%d %d\n",L[i],R[i]);
    for(int i = 1;i <= n;i ++) {
        if(L[i] > R[i])
            return false;
    }

    priority_queue<pii> q;
    for(int i = 1;i <= n;i ++) {
        add[L[i]].push_back({-R[i],i});
    }
    for(int i = 1;i <= n;i ++) {
        for(pii p : add[i]) {
            q.push(p);
        }
        pii u = q.top(); q.pop();
        if(-u.first < i) return false;
    }

    return true;
}

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) {
        value[i] = read();
        int k = read();
        while(k --) {
            int x = read();
            G[x].push_back(i);
        }
    }

    for(int u = 1;u <= n;u ++) {
        for(int v : G[u]) {
            rd[v] ++;
        }
    }

    queue<int> q;
    for(int i = 1;i <= n;i ++) {
        if(rd[i] == 0) q.push(i);
    }
    while(q.size()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : G[u]) {
            if(-- rd[v] == 0) {
                q.push(v);
            }
        }
    }

    int l = 0,r = 2e6;
   // cout << check(13) << endl;   return 0;
    while(r-l>1) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r - 1 << endl;
}
