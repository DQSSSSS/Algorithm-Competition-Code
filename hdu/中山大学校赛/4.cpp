#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e6 + 10;
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

vector<int> v[3300],v2[3300];

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        bool flag = 0;
        if(n > m) swap(n,m),flag = 1;

        for(int i = 0;i <= n+1;i ++) {
            v[i].clear(); v[i].resize(m+2);
            v2[i].clear(); v2[i].resize(m+2);
        }

        int p,q;
        scanf("%d",&p);
        while(p --) {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(flag) swap(x1,y1),swap(x2,y2);
            v[x1][y1] ++;
            v[x1][y2+1] --;
            v[x2+1][y1] --;
            v[x2+1][y2+1] ++;
        }

        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
                v2[i][j] = v[i][j] ? 1 : 0;
            }
        }
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                v2[i][j] += v2[i-1][j] + v2[i][j-1] - v2[i-1][j-1];
            }
        }

        scanf("%d",&q);

        while(q --) {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(flag) swap(x1,y1),swap(x2,y2);

            int x = v2[x2][y2] - v2[x1-1][y2] - v2[x2][y1-1] + v2[x1-1][y1-1];
            if(x == (x2-x1+1) * (y2-y1+1)) puts("YES");
            else puts("NO");
        }
    }
}
