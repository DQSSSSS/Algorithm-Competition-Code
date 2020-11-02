#include <bits/stdc++.h>
using namespace std;
const int SZ = 1e3 + 5;
using pii = pair<int, int>;
const int INF = 1e9 + 10;
typedef long long LL;
int n,m,Q;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

void get(int k,int &x,int &y) {
    if(k == 0) return ;
    if(k == 1) { swap(x,y); return; }
    if(k == 2) { x = n - x + 1; y = m - y + 1; return; }
    if(k == 3) { swap(x,y); x = m-x+1; return; }
}

struct bcj {
    int fa[SZ];
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void init(int n) {
        for(int i = 1;i <= n;i ++) fa[i] = i;
    }
};

struct DataStructure {

    int n,m,a[SZ][SZ];
    int maxD[SZ][SZ];
    int maxL[SZ][SZ];
    int maxR[SZ][SZ];


    void change(int x,int y) {
        a[x][y] ^= 1;
        for(int i = 1;i <= m;i ++) {
            if(!a[x][i]) maxL[x][i] = 0;
            else {
                if(i == 1) maxL[x][i] = 1;
                else maxL[x][i] = maxL[x][i-1] + 1;
            }
        }

        for(int i = m;i >= 1;i --) {
            if(!a[x][i]) maxR[x][i] = 0;
            else {
                if(i == m) maxR[x][i] = 1;
                else maxR[x][i] = maxR[x][i+1] + 1;
            }
        }

        for(int i = n;i >= 1;i --) {
            if(!a[i][y]) maxD[i][y] = 0;
            else {
                if(i == n) maxD[i][y] = 1;
                else maxD[i][y] = maxD[i+1][y] + 1;
            }
        }
    }

    int ask(int x,int y) {
        if(a[x][y] == 0) return 0;

     /*   printf("ask: %d %d\n",x,y);
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                printf("%d ",a[i][j]);
            }
            puts("");
        }*/

        int dl = y, dr = y;
        while(dl > 1 && a[x][dl-1]) dl--;
        while(dr < m && a[x][dr+1]) dr++;

      //  printf("%d %d\n",dl,dr);

        vector<vector<int> > tong; tong.resize(n+1);
        for(int i = dl;i <= dr;i ++) tong[maxD[x][i]].push_back(i);

        vector<pii> vec;
        for(int i = 1;i <= n;i ++)
            for(int x : tong[i])
                vec.push_back({i,x});

        bcj A,B;
        A.init(m+1);
        B.init(m+1);

    //    for(int j = 1;j <= m;j ++) printf("%d ",maxD[x][j]); puts("");
    //    for(auto p : vec) printf("%d,%d ",p.first,p.second); puts("");

        int ans = 0;
        for(int i = x,j = 0;i <= n;i ++) {
            if(!a[i][y]) continue;

            while(j < vec.size() && vec[j].first < i-x+1) {
                int id = vec[j].second;
                if(id <= y) {
                    int xx = A.find(id);
                    int yy = A.find(id+1);
                    A.fa[xx] = yy;
                }
                if(id >= y) {
                    int xx = B.find(id);
                    int yy = B.find(id-1);
                    B.fa[xx] = yy;
                }
               // printf("id: %d\n",id);
                j ++;
            }

          //  for(int j = 1;j <= m;j ++) printf("%d ",A.find(j)); puts("");
          //  for(int j = 1;j <= m;j ++) printf("%d ",B.find(j)); puts("");

            int l = max(dl,y-maxL[i][y]+1);
            int r = min(dr,y+maxR[i][y]-1);

            int al = A.find(l);
            int ar = B.find(r);

          //  cout << i << " " << al << " " << ar << endl;

            if(l <= al && al <= y && y <= ar && ar <= r) {
                int tmp = (ar-al+1)*(i-x+1);
                ans = max(ans,tmp);
           //     printf("%d %d %d get %d\n",i,al,ar,tmp);
//
            }
        }
        return ans;
    }

    void init(int nn,int mm) {
        n = nn;
        m = mm;
    }

    void fuck(int x,int y,char c) {
        a[x][y] = c == '#' ? 1 : 0;
    }

    void prework() {
        /*for(int i = n;i >= 1;i --) {
            seg[i].build(1,1,m);
        }*/
        for(int y = 1;y <= m;y ++) {
            for(int i = n;i >= 1;i --) {
                if(!a[i][y]) maxD[i][y] = 0;
                else {
                    if(i == n) maxD[i][y] = 1;
                    else maxD[i][y] = maxD[i+1][y] + 1;
                }
            }
        }

        for(int x = 1;x <= n;x ++) {
            for(int i = 1;i <= m;i ++) {
                if(!a[x][i]) maxL[x][i] = 0;
                else {
                    if(i == 1) maxL[x][i] = 1;
                    else maxL[x][i] = maxL[x][i-1] + 1;
                }
            }

            for(int i = m;i >= 1;i --) {
                if(!a[x][i]) maxR[x][i] = 0;
                else {
                    if(i == m) maxR[x][i] = 1;
                    else maxR[x][i] = maxR[x][i+1] + 1;
                }
            }
        }
    }
}ds[4];

char mp[SZ][SZ];

int main() {
    int T = read(),cc = 0;
    while(T --) {
        n = read(),m = read(),Q = read();
        for(int i = 1;i <= n;i ++)
            scanf("%s",mp[i]+1);
        for(int k = 0;k < 4;k ++) {
            if(k&1) ds[k].init(m,n);
            else ds[k].init(n,m);
        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++) {
                for(int k = 0;k < 4;k ++) {
                    int xx = i,yy = j;
                    get(k,xx,yy);
                    ds[k].fuck(xx,yy,mp[i][j]);
                }
            }
        }

        for(int k = 0;k < 4;k ++) {
            ds[k].prework();
        }
        printf("Case #%d:\n",++ cc);
        while(Q --) {
            int o = read(),x = read(),y = read();
            if(o == 1) {
                for(int k = 0;k < 4;k ++) {
                    int xx = x,yy = y;
                    get(k,xx,yy);
                    ds[k].change(xx,yy);
                }
            }
            else {
                int ans = 0;
                for(int k = 0;k < 4;k ++) {
                    int xx = x,yy = y;
                    get(k,xx,yy);
                    int t = ds[k].ask(xx,yy);
                //    cout << k << " " << t << endl;
                    ans = max(ans,t);
                }
                printf("%d\n",ans);
            }
        }
    }
}

/*
2
2 3 2
###
##.
2 2 2
2 1 3
4 3 3
###
#.#
#.#
###
2 3 2
1 3 2
2 3 2





2
5 5 233
#.#.#
.#.#.
#.#.#
.#.#.
#.#.#


2
5 5 233
#.#.#
.#.#.
#####
.#.#.
#####
2 4 4

2
5 5 233
#.#.#
.#.#.
#.#.#
.#.#.
#.#.#
Case #1:
2 1 1
1
2 2 2
1
2 3 3
1
1 3 2
2 2 2
3
2 3 1
3
2 3 2
3
1 3 4
2 3 3
5
2 4 4
3
1 5 4
2 5 4
6
*/
