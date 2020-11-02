#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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
multiset<int> s;

int main() {
    int n = read(),k = read();
    for(int i = 1;i <= n;i ++)
        a[i].second = read(),a[i].first = read();
    sort(a + 1,a + 1 + n);
    LL ans = 0,sum = 0;
    for(int i = n;i >= 1;i --) {
        s.insert(-a[i].second);
        sum += a[i].second;
        if(s.size() > k) {
            auto it = s.end(); it --;
            sum -= -*it;
            s.erase(it);
        }
       // cout << a[i].first << " "<< sum << endl;
        ans = max(ans,a[i].first * sum);
    }
    cout << ans << endl;
}
/**
5 3
100 1
10 2
5 3
2 4
6 5
*/
