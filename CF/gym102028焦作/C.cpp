#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e3 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct node {
    int x,y,id;
};
bool operator <(node a,node b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.id < b.id;
}

set<node> s[9];
set<pii> sx,sy;
int n,m;

void init() {
    for(int i = 1;i <= n;i ++) {
        bool flag = 0;
        if(a[i].x == 1) s[0].insert(a[i]),flag = 1;
        if(a[i].x == n) s[2].insert(a[i]),flag = 1;
        if(a[i].y == n) s[1].insert(a[i]),flag = 1;
        if(a[i].y == 1) s[3].insert(a[i]),flag = 1;
        if(a[i].x == 1 && a[i].y == 1) {
            s[0].clear(); s[3].clear(); s[4].insert(a[i]); flag = 1;
        }
        if(a[i].x == 1 && a[i].y == n) {
            s[0].clear(); s[1].clear(); s[5].insert(a[i]); flag = 1;
        }
        if(a[i].x == n && a[i].y == n) {
            s[1].clear(); s[2].clear(); s[6].insert(a[i]); flag = 1;
        }
        if(a[i].x == n && a[i].y == 1) {
            s[2].clear(); s[3].clear(); s[7].insert(a[i]); flag = 1;
        }
        if(!flag) {
            s[8].insert(a[i]);
            sx.insert(make_pair(a[i].x,i));
            sy.insert(make_pair(a[i].y,i));
        }
    }
}


int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 0;i < 9;i ++) s[i].clear();
        sx.clear(); sy.clear();

        for(int i = 1;i <= n;i ++) {
            a[i].x = read(),a[i].y = read();
            a[i].id = i;
        }

        init();

        int x1 = 1,y1 = 1,x2 = n,y2 = n,dx = 0,dy = 0;
        while(m --) {
            char o[2];
            scanf("%s",o);
            if(o[0] == '?') {
                int i = read();
                int ansx = a[i].x,ansy = a[i].y;
                if(s[8].find(a[i])) ansx+=dx,ansy+=dy;

                if(s[4].find(a[i])) ansx=x1,ansy=y1;
                if(s[5].find(a[i])) ansx=x1,ansy=y2;
                if(s[6].find(a[i])) ansx=x2,ansy=y2;
                if(s[7].find(a[i])) ansx=x2,ansy=y1;

                if(s[0].find(a[i])) ansx=x1,ansy+=dy;
                if(s[1].find(a[i])) ansx+=dx,ansy=y2;
                if(s[2].find(a[i])) ansx=x2,ansy+=dy;
                if(s[3].find(a[i])) ansx+=dx,ansy=y1;
                printf("%d %d\n",ansx,ansy);
            }
            else if(o[0] == '!') {
                LL ans = 0;
                for(int i = 4;i < 8;i ++) {
                    LL x = s[i].size();
                    ans += x * (x-1) / 2;
                }
                printf("%lld\n",ans);
            }
            else {
                int d = read();
                int ddx,ddy;
                if(o[0] == 'U') { ddx = -d,ddy = 0; }
                if(o[0] == 'D') { ddx = d,ddy = 0; }
                if(o[0] == 'L') { ddx = 0,ddy = -d; }
                if(o[0] == 'R') { ddx = 0,ddy = d; }
                dx += ddx,dy += ddy;
                x1 += ddx; x1 = min(x1,n); x1 = max(x1,1);
                x2 += ddx; x2 = min(x2,n); x2 = max(x2,1);
                y1 += ddy; y1 = min(y1,n); y1 = max(y1,1);
                y2 += ddy; y2 = min(y2,n); y2 = max(y2,1);


            }
        }
    }
}
