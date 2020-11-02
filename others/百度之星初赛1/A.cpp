#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
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

int n,a[SZ];

int main() {
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) a[i] = read();
        sort(a + 1,a + 1 + n);
        int ans = -1;
        for(int i = 1;i <= n;i ++) {
        	for(int j = i + 1;j <= n;j ++) {
                int x = a[i] + a[j];
                int id = lower_bound(a + j + 1,a + n + 1,x) - a;
                id --;
                if(id > j)
					ans = max(ans,x + a[id]);
        	}
        }
        cout << ans << endl;
    }
    return 0;
}
