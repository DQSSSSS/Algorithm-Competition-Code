#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
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

vector<LL> g;

LL pd(LL r,LL d) {
	LL x = 2 * r / d;
	LL ans = 0;
	for(int i = 0;i < g.size();i ++) {
		LL u2 = g[i];
		if(u2 > x) break;
		LL v2 = x - u2;
		LL v = sqrt(v2),u = sqrt(u2);
		if(v * v != v2) continue;
		if(u <= v) continue;
		if(__gcd(u,v) != 1) continue;
		ans ++;
	}
	return ans;
}

int main() {
    LL r = read();
    for(LL i = 1;i * i <= 2 * r;i ++)
        g.push_back(i * i);
    LL ans = 0;
    for(LL d = 1;d * d <= 2 * r;d ++) {
        if((2 * r) % d == 0) {
			ans += pd(r,d);
            if(d * d != 2 * r)
                ans += pd(r,2 * r / d);
        }
    }
    cout << ans * 4 << endl;
    return 0;
}
