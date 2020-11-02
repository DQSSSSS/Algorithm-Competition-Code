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

vector<pii> g[SZ];

struct haha {
    int u,id;
    LL w;
};

bool operator <(haha a,haha b) {
    return a.w > b.w;
}

struct hh {

    priority_queue<haha> q;

    void push(int u,int id,LL w) {
       // printf("%d %d %lld\n",u,id,w);
        q.push((haha){u,id,w});
    }

    haha top() {
        assert(q.size());
        return q.top();
    }

    void pop() {
        assert(q.size());
        haha f = q.top(); q.pop();
     //   printf("%d %d %lld:\n",f.u,f.id,f.w);
        int u = f.u,v = g[u][f.id].second;
        if(g[v].size()) {
            push(v,0,f.w+g[v][0].first);
        }

        f.w -= g[u][f.id].first;
        f.id ++;
        if(f.id < g[u].size())
            f.w += g[u][f.id].first,push(f.u,f.id,f.w);
      //  puts("----------");
    }

    void clr() {
        while(q.size()) q.pop();
    }
}q;


LL ans[SZ];
pii b[SZ];

int main() {
    int T = read();
    while(T --) {
        q.clr();
        int n = read(),m = read(),Q = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read(),w = read();
            g[x].push_back(make_pair(w,y));
        }
        for(int i = 1;i <= n;i ++) sort(g[i].begin(),g[i].end());

        for(int i = 1;i <= n;i ++) {
            if(g[i].size())
                q.push(i,0,g[i][0].first);
        }
        for(int i = 1;i <= Q;i ++) {
            b[i].first = read();
            b[i].second = i;
        }
        sort(b+1,b+1+Q);
        int now = 1;
        for(int i = 1;i <= Q;i ++) {
            while(now < b[i].first) {
                q.pop();
                now ++;
            }
            //cout << now << endl;
            haha x = q.top();
            ans[b[i].second] = x.w;
        }
        for(int i = 1;i <= Q;i ++) printf("%lld\n",ans[i]);
    }
}
