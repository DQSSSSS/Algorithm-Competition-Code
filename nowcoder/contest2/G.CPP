#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n;
LL T;
LL a[SZ],as[SZ];
LL x[SZ],xs[SZ];

int main() {
    n = read(),T = read();
    for(int i = 1;i <= n;i ++) x[i] = read();
    for(int i = 1;i <= n;i ++) a[i] = read(),as[i] += a[i] + (i == 0 ? 0 : as[i - 1]);
    LL lnum = a[1],l = 1,rnum = a[1],r = 1,now = 0;
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        cout << i << endl;
        LL d = x[i] - x[i - 1];
        if(r == i - 1) now += 2 * d * a[i],r ++,rnum = a[r];
        else if(r == i && rnum < a[r]) now += 2 * d * (a[i] - rnum),rnum = a[r];
        if(i != 1)
			now += 2 * d * (as[i - 1] - as[l] + lnum) - 2 * d * (as[r - 1] - as[i - 1] + rnum);
        printf("%lld %lld %lld %lld %lld\n",l,r,lnum,rnum,now);
        while(now > T && l < i) { ///move l
            LL tmp = (now - T) / (2 * (x[i] - x[l]));
			if((now - T) % (2 * (x[i] - x[l])) != 0) tmp ++;
            if(tmp >= lnum) {
                now -= lnum * 2 * (x[i] - x[l]);
                l ++; lnum = a[l];
            }
            else {
                now -= tmp * 2 * (x[i] - x[l]);
                lnum -= tmp;
            }
        }
		printf("%lld %lld %lld %lld %lld\n",l,r,lnum,rnum,now);
//

		while(l <= i && i <= r) {
			if(a[r] == rnum) {

				if(r == n) break;
                if(x[i] - x[l] > x[r + 1] - x[i]) {
					r ++,rnum = 0;
					continue;
                }
				else break;
			}
            LL tmp = min(lnum,a[r] - rnum);
            if(l == i) break;
            if(now - tmp * 2 * (x[i] - x[l]) + tmp * 2 * (x[r] - x[i]) <= now) {
                now = now - tmp * 2 * (x[i] - x[l]) + tmp * 2 * (x[r] - x[i]);
             //   cout << tmp << " " << lnum << endl;
				rnum += tmp;

                if(tmp == lnum) l ++,lnum = a[l];
                else lnum -= tmp;
            }
            else break;
        }/// move l and r
		printf("%lld %lld %lld %lld %lld\n",l,r,lnum,rnum,now);

        while(r <= n || (r == n && rnum == a[r])) {
			if(rnum < a[r]) {
				LL tmp = (T - now) / (2 * (x[r] - x[i]));
                if(tmp <= a[r] - rnum) {
					now += tmp * (2 * (x[r] - x[i]));
                    rnum += tmp;
                    break;
                }
                else {
					now += (a[r] - rnum) * (2 * (x[r] - x[i]));
					rnum = a[r];
                    if(r == n) break;
                    if(now + 2 * (x[r + 1] - x[i]) > T) { rnum = a[r]; break; }
                    else r ++,rnum = 0;
                }
			}
			else {
				if(now + 2 * (x[r + 1] - x[i]) > T) break;
				if(r == n) break;
				r ++; rnum = 0;
			}
		}/// move r
		printf("%lld %lld %lld %lld %lld\n",l,r,lnum,rnum,now);
        while(l >= 1 || (l == 1 && lnum == a[1])) {
			if(lnum < a[l]) {
				LL tmp = (T - now) / (2 * (x[i] - x[l]));
                if(tmp <= a[l] - lnum) {
					now += tmp * (2 * (x[i] - x[l]));
                    lnum += tmp;
                    break;
                }
                else {
					now += (a[l] - lnum) * (2 * (x[i] - x[l]));
					lnum = a[l];
                    if(l == 1) break;
                    if(now + 2 * (x[i] - x[l - 1]) > T) { lnum = a[l]; break; }
                    else l --,lnum = 0;
                }
			}
			else {
				if(now + 2 * (x[i] - x[l - 1]) > T) break;
				if(l == 1) break;
				l --; lnum = 0;
			}
		}/// move l

		printf("%lld %lld %lld %lld %lld\n",l,r,lnum,rnum,now);
		if(l != r) ans = max(ans,as[r - 1] - as[l] + lnum + rnum); else ans = max(ans,a[l]);
		//cout << ans <<endl;
	}
	cout <<ans << endl;
	return 0;
}

/*
6 18
1 2 3 4 5 6
1 2 3 4 5 6

5 10
1 3 5 6 8
3 5 2 6 9

8 20
1 6 9 10 15 17 18 20
3 7 6 9 2 6 3 8

9 40
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9



*/
