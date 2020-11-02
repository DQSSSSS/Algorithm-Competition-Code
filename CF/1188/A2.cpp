#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
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

struct edge {
    int t,d;
};

vector<edge> g[SZ];

int n,du[SZ];

bool check1() {
    for(int i = 1;i <= n;i ++) {
        if(du[i] == 2) {
            if(g[i][0].d != g[i][1].d) return false;
        }
    }
    return true;
}

struct haha {
    int x,y,z;
}l[SZ];

int del[SZ];
vector<haha> ans;

void add(int x,int y,int z) {
    ans.push_back((haha){x,y,-z});
}

pii find_leaf(int x,int f) {
    int t = 0,X,Y;
    for(edge e : g[x]) {
        int u = e.t;
        if(del[u]) continue;
        if(u == f) continue;
        t ++;
        int lst = x;
        while(du[u] != 1) {
            for(edge e2 : g[u]) {
                int v = e2.t;
                if(del[v]) continue;
                if(v == lst) continue;
                lst = u;
                u = v; break;
            }
        }
        if(t == 1) X = u;
        else Y = u;
        if(t == 2) return make_pair(X,Y);
    }
}

int main() {
    n = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read(),z = read();
        g[x].push_back((edge){y,z});
        g[y].push_back((edge){x,z});
        du[x] ++; du[y] ++;
    }
    if(check1()) {
        puts("YES");
        for(int i = 1;i <= n;i ++) {
            if(du[i] == 2) {
               edge e1 = g[i][0];
               edge e2 = g[i][1];
               g[e1.t].push_back((edge){e2.t,e1.d});
               g[e2.t].push_back((edge){e1.t,e1.d});
               del[i] = 1;
            }
        }

        int tot = 0;
        for(int u = 1;u <= n;u ++) {
            for(edge e : g[u]) {
                if(!del[u] && !del[e.t] && e.t > u) {
                    l[++ tot].x = u;
                    l[tot].y = e.t;
                    l[tot].z = e.d;
                }
            }
        }
   //     for(int i = 1;i <= tot;i ++) {
    //        printf("%d %d %d\n",l[i].x,l[i].y,l[i].z);
    //    }
        for(int i = 1;i <= tot;i ++) {
            int x = l[i].x,y = l[i].y;
            int z = l[i].z;
            if(!z) continue;
            if(du[y] == 1) swap(x,y);
            if(du[x] == 1 && du[y] == 1) {
                add(x,y,-z);
            }
            else if(du[x] == 1) {
                pii a = find_leaf(y,x);
                add(x,a.first,-z/2);
                add(x,a.second,-z/2);
                add(a.first,a.second,z/2);
            }
            else {
           //         cout << x << " " << y << endl;
                pii a = find_leaf(y,x);
                pii b = find_leaf(x,y);
                add(a.first,b.first,-z/2);
                add(a.second,b.second,-z/2);
                add(a.first,a.second,z/2);
                add(b.first,b.second,z/2);
            }
        }
        cout << ans.size() << endl;
        for(int i = 0;i < ans.size();i ++) {
            printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
        }
    }
    else puts("NO");
    return 0;
}
/**
5
1 2 2
2 3 2
3 4 10
3 5 18

*/
