#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int b[1010][1010],n,m,q;

int g(int x,int y) {
    if(x<1||x>n||y<1||y>m) return 0;
    if(b[x][y]) return 1;
    return 0;
}

int get(int x,int y) {
    if(x == 1 && y == 1) return !b[1][1]&&!b[1][2]&&!b[2][1]&&!b[2][2];
    if(x == 1 && y == m) return !b[1][m]&&!b[1][m-1]&&!b[2][m]&&!b[2][m-1];
    if(x == n && y == 1) return !b[n][1]&&!b[n][2]&&!b[n-1][1]&&!b[n-1][2];
    if(x == n && y == m) return !b[n][m]&&!b[n][m-1]&&!b[n-1][m]&&!b[n-1][m-1];
    if(x == 1) return (!b[x][y]&&!b[x][y-1]&&!b[x+1][y]&&!b[x+1][y-1])
        + (!b[x][y]&&!b[x][y+1]&&!b[x+1][y]&&!b[x+1][y+1]);
    if(y == 1) return (!b[x][y]&&!b[x][y+1]&&!b[x+1][y]&&!b[x+1][y+1])
        + (!b[x][y]&&!b[x][y+1]&&!b[x-1][y]&&!b[x-1][y+1]);
    if(x == n) return (!b[x][y]&&!b[x][y-1]&&!b[x-1][y]&&!b[x-1][y-1])
        + (!b[x][y]&&!b[x][y+1]&&!b[x-1][y]&&!b[x-1][y+1]);
    if(y == m) return (!b[x][y]&&!b[x][y-1]&&!b[x+1][y]&&!b[x+1][y-1])
        + (!b[x][y]&&!b[x][y-1]&&!b[x-1][y]&&!b[x-1][y-1]);
    int tmp = 4;
    tmp -= g(x-1,y) | g(x,y-1) | g(x-1,y-1) | g(x,y);
    tmp -= g(x-1,y) | g(x,y+1) | g(x-1,y+1) | g(x,y);
    tmp -= g(x+1,y) | g(x,y-1) | g(x+1,y-1) | g(x,y);
    tmp -= g(x+1,y) | g(x,y+1) | g(x+1,y+1) | g(x,y);
    return tmp;
}

int main() {
    n = read(),m = read(),q = read();
    int ans = (n-1) * (m-1);
    while(q --) {
        int x = read(),y = read();
        int tmp = get(x,y);

        ans -= tmp;
        printf("%d\n",ans);
        b[x][y] = 1;
    }
}

/**
3 4 233
2 4
3 3
1 1

*/
