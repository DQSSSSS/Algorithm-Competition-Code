#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e7 + 10;
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
    int x,y,id;

    haha up() {
        haha ans;
        ans.x = x - 1; ans.y = y;
        if(id == 0) ans.id = 2;
        if(id == 1) ans.id = 1;
        if(id == 2) ans.id = 5;
        if(id == 3) ans.id = 3;
        if(id == 4) ans.id = 0;
        if(id == 5) ans.id = 4;
        return ans;
    }

    haha down() {
        haha ans;
        ans.x = x + 1; ans.y = y;
        if(id == 0) ans.id = 4;
        if(id == 1) ans.id = 1;
        if(id == 2) ans.id = 0;
        if(id == 3) ans.id = 3;
        if(id == 4) ans.id = 5;
        if(id == 5) ans.id = 2;
        return ans;
    }

    haha left() {
        haha ans;
        ans.x = x; ans.y = y - 1;
        if(id == 0) ans.id = 1;
        if(id == 1) ans.id = 5;
        if(id == 2) ans.id = 2;
        if(id == 3) ans.id = 0;
        if(id == 4) ans.id = 4;
        if(id == 5) ans.id = 3;
        return ans;
    }

    haha right() {
        haha ans;
        ans.x = x; ans.y = y + 1;
        if(id == 0) ans.id = 3;
        if(id == 1) ans.id = 0;
        if(id == 2) ans.id = 2;
        if(id == 3) ans.id = 5;
        if(id == 4) ans.id = 4;
        if(id == 5) ans.id = 1;
        return ans;
    }
};

int dist[5010][5010][6];

bool operator <(haha a,haha b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.id < b.id;
}

map<haha,haha> pr;

int sx,sy;

void bfs() {
    int n,m;
    n = 4500,m = n;
    memset(dist,-1,sizeof dist);
    dist[sx=10][sy=10][0] = 0;
    queue<haha> q;
    q.push((haha){sx,sy,0});
    while(q.size()) {
        haha u = q.front(); q.pop();
        haha nx;
        nx = u.down();
        if(1<=nx.x&&nx.x<=n&&1<=nx.y&&nx.y<=m&&dist[nx.x][nx.y][nx.id] == -1) {
            dist[nx.x][nx.y][nx.id] = dist[u.x][u.y][u.id] + 1; q.push(nx);
            //printf("[%d %d %d] -> [%d %d %d]\n",u.x,u.y,u.id,nx.x,nx.y,nx.id);
         //   pr[nx] = u;
        }
        nx = u.up();
        if(1<=nx.x&&nx.x<=n&&1<=nx.y&&nx.y<=m&&dist[nx.x][nx.y][nx.id] == -1) {
            dist[nx.x][nx.y][nx.id] = dist[u.x][u.y][u.id] + 1; q.push(nx);
            //printf("[%d %d %d] -> [%d %d %d]\n",u.x,u.y,u.id,nx.x,nx.y,nx.id);
         //   pr[nx] = u;
        }
        nx = u.left();
        if(1<=nx.x&&nx.x<=n&&1<=nx.y&&nx.y<=m&&dist[nx.x][nx.y][nx.id] == -1) {
            dist[nx.x][nx.y][nx.id] = dist[u.x][u.y][u.id] + 1; q.push(nx);
           // printf("[%d %d %d] -> [%d %d %d]\n",u.x,u.y,u.id,nx.x,nx.y,nx.id);
          //  pr[nx] = u;
        }
        nx = u.right();
        if(1<=nx.x&&nx.x<=n&&1<=nx.y&&nx.y<=m&&dist[nx.x][nx.y][nx.id] == -1) {
            dist[nx.x][nx.y][nx.id] = dist[u.x][u.y][u.id] + 1; q.push(nx);
           // printf("[%d %d %d] -> [%d %d %d]\n",u.x,u.y,u.id,nx.x,nx.y,nx.id);
          //  pr[nx] = u;
        }
    }

}

int tong[SZ];
vector<pii> g[8010];

int main() {
    //freopen("L.txt","w",stdout);
    bfs();
    for(int i = 0;i <= 10;i ++) {
        for(int j = i;j <= 10;j ++) {
            if(i+j<6)
                printf("dist[%d][%d]=%d;\n",i,j,dist[sx+i][sy+j][0]);
        }
    }
    return 0;
    for(int i = 0;i <= 4000;i ++) {
        for(int j = 0;j <= 4000;j ++) {
            g[i+j].push_back(make_pair(dist[sx+i][sy+j][0],i));
//            printf("%3d",dist[sx+i][sy+j][0]);
        }
 //       puts("");
    }
    for(int i = 1;i <= 8000;i ++) {
        sort(g[i].begin(),g[i].end());
        for(pii p : g[i]) tong[p.first] ++;
        int maxt = 0,v;
        for(pii p : g[i]) {
            if(tong[p.first] > maxt) {
                maxt = tong[p.first];
                v = p.first;
            }
        }
        printf("%d,",i,v);
        for(pii p : g[i]) tong[p.first] --;
    }

    for(int i = 1;i <= 8000;i ++) {
        sort(g[i].begin(),g[i].end());
        for(pii p : g[i]) tong[p.first] ++;
        int maxt = 0,v;
        for(pii p : g[i]) {
            if(tong[p.first] > maxt) {
                maxt = tong[p.first];
                v = p.first;
            }
        }
        for(pii p : g[i]) {
            if(p.first != v) {
                if(i-p.second < p.second)
                    printf("mp[%d][%d]=%d\n",i-p.second,p.second,p.first);
            }
        }

        for(pii p : g[i]) tong[p.first] --;
    }

}


/**
  0  3  4  5  4  7  8  9  8 11 12 13 12 15 16 17 16 19 20 21 20 23 24 25 24 27 28 29 28 31 32
  3  6  5  6  5  8  9 10  9 12 13 14 13 16 17 18 17 20 21 22 21 24 25 26 25 28 29 30 29 32 33
  4  5  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
  5  6  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33
  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34
  7  8  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
  8  9  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36
  9 10  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37
  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38
 11 12 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39
 12 13 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40
 13 14 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41
 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
 15 16 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43
 16 17 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44
 17 18 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45
 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46
 19 20 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47
 20 21 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48
 21 22 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
 23 24 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51
 24 25 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52
 25 26 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53
 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54
 27 28 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55
 28 29 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56
 29 30 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57
 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58
 31 32 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59
 32 33 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60
*/
