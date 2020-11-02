#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

int n;

bool check(int i,int d) {
    int t = 0;
    for(int j = 0;j < n;j ++) if(i>>j&1) t ++;
    return t == d;
}

vector<int> g;
int num[SZ],top = 0;

bool dfs(int d) {
    if(top == n) {
        bool flag = 0;
       // for(int i = 1;i <= top;i ++) printf("%d ",num[i]); puts("");
        for(int i = 1;i <= top;i ++) {
            for(int j = i+1;j <= top;j ++) {
                if(!check(num[i]^num[j],n/2)) {
                    flag = 1;
                   // cout << num[i]^num[j] << endl;
                }
            }
        }
        if(!flag) {
            for(int i = 1;i <= top;i ++) printf("%d ",num[i]); puts("");
            for(int i = 1;i <= top;i ++) {
                for(int j = n-1;j >= 0;j --)
                    printf("%d",num[i]>>j&1);
                puts("");
            }
            return true;
        }
        return false;
    }
    if(d == g.size()) return false;
    if(dfs(d+1)) return true;
    num[++ top] = g[d];
    if(dfs(d+1)) return true;
    top --;
    return false;
}

int a[2010][2010];


int main() {
    int m = read();
    a[1][1] = 1; a[1][2] = 1;
    a[2][1] = 1; a[2][2] = -1;
    for(int now = 2;now < m;now *= 2) {
        for(int i = 1;i <= now;i ++)
            for(int j = now+1;j <= now*2;j ++)
                a[i][j] = a[i][j-now];
        for(int i = now+1;i <= 2*now;i ++)
            for(int j = 1;j <= now;j ++)
                a[i][j] = a[i-now][j];
        for(int i = now+1;i <= 2*now;i ++)
            for(int j = now+1;j <= now*2;j ++)
                a[i][j] = -a[i-now][j-now];
    }
    for(int i = 1;i <= m;i ++) {
        for(int j = 1;j <= m;j ++) {
            printf("%d%c",a[i][j],j == m?'\n' : ' ');
        }
    }
}
