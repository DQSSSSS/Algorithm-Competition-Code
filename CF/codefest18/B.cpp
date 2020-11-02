#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

LL a[SZ];

int main() {
	int n = read();
	LL s = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    sort(a + 1,a + 1 + n);
    int mid = n + 1 >> 1;
    LL ans = 0;
    if(s >= a[mid])
		for(int i = n;i >= mid;i --)
			ans += max(0ll,s - a[i]);
	else
        for(int i = 1;i <= mid;i ++)
        	ans += max(0ll,a[i] - s);
    cout << ans << endl;
	return 0;
}

