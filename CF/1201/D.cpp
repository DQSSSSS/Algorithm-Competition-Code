#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const LL INF = 1e15 + 10;
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
    LL pos;
    LL dist;
}a[4];

LL gd(LL f,LL t,LL mx,LL mn) {
    LL d1 = max(max(f,t),max(mx,mn));
    LL d2 = min(min(f,t),min(mx,mn));
    return 2*(d1-d2)-abs(f-t);
}

LL amn[SZ],amx[SZ],b[SZ];

int main() {
    LL n = read(),m = read(),k = read(),q = read();
    LL maxx = 1;
    for(int i = 1;i <= n;i ++) amn[i] = INF,amx[i] = 0;
    amn[1] = 1; amx[1] = 1;
    for(int i = 1;i <= k;i ++) {
        LL x = read(),y = read();
        maxx = max(maxx,x);
        amn[x] = min(amn[x],y);
        amx[x] = max(amx[x],y);
    }
    for(int i = 1;i <= q;i ++) b[i] = read();
    sort(b+1,b+1+q);
    b[0] = -INF,b[q+1] = INF;
    q ++;

    for(int i = 0;i < 4;i ++) {
        a[i].pos = 1;
        a[i].dist = 0;
    }

    LL ans = INF;
    for(int i = 1;i <= n;i ++) {
        if(amn[i] == INF) continue;
        LL x1 = amn[i],x2 = amx[i];
        if(i < maxx) {
            haha aa[4],tmp;
            int id;
            id = lower_bound(b,b+q+1,amn[i])-b-1;
            tmp.pos = b[id]; tmp.dist = INF;
            for(int now = 0;now < 4;now ++) {
                tmp.dist = min(tmp.dist,a[now].dist + gd(a[now].pos,tmp.pos,x1,x2));
            }
            aa[0] = tmp;

            id = lower_bound(b,b+q+1,amn[i])-b;
            tmp.pos = b[id]; tmp.dist = INF;
            for(int now = 0;now < 4;now ++) {
                tmp.dist = min(tmp.dist,a[now].dist + gd(a[now].pos,tmp.pos,x1,x2));
            }
            aa[1] = tmp;

            id = lower_bound(b,b+q+1,amx[i])-b-1;
            tmp.pos = b[id]; tmp.dist = INF;
            for(int now = 0;now < 4;now ++) {
                tmp.dist = min(tmp.dist,a[now].dist + gd(a[now].pos,tmp.pos,x1,x2));
            }
            aa[2] = tmp;

            id = lower_bound(b,b+q+1,amx[i])-b;
            tmp.pos = b[id]; tmp.dist = INF;
            for(int now = 0;now < 4;now ++) {
                tmp.dist = min(tmp.dist,a[now].dist + gd(a[now].pos,tmp.pos,x1,x2));
            }
            aa[3] = tmp;

            for(int now = 0;now < 4;now ++) a[now] = aa[now];
        }
        else {
            for(int now = 0;now < 4;now ++) {
                ans = min(ans,a[now].dist + gd(a[now].pos,x1,x1,x2));
                ans = min(ans,a[now].dist + gd(a[now].pos,x2,x1,x2));
            }
        }
    }

    cout << ans + maxx - 1 << endl;

}
/**
4 5 6 1
1 3
2 1
2 4
3 5
4 2
4 5
2

4 5 2 1
3 1
4 4
3

3 6 3 1
1 6
2 2
3 4
6

*/
