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

struct point {
	LL x,y;
	void Read() { x = read(),y = read(); }
    point operator -(const point &o) const {
        return (point){x - o.x,y - o.y};
    }
    LL operator *(const point &o) const {
        return x * o.y - y * o.x;
    }
};

struct haha {
	point a,b;
}l[SZ];

int main() {
    int n = read();
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        l[i].a.Read();
        l[i].b.Read();
        LL dx = abs(l[i].a.x - l[i].b.x);
        LL dy = abs(l[i].a.y - l[i].b.y);
		ans += __gcd(dx,dy) + 1;
    }
    for(int i = 1;i <= n;i ++)
    	for(int j = i + 1;j <= n;j ++) {
            point a = l[i].a,b = l[i].b;
            point c = l[j].a,d = l[j].b;
            if(((c - a) * (b - a) <= 0) ^ ((d - a) * (b - a) <= 0)) {
                if(((b - c) * (d - c) <= 0) ^ ((a - c) * (d - c) <= 0))
            		ans --;
            }
    	}
	cout << ans << endl;
	return 0;
}
