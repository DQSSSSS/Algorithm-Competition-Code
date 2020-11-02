#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
const int mod = 998244353;
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

int a[510][510];
int b[510][510];
int rd[510];

int main() {
    int m = read(),n = read();
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++) {
            a[i][j] = read();
            if(a[i][j] == 0) a[i][j] = 1e9;
        }
    for(int x = 1;x <= m;x ++)
        for(int y = x + 1;y <= m;y ++) {
            int dx = 0,dy = 0;
            for(int i = 1;i <= n;i ++) {
                if(a[i][x] < a[i][y]) dx ++;
                if(a[i][x] > a[i][y]) dy ++;
            }
            if(dx > dy) b[x][y] = dx,rd[y] ++;
            if(dx < dy) b[y][x] = dy,rd[x] ++;
        }
/*
    for(int x = 1;x <= m;x ++) {
        for(int y = 1;y <= m;y ++) {
            cout << b[x][y] << " ";
        }
        puts("");
    }*/

    for(int k = 1;k <= m;k ++)
        for(int i = 1;i <= m;i ++)
            for(int j = 1;j <= m;j ++) {
                if(i == j) continue;
                if(i == k) continue;
                if(j == k) continue;
                b[i][j] = max(b[i][j],min(b[i][k],b[k][j]));
            }

    for(int i = 1;i <= m;i ++) {
        int t = 0;
        for(int j = 1;j <= m;j ++) {
            if(b[i][j] < b[j][i]) t = 1;
        }
        if(!t) printf("%d ",i);
    }

    return 0;
}
