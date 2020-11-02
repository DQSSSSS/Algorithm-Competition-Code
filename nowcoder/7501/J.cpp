#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e6 + 10;
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

int n,m,a,b;
LL A[1010][1010];
LL tree[1010][1010];
LL sum[1010][1010];

bool isin(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}

void work() {
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            sum[i][j] = tree[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            LL x = sum[i][j] + A[i][j];
            if(x==0) continue;
            if(x<0 || !isin(i+a-1,j+b-1)) {
                puts("QAQ"); return ;
            } else {
                tree[i][j] -= x;
                tree[i+a][j] += x;
                tree[i][j+b] += x;
                tree[i+a][j+b] -= x;
                sum[i][j] -= x;
            }
        }
    }
    puts("^_^");
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read(),a = read(),b = read();
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                A[i][j] = read();
                tree[i][j] = 0;
                sum[i][j] = 0;
            }
        }
        work();
    }
}
