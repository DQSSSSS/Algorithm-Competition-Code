#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e5 + 10;
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

int a[SZ],b[110];

int main() {
    int n = read();
    int minn = 1e9,maxn = 0,sum = 0;
    for(int i = 1;i <= n;i ++) {
        int x = a[i] = read();
        for(int j = 1;j <= 100;j ++)
            if(x % j == 0) b[j] = max(b[j],x);
        sum += x;
        minn = min(minn,x);
        maxn = max(maxn,x);
    }
    int ans = sum;
    for(int i = 1;i <= 100;i ++) {
        ans = min(ans,sum - minn - b[i] + minn * i + b[i] / i);
    }
    cout << ans << endl;
}
