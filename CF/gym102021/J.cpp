#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 3e5*4 + 10;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

int a[SZ][4][4];
vector<int> mp[SZ];

int get_cor_dir(int id,int x,int y) {
    for(int j = 0;j <= 3;j ++) {
        if(a[id][j][0] == x && a[id][j][1] == y) return j;
    }
    printf("impossible"),exit(0);
}

int get_another(int val,int id) {
    if(mp[val].size() != 2) printf("impossible"),exit(0);
    if(mp[val][0] == id) return mp[val][1];
    return mp[val][0];
}
bool vis[SZ];

vector<vector<pair<int,int> > > b;

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i][0][0] = read();
        a[i][0][1] = read();
        a[i][0][2] = read();
        a[i][0][3] = read();
        for(int j = 1;j <= 3;j ++) {
            for(int k = 0;k < 4;k ++)
                a[i][j][(j+k)%4] = a[i][0][k];
        }
        for(int j = 0;j < 4;j ++)
            if(a[i][0][j])
                mp[a[i][0][j]].push_back(i);
    }
    /*
    for(int k = 1;k <= n;k ++) {
        for(int i = 0;i < 4;i ++,puts(""))
            for(int j = 0;j < 4;j ++)
                cout << a[k][i][j] << " ";
        puts("");
    }
*/
    int id = -1;
    for(int i = 1;i <= n;i ++) {
        int t = 0;
        for(int j = 0;j < 4;j ++)
            if(!a[i][0][j])
                t ++;
        if(t >= 3) { id = i; break; }
    }

    if(id == -1)
        for(int i = 1;i <= n;i ++) {
            int t = 0;
            for(int j = 0;j < 4;j ++)
                if(!a[i][0][j])
                    t ++;
            if(t == 2) { id = i; break; }
        }
    if(id == -1) return printf("impossible"),0;

    vector<pair<int,int> > tmp;
    tmp.resize(n+1);
    b.push_back(tmp);
    b.push_back(tmp);

    int r = -1,c = -1;
    for(int i = 1;i <= n;i ++) {
        int zi = b[1][i-1].first,zj = b[1][i-1].second;
        int si = b[0][i].first,sj = b[0][i].second;
        int x = a[zi][zj][2],y = a[si][sj][3];
        b[1][i] = make_pair(id,get_cor_dir(id,x,y));
        vis[id] = 1;
        if(a[id][b[1][i].second][2] == 0) {
            c = i; break;
        }
        id = get_another(a[id][b[1][i].second][2],id);
        if(vis[id]) return printf("impossible"),0;
    }

    if(c == -1) return printf("impossible"),0;
    if(n % c) return printf("impossible"),0;
    r = n / c;

    tmp.resize(c+1);
    for(int j = 2;j <= r;j ++) {
        b.push_back(tmp);
        //cout << a[b[j-1][1].first][b[j-1][1].second][3] << " " << b[j-1][1].first << endl;
        id = get_another(a[b[j-1][1].first][b[j-1][1].second][3],b[j-1][1].first);
        if(vis[id]) return printf("impossible"),0;
        for(int i = 1;i <= c;i ++) {
            int zi = b[j][i-1].first,zj = b[j][i-1].second;
            int si = b[j-1][i].first,sj = b[j-1][i].second;
            int x = a[zi][zj][2],y = a[si][sj][3];
         //   cout << x << " " << y << " " << id << endl;
            b[j][i] = make_pair(id,get_cor_dir(id,x,y));
           // puts("cor is yes");
            vis[id] = 1;
            if(i < c && a[id][b[j][i].second][2] == 0)
                return printf("impossible"),0;
            if(i == c) break;
            id = get_another(a[id][b[j][i].second][2],id);
            if(vis[id]) return printf("impossible"),0;
        }
    }

    for(int i = 1;i <= r;i ++) {
        for(int j = 1;j <= c;j ++) {
            int id = b[i][j].first,dir = b[i][j].second;
            if(j == 1) {
                if(a[id][dir][0] != 0) return printf("impossible"),0;
            }
            if(j == c) {
                if(a[id][dir][2] != 0) return printf("impossible"),0;
            }

            if(i == 1) {
                if(a[id][dir][1] != 0) return printf("impossible"),0;
            }
            if(i == r) {
                if(a[id][dir][3] != 0) return printf("impossible"),0;
            }

            if(i < r) {
                int id2 = b[i+1][j].first,dir2 = b[i+1][j].second;
                if(a[id][dir][3] != a[id2][dir2][1]) return printf("impossible"),0;
                if(!a[id][dir][3]) return printf("impossible"),0;
            }

            if(j < c) {
                int id2 = b[i][j+1].first,dir2 = b[i][j+1].second;
                if(a[id][dir][2] != a[id2][dir2][0]) return printf("impossible"),0;
                if(!a[id][dir][2]) return printf("impossible"),0;
            }
        }
    }

    printf("%d %d\n",c,r);
    for(int j = 1;j <= c;j ++,puts(""))
        for(int i = 1;i <= r;i ++) {
            printf("%d ",b[i][j].first);
        }
}
/***
3
0 0 2 0
1 0 0 0
2 0 1 0

4
0 3 4 0
4 5 0 0
2 0 0 5
0 0 2 3

*/
