#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
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

int X[SZ],Y[SZ];

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read(),m = read();
        for(int i = 0;i <= m+1;i ++) X[i] = Y[i] = 0;
        for(int i = 1;i <= n;i ++) {
            int x = read(),y = read();
            char s[2];
            scanf("%s",s);
            if(s[0] == 'N') Y[y+1] ++,Y[m+1] --;
            else if(s[0] == 'S') Y[0] ++,Y[y] --;
            else if(s[0] == 'W') X[0] ++,X[x] --;
            else X[x+1] ++,X[m+1] --;
        }
        int maxx = 0,maxy = 0;
        for(int i = 1;i <= m;i ++) X[i] += X[i-1];
        for(int i = 0;i <= m;i ++) maxx = max(maxx,X[i]);
        for(int i = 1;i <= m;i ++) Y[i] += Y[i-1];
        for(int i = 0;i <= m;i ++) maxy = max(maxy,Y[i]);
        int minx = 1e9,miny = 1e9;
        for(int i = 0;i <= m;i ++) if(maxx == X[i]) { minx = i; break; }
        for(int i = 0;i <= m;i ++) if(maxy == Y[i]) { miny = i; break; }
        printf("Case #%d: %d %d\n",cc,minx,miny);
    }
}
/**
3
1 10
5 5 N
4 10
2 4 N
2 6 S
1 5 E
3 5 W
8 10
0 2 S
0 3 N
0 3 N
0 4 N
0 5 S
0 5 S
0 8 S
1 5 W

*/
