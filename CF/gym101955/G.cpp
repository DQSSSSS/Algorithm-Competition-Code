#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

int gen[10000010];
vector<int> pfs;
vector<pii> fj[10000010];

struct haha {
    int mp[6010][6010];
    bool vis[6010][6010];
    vector<pii> S;

    void clr() {
        for(pii p : S) {
            mp[p.first][p.second] = 0;
            vis[p.first][p.second] = 0;
        }
        S.clear();
    }

    void add(int x,int y,int w) {
        S.push_back(make_pair(x,y));
       // printf("add : (%d,%d) %d\n",x,y,w);
        mp[x][y] += w;
        vis[x][y] = 1;
    }

    void del(int x,int y) {
        mp[x][y] = 0;
        vis[x][y] = 0;
    }

    bool iscz(int x,int y) {
        return 1<=x&&x<=6000&&1<=y&&y<=6000&&vis[x][y];
    }

    void add_w(int x,int y,int k,int w) {
        for(pii p: fj[k]) {
            int dx = p.first;
            int dy = p.second;
            for(int i = -1;i <= 1;i += 2) {
                for(int j = -1;j <= 1;j += 2) {
                    int X = x + dx * i;
                    int Y = y + dy * j;
                    if(iscz(X,Y)) {
                        mp[X][Y] += w;
                    }
                }
            }
        }
        if(gen[k]) {
            int d = gen[k];
            if(iscz(x+d,y)) mp[x+d][y] += w;
            if(iscz(x-d,y)) mp[x-d][y] += w;
            if(iscz(x,y+d)) mp[x][y+d] += w;
            if(iscz(x,y-d)) mp[x][y-d] += w;
        }
    }

    LL ask(int x,int y,int k) {
        LL ans = 0;
        for(pii p: fj[k]) {
            int dx = p.first;
            int dy = p.second;
            for(int i = -1;i <= 1;i += 2) {
                for(int j = -1;j <= 1;j += 2) {
                    int X = x + dx * i;
                    int Y = y + dy * j;
                    if(iscz(X,Y)) {
                        ans += mp[X][Y];
                    }
                }
            }
        }
        if(gen[k]) {
            int d = gen[k];
            if(iscz(x+d,y)) ans += mp[x+d][y];
            if(iscz(x-d,y)) ans += mp[x-d][y];
            if(iscz(x,y+d)) ans += mp[x][y+d];
            if(iscz(x,y-d)) ans += mp[x][y-d];
        }
        return ans;
    }

}pm;

int main(){
    for(int i = 1;i * i <= 1e7;i ++) {
        pfs.push_back(i);
        gen[i*i] = i;
    }
    for(int x : pfs)
        for(int y : pfs)
            if(x*x+y*y <= 1e7)
                fj[x*x+y*y].push_back(make_pair(x,y));
    int T = read(),cc = 0;
    while(T --) {
        int n = read(),m = read();
        pm.clr();
        for(int i = 1;i <= n;i ++) {
            int x = read(),y = read(),w = read();
            pm.add(x,y,w);
        }
        printf("Case #%d:\n",++ cc);
        LL lstans = 0;
        for(int i = 1;i <= m;i ++) {
            int opt = read(),x = read(),y = read(),k,w;
            x = (x+lstans)%6000+1;
            y = (y+lstans)%6000+1;
            if(opt == 1) {
                w = read();
                pm.add(x,y,w);
            }
            if(opt == 2) {
                pm.del(x,y);
            }
            if(opt == 3) {
                k = read(),w = read();
                pm.add_w(x,y,k,w);
            }
            if(opt == 4) {
                k = read();
                printf("%lld\n",lstans = pm.ask(x,y,k));
            }
        }
    }
}

