#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
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

LL n,k,a[SZ],lsh[SZ];

int main() {
	n = read(),k = read();
	for(int i = 1;i <= n;i ++) lsh[i] = a[i] = read();
	sort(a + 1,a + 1 + n);
	sort(lsh + 1,lsh + 1 + n);
	int len = unique(lsh + 1,lsh + 1 + n) - lsh - 1;
	
	if(len == 1) { puts("0"); return 0; }
	
	LL sum = 0,ans = 0,hp = len,lst = 1;
	while(hp > 1) {
		int pos = upper_bound(a + 1,a + 1 + n,lsh[hp - 1]) - a;
		//cout << lsh[hp - 1] << " " << pos << endl;
		LL d = n - pos + 1,h = lsh[hp] - lsh[hp - 1];
		if(sum + d * h > k) { 
			LL tmp = (k - sum) / d;
			ans ++;
		//	cout << h << " " << tmp << endl;
			LL one = k / d * d;
			h -= tmp;
			LL dd = h / (k / d);
			if(k % d == 0 && h % (k / d) == 0) {
				ans += dd;
				sum = 0;
			}
			else {
				ans += dd - 1;
				sum = (h - ((dd - 1) * (k / d))) * d;
				while(sum > k) ans ++,sum -= one;
			}
			hp --; 
		//	cout << dd << endl;
		}
		else {
			sum += d * h;
			hp --;
		}
		//cout << sum << " " << ans << endl;
		//puts("---");
	}
	if(sum) ans ++;
	cout << ans << endl;
	return 0;
}
/**
5 5
1 99 100 101 102

5 5
1 4 6 9 10
*/
