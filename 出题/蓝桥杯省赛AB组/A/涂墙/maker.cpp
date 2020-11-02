#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 998244353;
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

mt19937 rd(time(0));

int randlr(int l,int r) { return rd()%(r-l+1)+l; }

bool mp[2010][2010];

void get_data() {
    int T = 10;
    printf("%d\n",T);
    while(T --) {
        int n = randlr(1900,2000);
        int m = min(n*n,randlr(0,45000));
        printf("%d %d\n",n,m);
        memset(mp,0,sizeof mp);
        while(m --) {
            int x = randlr(1,n);
            int y = randlr(1,n);
            while(mp[x][y]) {
                x = randlr(1,n),y = randlr(1,n);
            }
            mp[x][y] = 1;
            printf("%d %d\n",x,y);
        }
    }
}

int main() {
    for(int i = 6;i < 10;i ++) {
        string s = "data"; s += i + '0'; s += ".in";
        freopen(s.c_str(),"w",stdout);
        get_data();
        fclose(stdout);
    }
    return 0;
}
