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

LL n,a[SZ],b[SZ],maxnum,minnum;

bool check(LL mid) {
	for(int i = 1;i <= n;i ++) b[i] = a[i];
    int pl = 1,pr = n;
	while(pl <= pr) {
        if(b[pl] < mid) {
            int dl = mid - b[pl];
            if(b[pr] < mid) return false;
            int dr = (b[pr] - mid) / 2;
            if(dr == 0) { pr --; continue; }
            int d = min(dl,dr);
			b[pl] += d; b[pr] -= d * 2;
        }
        if(b[pl] >= mid) pl ++;
	}
	for(int i = 1;i <= n;i ++)
		if(b[i] < mid) return false;
	return true;
}


int div() {
	int l = minnum,r = (minnum + maxnum) / 2 + 1;
    while(r - l > 1) {
    	int mid = l + r >> 1;
    //	cout << l << " " << r << " " << mid << endl;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    int T = read();
    while(T --) {
		n = read();
		maxnum = 0; minnum = 1e8;
		for(int i = 1;i <= n;i ++) {
			a[i] = read();
            maxnum = max(maxnum,a[i]);
            minnum = min(minnum,a[i]);
        }
        sort(a + 1,a + 1 + n);
        for(int i = 1;i <= n;i ++) b[i] = a[i];
        for(int i = 1;i <= n;i ++) cout << b[i] <<" "; puts("");
        LL ans = 0;
        for(int i = 1;i <= n;i ++) {
			ans += b[i] * 2;
        }
        cout << ans << endl;
		ans /= (2 * n);
        cout << ans << endl;
        LL d = 0;
        for(LL i = ans + 5;i >= max(0ll,ans - 5);i --)
        	if(check(i)) {
        		d = i;
        		break;
        	}
        printf("%d\n",d);
    }
    return 0;
}
/**
233
10
0 20000 93464 13648 86416541 100000000 35651697 25648681 44896332 310

19524539
*/
