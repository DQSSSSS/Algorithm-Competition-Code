#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int n,m;
bool flag = 0;

vector<vector<int> > g;

void print() {
    if(flag) {
        vector<vector<int> > ans;
        ans.resize(m+1);
        for(int i = 1;i <= m;i ++) ans[i].resize(n+1);
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                int x = (g[i][j]-1) / m + 1;
                int y = (g[i][j]-1) % m + 1;
                ans[j][i] = (y-1)*n+x;
            }
        }
        swap(n,m);
        g = ans;
    }
/*
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            for(int k = 0;k < 4;k ++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if(isin(x,y)) {
                    G[(x-1)*m+y][(i-1)*m+j] = 1;
                }
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            for(int k = 0;k < 4;k ++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if(isin(x,y)) {
                    int a = num[x][y];
                    int b = num[i][j];
                    //printf("-%d %d %d\n",a,b,g[a][b]);
                    assert(G[a][b] == 0);
                }
            }
        }
    }
*/
    puts("YES");
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            printf("%d ",g[i][j]);
        }
        puts("");
    }
}

int main() {
    n = read(),m = read();
    if(n>m) swap(n,m),flag = 1;
    g.resize(n+1);
    for(int i = 1;i <= n;i ++) g[i].resize(m+1);
    if(n == 1) {
        if(m == 1) return puts("YES\n1"),0;
        else if(m <= 3) return puts("NO"),0;
        else {
            if(m == 4) {
                g[1][1] = 2;
                g[1][2] = 4;
                g[1][3] = 1;
                g[1][4] = 3;
            }
            else {
                int t = 1;
                for(int i = 1;i <= m;i += 2) g[1][t++] = i;
                for(int i = 2;i <= m;i += 2) g[1][t++] = i;
            }
        }
    }
    else if(n == 2) {
        if(m <= 3) return puts("NO"),0;
        else if(m == 4) {
            g[1][1] = 1;
            g[1][2] = 3;
            g[1][3] = 5;
            g[1][4] = 2;

            g[2][1] = 8;
            g[2][2] = 6;
            g[2][3] = 4;
            g[2][4] = 7;
        }
        else {
            for(int j = 1;j <= n;j ++) {
                int t = (j-1)%m+1;
                for(int i = 1;i <= m;i += 2) {
                    g[j][t++] = (j-1)*m+i;
                    if(t == m+1) t = 1;
                }
                for(int i = 2;i <= m;i += 2) {
                    g[j][t++] = (j-1)*m+i;
                    if(t == m+1) t = 1;
                }
            }
        }
    }
    else if(n == 3) {
        if(m == 3) {
            g[1][1] = 1;
            g[1][2] = 3;
            g[1][3] = 4;

            g[2][1] = 5;
            g[2][2] = 7;
            g[2][3] = 6;

            g[3][1] = 9;
            g[3][2] = 2;
            g[3][3] = 8;
        }
        else if(m == 4) {
            g[1][1] = 1;
            g[1][2] = 3;
            g[1][3] = 5;
            g[1][4] = 2;

            g[2][1] = 4;
            g[2][2] = 6;
            g[2][3] = 12;
            g[2][4] = 9;

            g[3][1] = 11;
            g[3][2] = 8;
            g[3][3] = 10;
            g[3][4] = 7;
        }
        else {
            for(int j = 1;j <= n;j ++) {
                int t = (j-1)%m+1;
                for(int i = 1;i <= m;i += 2) {
                    g[j][t++] = (j-1)*m+i;
                    if(t == m+1) t = 1;
                }
                for(int i = 2;i <= m;i += 2) {
                    g[j][t++] = (j-1)*m+i;
                    if(t == m+1) t = 1;
                }
            }
        }
    }
    else if(n == 4) {
        if(m == 4) {
            g[1][1] = 1;
            g[1][2] = 3;
            g[1][3] = 5;
            g[1][4] = 2;

            g[2][1] = 4;
            g[2][2] = 6;
            g[2][3] = 8;
            g[2][4] = 9;

            g[3][1] = 7;
            g[3][2] = 12;
            g[3][3] = 13;
            g[3][4] = 11;

            g[4][1] = 15;
            g[4][2] = 10;
            g[4][3] = 16;
            g[4][4] = 14;
        }
        else {
            for(int j = 1;j <= n;j ++) {
                int t = (j-1)%m+1;
                for(int i = 1;i <= m;i += 2) {
                    g[j][t++] = (j-1)*m+i;
                    if(t == m+1) t = 1;
                }
                for(int i = 2;i <= m;i += 2) {
                    g[j][t++] = (j-1)*m+i;
                    if(t == m+1) t = 1;
                }
            }
        }
    }
    else {
        for(int j = 1;j <= n;j ++) {
            int t = (j-1)%m+1;
            for(int i = 1;i <= m;i += 2) {
                g[j][t++] = (j-1)*m+i;
                if(t == m+1) t = 1;
            }
            for(int i = 2;i <= m;i += 2) {
                g[j][t++] = (j-1)*m+i;
                if(t == m+1) t = 1;
            }
        }
    }
    print();
}
