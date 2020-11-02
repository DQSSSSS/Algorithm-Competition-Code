#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL a[SZ];

void work() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
    }
    int nowr = 1;
    for(int i = 63;i >= 0;i --) {
        int id = -1;
        for(int j = nowr;j <= n;j ++) {
            if(a[j] >> i & 1) {
                id = j;
                break;
            }
        }
        if(id == -1) continue;
        swap(a[id],a[nowr]);
        for(int j = 1;j <= n;j ++) {
            if(j == nowr) continue;
            if(a[j] >> i & 1) {
                a[j] ^= a[nowr];
            }
        }
        nowr ++;
    }
    nowr --;
  //  cout << nowr << endl;
  //  for(int i = 1;i <= nowr;i ++) cout << a[i] << endl;
    int q = read();
    while(q --) {
        LL k = read();
        if(nowr == n) k ++;
        if(k > (1ll << nowr)) puts("-1");
        else {
            k --;
            LL ans = 0;
            for(int i = 1;i <= nowr;i ++) {
                int id = nowr - i;
                if(k >> id & 1) {
                    ans ^= a[i];
                }
            }
            printf("%lld\n",ans);
        }
    }
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        printf("Case #%d:\n",++ cc);
        work();
    }
}
