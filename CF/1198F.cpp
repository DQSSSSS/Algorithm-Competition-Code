#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-14;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n,b[SZ];
pii a[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = make_pair(read(),i);
    int T = 50;
    while(T -- > 1) {
        random_shuffle(a+1,a+1+n);
        int now = a[1].first,t = 1;
        b[a[1].second] = T;
        for(int i = 2;i <= n;i ++) {
            int x = __gcd(now,a[i].first);
            if(x<now) b[a[i].second] = T,t ++;
            now = x;
        }
        if(now != 1) break;
        if(t && n-t) {
            int x = 0;
            for(int i = 1;i <= n;i ++) {
                if(b[a[i].second] != T) {
                    x = __gcd(x,a[i].first);
                }
            }
            if(x == 1) {
                puts("YES");
                for(int i = 1;i <= n;i ++) {
                    printf("%d ",b[i]==T?2:1);
                }
                return 0;
            }
        }
    }
    puts("NO");
}
