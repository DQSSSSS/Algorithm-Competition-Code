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

LL a[SZ],N[SZ],b[SZ],sum[SZ],S[SZ];
map<LL,int> mp;

int main() {
    int n = read(),t = 0;
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
        if(!mp[a[i]]) mp[a[i]] = 1,t ++;
    }
    sort(a + 1,a + 1 + n);
    n = unique(a + 1,a + 1 + n) - a - 1;
    for(int i = 1;i < n;i ++) b[i] = a[i + 1] - a[i];
    sort(b + 1,b + n);

    sum[0] = t;
    N[0] = t;
    LL nn = n;
    for(int i = 1,lst = 1;i < n;i ++) {
        if(i == n - 1 || b[i] != b[i + 1]) {
            LL x = i - lst + 1;
            sum[i] = sum[lst - 1] + nn * (b[i] - b[lst - 1] - 1) + nn - x;
            nn -= x;
            N[i] = nn;
            lst = i + 1;
        }
    }
/*
    for(int i = 0;i < n;i ++) cout << b[i] << " "; puts("");
    for(int i = 0;i < n;i ++) cout << N[i] << " "; puts("");
    for(int i = 0;i < n;i ++) cout << sum[i] << " "; puts("");
*/

    int m = read();
    for(int i = 1;i <= m;i ++) {
        LL x = read(),y = read();
        LL len = y - x;
        LL ans = 0;
        if(len > b[n-1]) ans = sum[n-1] + nn * (len - b[n-1]);
        else {
            int id = upper_bound(b + 1,b + n,len) - b - 1;
       //     cout << id << endl;
            ans = sum[id] + (len - b[id]) * N[id];
        }
        printf("%lld ",ans);
    }

    return 0;
}



