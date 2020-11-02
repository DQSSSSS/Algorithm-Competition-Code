#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 150010;
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

LL work() {
	LL n = read(),m = read(),k = read();
    if(n > m) swap(n,m);
    if(m > k) return -1;
    LL d = m - n,ans = n;
    k -= n;
    if(d % 2 == 0) {
        if(k % 2 == 0)
	        ans += k;
    	else
            ans --,k --,ans += k;
    }
	else {
        if(k % 2 == 0)
	        k --,d --,ans += k;
    	else
            ans += k - 1;
    }
    return ans;
}

int main() {
    int q = read();
    while(q --) {
        cout << work() << endl;
    }
    return 0;
}
