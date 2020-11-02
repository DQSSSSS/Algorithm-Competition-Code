#include <bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
using namespace std;
set<pll>s;
vector<LL> v;
int main() {
    LL n,m,a,b;
    scanf("%I64d%I64d",&n,&m);
    LL x = n;
    for (LL i = 2;i*i <= x;i++) {
        if (x % i == 0) {
            v.push_back(n/i);
            while(x % i == 0) x /= i;
        }
    }
    if(x != 1) v.push_back(n/x);
    for (LL i = 1;i <= m;i++)
        scanf("%I64d%I64d",&a,&b),s.insert(make_pair(min(a,b),max(a,b)));
    bool flag = false;
    for (LL i = 0;!flag && i < v.size();i++) {
        LL step = v[i],cnt = 0;
        for (auto x : s) {
            LL p = x.first,q = x.second;
            p += step,q += step,p %= n,q %= n;
            if (p == 0) p = n;
            if (q == 0) q = n;
            if (s.find(make_pair(min(p,q),max(p,q))) != s.end())
                cnt++;
        }
        if (cnt == m)
            flag = true;
    }
    if (flag) puts("Yes");
    else puts("No");
    return 0;
}
