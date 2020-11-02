#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct haha {
    int x,y;
}a[SZ];

bool cmp(haha a,haha b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }

LL sum[1010],dd[1010],lsh[1010];

int main() {
    freopen("dull.in","r",stdin);
    int T = read();
    while(T --) {
        int n = read(),m = read(),k = read();

        for(int i = 1;i <= lsh[0];i ++) dd[i]=sum[i]=0;
        lsh[0] = 0;

        for(int i = 1;i <= k;i ++) {
            a[i].x = read(),a[i].y = read();
            lsh[++ lsh[0]] = a[i].y;
        }

        if(k == 0) { printf("%lld %lld\n",0ll,1ll*n*m); continue; }

        lsh[++ lsh[0]] = 1;
        lsh[++ lsh[0]] = m + 1;

        sort(lsh + 1, lsh + 1 + lsh[0]);

        lsh[0] = unique(lsh + 1, lsh + 1 + lsh[0]) - lsh - 1;

        for(int i = 1; i <= k; i ++)
            a[i].y = lower_bound(lsh + 1, lsh + 1 + lsh[0], a[i].y) - lsh;

        sort(a + 1, a + 1 + k, cmp);
        LL ji = 0,ou = 0;
        ou = 1ll*(a[1].x-1) * m;
        for(int i = 1,lst = 1; i <= k; i ++) {
            if(i == k || a[i].x != a[i+1].x) {
                LL val;
                if(i == k) val = n - a[i].x + 1;
                else val = a[i+1].x - a[i].x;

                //cout << val << " " << ji << " " << ou << endl;

                for(int j = 1;j <= lsh[0];j ++) dd[j] = 0;
                for(int j = lst; j <= i; j ++) {
                    dd[a[j].y] ++;
                }
                for(int j = 1; j <= lsh[0]; j ++)
                    dd[j] += dd[j-1],sum[j] += dd[j];

                for(int j = 1; j < lsh[0]; j ++) {
                    if(sum[j] % 2 == 1) ji += (lsh[j+1]-lsh[j]) * val;
                    else ou += (lsh[j+1]-lsh[j]) * val;
                }
                lst = i + 1;
            }
        }
        printf("%lld %lld\n",ji,ou);
        //cout << ji + ou << endl;
        //cout << 1ll*n*m << endl;
    }
}
/**
3
3 3 0

3 3 1
2 2

5 5 5
1 5
2 1
3 3
4 2
5 4

233
1000000000 1000000000 1
565656565 565656565
*/

