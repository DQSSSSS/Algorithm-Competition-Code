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

int n,m,sum;

bool isin(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}

char mp[666][666];

int main() {
    n = read(),m = read(),sum = 0;
    for(int i = 1;i <= n;i ++) scanf("%s",mp[i]+1);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(mp[i][j] == '*') sum ++;
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(mp[i][j] == '*') {
                const int dx[] = {0,1,0,-1};
                const int dy[] = {1,0,-1,0};
                int tong[5] = {},t = 1,flag = 0;
                for(int k = 0;k < 4;k ++) {
                    int x = i,y = j;
                    while(isin(x+dx[k],y+dy[k]) && mp[x+dx[k]][y+dy[k]] == '*')
                        tong[k] ++,x += dx[k],y += dy[k];
                    if(tong[k] == 0) flag = 1;
                    t += tong[k];
                }
                if(!flag && t == sum) return puts("YES"),0;
            }
        }
    }
    puts("NO");
}
