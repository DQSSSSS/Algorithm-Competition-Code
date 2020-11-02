#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
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

int a[SZ],use[SZ],R[SZ];
int stmx[22][SZ];
int stmn[22][SZ];

int get_min(int l,int r) {
    int k = log2(r-l+1);
    return min(stmn[k][l],stmn[k][r-(1<<k)+1]);
}

int get_max(int l,int r) {
    int k = log2(r-l+1);
    return max(stmx[k][l],stmx[k][r-(1<<k)+1]);
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i+2*n] = a[i+n] = a[i] = read();
    }
    for(int i = 1;i <= 3 * n;i ++) {
        stmx[0][i] = a[i];
        stmn[0][i] = a[i];
    }
    for(int j = 1;j <= log2(3*n);j ++) {
        for(int i = 1;i + (1<<j) - 1<= 3*n;i ++){
            stmn[j][i] = min(stmn[j-1][i],stmn[j-1][i+(1<<(j-1))]);
            stmx[j][i] = max(stmx[j-1][i],stmx[j-1][i+(1<<(j-1))]);
        }
    }

    stack<int> S;

    for(int i = 3*n;i >= 1;i --){
        while(S.size() && a[S.top()] <= a[i]) S.pop();
        R[i] = S.empty() ? 3*n : S.top()-1;
        S.push(i);
    }
    for(int i = 1;i <= 3*n;i ++){
        int l = i,r = R[i] + 1;
        while(r-l>1) {
            int mid = l + r >> 1;
            if(get_min(i,mid)*2 < a[i]) r = mid;
            else l = mid;
        }
        if(r != R[i] +1) use[i] = l;
        else use[i] = INF;
    }

    for(int i = 1;i <= 3 * n;i ++) {
        stmn[0][i] = use[i];
    }
    for(int j = 1;j <= log2(3*n);j ++) {
        for(int i = 1;i + (1<<j) - 1<= 3*n;i ++){
            stmn[j][i] = min(stmn[j-1][i],stmn[j-1][i+(1<<(j-1))]);
        }
    }

    for(int i = 1;i <= n;i ++){
        int r = get_min(i,3*n),ans;
        if(r == INF) ans = -1;
        else ans = r - i + 1;
        printf("%d ",ans);
    }
}



