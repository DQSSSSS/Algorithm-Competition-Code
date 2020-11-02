#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 1e17;

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
    bool flag;
    LL x;
};

void add(haha &a,haha &b) {
    a.flag |= b.flag;
    if(a.x+b.x>=(LL)1e17) a.flag = 1;
    (a.x += b.x)%=mod;
}

haha f[SZ][4][4];

int main() {
    int n = read();
    f[1][1][1].x = 1;
    f[1][2][1].x = 1;
    f[1][3][1].x = 1;
    for(int i = 2;i <= n;i ++) {
        for(int j = 1;j <= 3;j ++) {
            add(f[i][j][2],f[i-1][j][1]);
        }
        add(f[i][1][1],f[i-1][2][1]);
        add(f[i][1][1],f[i-1][2][2]);
        add(f[i][1][1],f[i-1][3][1]);
        add(f[i][1][1],f[i-1][3][2]);

        add(f[i][2][1],f[i-1][1][1]);
        add(f[i][2][1],f[i-1][1][2]);
        add(f[i][2][1],f[i-1][3][1]);
        add(f[i][2][1],f[i-1][3][2]);

        add(f[i][3][1],f[i-1][1][1]);
        add(f[i][3][1],f[i-1][1][2]);
        add(f[i][3][1],f[i-1][2][1]);
        add(f[i][3][1],f[i-1][2][2]);
    }
    haha ans; ans.x = 0; ans.flag = 0;
    for(int i = 1;i <= 3;i ++)
        for(int j = 1;j <= 2;j ++)
            add(ans,f[n][i][j]);
    if(ans.flag) {
        ans.x %= (LL)1e10;
        printf("......%010lld\n",ans.x);
    }
    else {
        printf("%lld\n",ans.x);
    }
    return 0;
}

