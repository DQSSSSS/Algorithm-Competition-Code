#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

struct haha {
    int t;
    LL d;
};

vector<haha> g[SZ];
int n,k,m;

int id(int x,int y) {
    return (x-1) * k + y;
}

deque<int> q;
LL dist[SZ];
bool use[SZ];

bool spfa(int s,LL mid) {
    for(int i = 1;i <= n * k;i ++) dist[i] = 1e13,use[i] = 0;
    dist[id(s,1)] = 0;
    q.push_front(id(s,1));
    use[id(s,1)] = 1;
    while(q.size()) {
        if(q.size() >= 2 && q.front() > q.back()) {
            int x = q.front(); q.pop_front();
            int y = q.back(); q.pop_back();
            q.push_front(y);
            q.push_back(x);
        }
        int u = q.front(); q.pop_front();
        use[u] = 0;
        int x = (u-1)/k+1,y = (u-1)%k+1;
      //  cout << u << " " << x << " " << y << endl;
        for(haha e: g[x]) {
            int v = e.t;
            if(e.d > mid) continue;
          /*  if(x == 6)   {
                cout << u << " " << x << " " << y << endl;
                cout << v << " " << dist[id(v,y)] << endl;
                cout << dist[u] + e.d << endl;
            }*/
            if(dist[u] + e.d <= mid) {
                if(dist[id(v,y)] > dist[u] + e.d) {
                    dist[id(v,y)] = dist[u] + e.d;
                    if(!use[id(v,y)]) {
                        use[id(v,y)] = 1;
                        if(q.empty() || dist[id(v,y)] < dist[q.front()])
                            q.push_front(id(v,y));
                        else
                            q.push_back(id(v,y));
                    }
                }
            }
            else {
                if(y < k && dist[id(v,y+1)] > e.d) {
                    dist[id(v,y+1)] = e.d;
                    if(!use[id(v,y+1)]) {
                        use[id(v,y+1)] = 1;
                        if(q.empty() || dist[id(v,y+1)] < dist[q.front()])
                            q.push_front(id(v,y+1));
                        else
                            q.push_back(id(v,y+1));
                    }
                }
            }
        }
    }
   /* cout << s << endl;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= k;j ++) {
            printf("%20lld",dist[id(i,j)]);
        }
        puts("");
    }*/
    for(int i = 1;i <= n;i ++) {
        int b = 0;
        for(int j = 1;j <= k;j ++) {
            if(dist[id(i,j)] != 1e13) {
                b = 1; break;
            }
        }
        if(b == 0) return false;
    }
    return true;
}

bool check(LL mid) {
    for(int i = 1;i <= n;i ++) {
        if(!spfa(i,mid)) return false;
    }
    return true;
}

int main() {
    int T = read();
    while(T --) {
        n = read(),k = read(),m = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i <= m;i ++) {
            int x = read()+1,y = read()+1,z = read();
            g[x].push_back((haha){y,z});
            g[y].push_back((haha){x,z});
        }
       // check(688);
        LL l = 0,r = 1e13;
        while(r - l > 1) {
            LL mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%lld\n",r);
    }
}
/**
233
10 2 15
0 1 113
1 2 314
2 3 271
3 4 141
4 0 173
5 7 235
7 9 979
9 6 402
6 8 431
8 5 462
0 5 411
1 6 855
2 7 921
3 8 355
4 9 113

*/
