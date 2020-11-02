#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,int> pli;
const int SZ = 510;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

char a[SZ];
int f[SZ][SZ][3];

int dfs(int l,int r,int b) {
    if(l > r) return 0;
    if(f[l][r][b] != -1) return f[l][r][b];
   // cout << l << " " << r << " " << b << endl;
    if(b == 0) {
        /*int ans = dfs(l+1,r-1,0) + (a[l] == a[r] ? 1 : 2);
        for(int i = l+1;i < r;i ++) {
            if(a[l] == a[r])
                ans = min(ans,dfs(l,i,1)+dfs(i+1,r,2)+1);
            else
                ans = min(ans,dfs(l,i,1)+dfs(i+1,r,2)+2);
        }*/
        int ans = min(dfs(l,r,1)+1,dfs(l,r,2)+1);
        return f[l][r][b] = ans;
    }
    if(b == 1) {
        int ans = dfs(l+1,r,0);
        for(int i = l+1;i <= r;i ++) {
            if(a[l] == a[i])
                ans = min(ans,dfs(l+1,i-1,0)+dfs(i,r,1));
        }
        return f[l][r][b] = ans;
    }
    if(b == 2) {
        int ans = dfs(l,r-1,0);
        for(int i = l;i <= r-1;i ++) {
            if(a[i] == a[r])
                ans = min(ans,dfs(i+1,r-1,0)+dfs(l,i,2));
        }
        return f[l][r][b] = ans;
    }
}

int main() {
    int n = read();
    scanf("%s",a+1);
    memset(f,-1,sizeof f);
    for(int i = 1;i <= n;i ++) f[i][i][1] = f[i][i][2] = 0,f[i][i][0] = 1;
    cout << dfs(1,n,0) << endl;
}


/**
11
abccbacabba
*/
