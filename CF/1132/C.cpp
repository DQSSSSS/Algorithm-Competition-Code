#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

LL a[SZ],l[SZ],r[SZ],b[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        l[i] = read(),r[i] = read();
        a[l[i]] ++; a[r[i]+1]--;
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) a[i] += a[i-1];
    for(int i = 1;i <= m;i ++) {
        for(int j = l[i];j <= r[i];j ++) a[j] --;
        int sum = 0;
        for(int j = 1;j <= n;j ++) {
            sum += a[j] != 0;
            b[j] = b[j-1] + (a[j] == 1);
        }
        for(int j = i+1;j <= m;j ++) {
            int x = b[r[j]] - b[l[j]-1];
            ans = max(ans,sum-x);
        }
        for(int j = l[i];j <= r[i];j ++) a[j] ++;
    }
    cout << ans << endl;
}


