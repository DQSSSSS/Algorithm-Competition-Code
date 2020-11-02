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

int a[110];
int use[110];

int main() {
    int n = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();

    int ans = 0;
    for(int b = 1;b <= k;b ++) {
        memset(use,0,sizeof use);
        int t = 0,d = 0;
        for(int i = 0;b+i*k <= n;i ++)
            use[b+i*k] = 1;
        for(int i = 1;i <= n;i ++)
            if(!use[i]) {
                if(a[i] == 1)
                    d ++;
                else
                    t ++;
            }
        ans = max(ans,abs(d-t));
    }
    cout << ans << endl;
    return 0;
}
