#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

pii a[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        a[i].first = read();
        a[i].second = a[i].first + read();
    }
    sort(a+1,a+1+n);
    int ans = 0;
    multiset<int> s;
   // for(int i = 1;i <= n;i ++) printf("%d %d\n",a[i].first,a[i].second);
    for(int i = 1;i <= n;i ++) {
        auto it = s.lower_bound(a[i].first - m);
        if(it == s.end() || *it > a[i].first) ans ++,s.insert(a[i].second);
        else {
//            cout << i << " " <<*it << endl;
            s.erase(it);
            s.insert(a[i].second);
        }
    }
   // cout << ans << endl;
    cout << n - ans << endl;
}
