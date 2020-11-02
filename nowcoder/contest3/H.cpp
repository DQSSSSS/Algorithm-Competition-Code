#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 10000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int tot = 0;
int pri[SZ];
bool vis[SZ];
LL p[SZ];

void init(int n) {
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i;
		for(int j = 1,m;j <= tot && (m = pri[j] * i) <= n;j ++) {
			vis[m] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int main(){
    int n = read();
    init(n);
    for(LL d = 1,j = tot;d <= n;d ++) {
        while(j >= 1 && d * pri[j] > n)
            j --;
        p[d] = j;
    }
    LL ans = 0;
//    for(LL d = 1;d <= n;d ++) cout << p[d] << " "; puts("");
    for(LL d = 1;d <= n;d ++) {
        ans += (p[d] * (p[d] - 1)) / 2;
    }
    cout << ans * 2 << endl;
    return 0;
}
