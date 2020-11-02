#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

vector<pii> G[SZ];
int dist[SZ],ans[SZ],a[SZ];

void work() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        ans[i] = -1;
    }
    for(int i = 1;i <= n;i ++) {
        G[i].clear();
        dist[i] = 1e9;
    }
    for(int i = 2;i <= n;i ++) {
        a[i] = read();
    }
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        G[x].push_back({y,i});
        G[y].push_back({x,i});
    }

    vector<int> vec; vec.push_back(1);
    dist[1] = 0;
    while(vec.size() < n) {
       // for(int u : vec) cout << u << " "; puts("");
        int minrank = 1e9,mindist = 1e9;
        for(int u : vec) {
            for(auto e : G[u]) {
                int v = e.first;
                if(dist[v] == 1e9) {
                    if(a[v] < 0) {
                        minrank = min(minrank,-a[v]);
                    }
                    else {
                        mindist = min(mindist,a[v]);
                    }
                }
            }
        }
      //  cout << minrank << " " << mindist << endl;
        int maxd = 0;
        for(int u : vec) {
            maxd = max(maxd,dist[u]);
        }
        vector<int> tmp;
        if(minrank == vec.size()) {
            for(int u : vec) {
                for(auto e : G[u]) {
                    int v = e.first;
                    if(dist[v] == 1e9) {
                        if(a[v] < 0 && minrank == -a[v]) {
                            dist[v] = maxd+1;
                            tmp.push_back(v);
                            ans[e.second] = max(ans[e.second],dist[v] - dist[u]);
                        }
                    }
                }
            }
        }
        else {
            for(int u : vec) {
                for(auto e : G[u]) {
                    int v = e.first;
                    if(dist[v] == 1e9) {
                        if(a[v] > 0 && mindist == a[v]) {
                            dist[v] = maxd+mindist - maxd;
                            tmp.push_back(v);
                            ans[e.second] = max(ans[e.second],dist[v] - dist[u]);
                        }
                    }
                }
            }
        }
        for(int x : tmp) vec.push_back(x);
    }
    for(int i = 1;i <= m;i ++) if(ans[i] == -1) ans[i] = 1e6;
    for(int i = 1;i <= m;i ++) {
        printf("%d ",ans[i]);
    }
    puts("");
}

int main(){
    int T = read();
    int cc = 0;
    while(T --) {
        printf("Case #%d: ",++ cc);
        work();
    }
    return 0;
}

