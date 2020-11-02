#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

pii a[SZ];

int main() {
    int n = read() * 4 + 1;
    for(int i = 1;i <= n;i ++) a[i].first = read(),a[i].second = read();
    for(int x1 = 0;x1 <= 50;x1 ++) {
        for(int x2 = x1;x2 <= 50;x2 ++) {
            for(int y1 = 0;y1 <= 50;y1 ++) {
                for(int y2 = y1;y2 <= 50;y2 ++) {
                    int tot = 0;
                    for(int i = 1;i <= n;i ++) {
                        if(((a[i].first == x1 || a[i].first == x2) && y1 <= a[i].second && a[i].second <= y2)
                           ||((a[i].second == y1 || a[i].second == y2) && x1 <= a[i].first && a[i].first <= x2))
                            tot ++;
                    }
                 //   cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << tot << endl;
                    if(tot == n-1) {
                        for(int i = 1;i <= n;i ++) {
                            if(!(((a[i].first == x1 || a[i].first == x2) && y1 <= a[i].second && a[i].second <= y2)
                                ||((a[i].second == y1 || a[i].second == y2) && x1 <= a[i].first && a[i].first <= x2)))
                                    cout << a[i].first << " " << a[i].second << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }
}
