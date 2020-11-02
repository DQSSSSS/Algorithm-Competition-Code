#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

int ans[SZ];
set<pii> s;

int main() {
	int n = read(),m = read(),d = read() + 1;
	for(int i = 1;i <= n;i ++) {
		int x = read();
		s.insert(make_pair(x,i));
	}
	int tot = 0;
	while(s.size()) {
		tot ++;
		pii x = *s.begin();
		int now = x.first;
		while(now <= m) {
			ans[x.second] = tot;
			now += d; s.erase(x);
			set<pii> :: iterator it = s.lower_bound(make_pair(now,-1));
			if(it == s.end()) break;
			x = *it; now = x.first;	
		}
	}
	printf("%d\n",tot);
	for(int i = 1;i <= n;i ++)
		printf("%d ",ans[i]);
	return 0;
}
