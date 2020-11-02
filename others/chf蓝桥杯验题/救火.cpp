#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
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

const int dx[] = {-1,-1,1,1,-2,-2,2,2};
const int dy[] = {-2,2,2,-2,-1,1,-1,1};

int n,m;

bool isin(int x,int y) {
    if(x < 1 ||y < 1 || x > n || y > m) return false;
    return true;
}

int mhdjl(int sx,int sy,int ex,int ey) {
    return abs(sx - ex) + abs(sy - ey);
}

struct Heap{
    int x,y,d;
};

bool operator <(Heap a,Heap b) { return a.d > b.d; }

int dist[22][22];
bool vis[22][22];
priority_queue<Heap> q;

int dij(int sx,int sy,int ex,int ey) {
    memset(dist,63,sizeof dist);
    memset(vis,0,sizeof vis);
    dist[ex-sx+10][ey-sy+10] = 0;
    q.push((Heap){sx,sy,0});
    while(q.size()) {
        Heap f = q.top(); q.pop();
        int x = ex-f.x+10;
        int y = ey-f.y+10;
        if(x < 0 || x > 20 || y < 0 || y > 20) continue;
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        for(int i = 0;i < 8;i ++) {
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];
            if(isin(nx,ny)) {
                int xx = ex-nx+10;
                int yy = ey-ny+10;
                if(xx >= 0 && xx <= 20 && yy >= 0 && yy <= 20) {
                //cout << xx <<" " << yy << " " << x << " " << y << endl;
                    if(dist[xx][yy] > dist[x][y] + 1) {
                        dist[xx][yy] = dist[x][y] + 1;
                        q.push((Heap){nx,ny,dist[xx][yy]});
                    }
                }
            }
        }
    }
   /* for(int i = -10;i <= 10;i ++,puts(""))
        for(int j = -10;j <= 10;j ++)
            if(dist[i+10][j+10] == 0x3f3f3f3f) printf("   ");
            else printf("%3d",dist[i+10][j+10]);*/
    if(dist[10][10] == 0x3f3f3f3f) { puts("-1"); return -1; }
    return dist[10][10];
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        int sx = 1,sy = 1,ex = read(),ey = read();
        int d = 0;
        while(233) {
            int xd = ex - sx;
            int yd = ey - sy;
            if(abs(xd) <= 10 && abs(yd) <= 10) break;
            int nx = sx,ny = sy;
            if(abs(xd) > abs(yd)) {
                if(xd > 0) sx += 2;
                else if(xd < 0) sx -= 2;
                else {
                    if(sx + 2 <= n) sx += 2;
                    else sx -= 2;
                }
                if(yd > 0) sy += 1;
                else if(yd < 0) sy -= 1;
                else {
                    if(sy + 1 <= m) sy += 1;
                    else sy -= 1;
                }
            }
            else {
                if(xd > 0) sx += 1;
                else if(xd < 0) sx -= 1;
                else {
                    if(sx + 1 <= n) sx += 1;
                    else sx -= 1;
                }
                if(yd > 0) sy += 2;
                else if(yd < 0) sy -= 2;
                else {
                    if(sy + 2 <= m) sy += 2;
                    else sy -= 2;
                }
            }
            swap(nx,sx);
            swap(ny,sy);
            if(!isin(nx,ny)) break;
            d ++;
            sx = nx; sy = ny;
        }
        if(abs(sx-ex) > 10 || abs(sy-ey) > 10) { puts("-1"); continue; }
        int tmp = dij(sx,sy,ex,ey);
        if(tmp == -1) continue;
        d += tmp;
        printf("%d\n",d);
    }
    return 0;
}
/**
5
1 1 1 1
2 2 2 2
2 3 2 3
3 5 3 5
4 4 4 4
*/

