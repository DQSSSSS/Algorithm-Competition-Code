//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e5 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

struct pp {
    set<pii> s;

    int top() {
        return s.begin()->second;
    }

    void insert(int x)

}q;

int ID[SZ];

struct haha {
    set<int> a[444];
    int val[SZ],pos[SZ];

    void insert(int id,int p) {
        a[p].insert(id);
        pos[id] = p;

    }

    int find(int id,int d) {
        int x = pos[id];
        if(a[x].size()!=1) return 0;
        x += d;
        int T = 359,t = 0;
        while(T --) {
            if(x == -1) x = 359;
            if(x == 360) x = 0;
            if(a[x].size()) return t;
            x --; t ++;
        }
        return 0;
    }

    int find_id(int id,int d) {
        int x = pos[id];
        if(a[x].size()!=1) {
            if(a[x].size() == 2) {
                auto it = a[x].begin();
                if(*it != id) return *it;
                it ++; return *it;
            }
            return -1;
        }
        x += d;
        int T = 359,t = 0;
        while(T --) {
            if(x == -1) x = 359;
            if(x == 360) x = 0;
            if(a[x].size()) {
                if(a[x].size() == 1) return *a[x].begin();
                else return -1;
            }
            x --; t ++;
        }
        return 0;
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= n;i ++) {
            int x = find(i,-1);
            int y = find(i,1);
            val[i] = x+y;
        }
    }

    void del(int id) {
        for(int d = -1;d <= 1;d ++) {
            int p = find_id(id,d);
            if(p == -1) continue;
            int x = find(id,d);
            q.add()
        }
        a[pos[id]].erase(id);
    }

}r,g,b;

int getVal(int id) {
    return r.val[id]+g.val[id]+b.val[id];
}

int R[SZ],G[SZ],B[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        R[i] = read();
        G[i] = read();
        B[i] = read();
        ID[i] = read();
        r.insert(i,R[i]);
        g.insert(i,G[i]);
        b.insert(i,B[i]);
    }

    r.init(n);
    g.init(n);
    b.init(n);

    for(int i = 1;i <= n;i ++) {
        int x = getVal(i);
        q.push(-x,ID[i]);
    }

    while(n --) {
        int id = q.top(); q.pop();
        printf("%d\n",id);
        r.del(mp[id]);
        g.del(mp[id]);
        b.del(mp[id]);
    }
}
