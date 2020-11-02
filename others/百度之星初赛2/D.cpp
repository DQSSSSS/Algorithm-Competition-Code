#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Min(x,y) ((x) < (y) ? (x) : (y))
#define Max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;

typedef long long LL;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n,a[SZ],b[SZ],maxnum,minnum;

inline bool check(int mid) {
    register int pl = 1,pr = n,lx = a[1],rx = a[n];
	while(pl <= pr) {
		if(lx >= mid) {
        	pl ++,lx = a[pl];
			if(lx >= mid) return true;
		}
        if(lx < mid) {
            int dl = mid - lx;
            if(rx < mid) return false;
            int dr = (rx - mid) >> 1;
            if(dr == 0) { pr --; rx = a[pr]; continue; }
            int d = Min(dl,dr);
			lx += d; rx -= d << 1;
        }
	}
	if((pl <= n && lx < mid) || (pr >= 1 && rx < mid)) return false;
	return true;
}


inline int div() {
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
		for(register int i = 1;i <= n;i ++) {
			a[i] = read();
            maxnum = Max(maxnum,a[i]);
            minnum = Min(minnum,a[i]);
        }
        sort(a + 1,a + 1 + n);
        printf("%d\n",div());
    }
    return 0;
}
