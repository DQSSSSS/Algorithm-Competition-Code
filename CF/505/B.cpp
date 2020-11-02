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

vector<LL> ans;
LL a[SZ],b[SZ];

void fj(LL d) {
    for(LL i = 2;i * i <= d;i ++) {
    	if(d % i == 0) {
    		ans.push_back(i);
    		while(d % i == 0) d /= i;
    	}
    }
    if(d != 1) ans.push_back(d);
}

int main() {
    int n = read();
    LL x = read(),y = read();
	fj(x); fj(y);
	sort(ans.begin(),ans.end());

    for(int i = 1;i < n;i ++) {
		a[i] = read(); b[i] = read();
    }

    for(int i = 0;i < ans.size();i ++) {
    	if(i > 0 && ans[i] == ans[i - 1]) continue;
    	LL x = ans[i];
    	bool flag = 0;
    	for(int j = 1;j < n;j ++) {
    		if(a[j] % x && b[j] % x) {
    			flag = 1;
    			break;
    		}
    	}
    	if(!flag) { cout << x; return 0; }
    }
    puts("-1");
    return 0;
}
