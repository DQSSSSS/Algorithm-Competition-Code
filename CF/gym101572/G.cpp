//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e5 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

multiset<pii> s;
pii a[SZ];

int main(){
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) s.insert(make_pair(0,0));
    int ans = 1;
    while(m --) {
        int o = read(),p = read();
        if(o != 1) {
            auto it = s.lower_bound(a[o]); s.erase(it);
            bool flag = a[o] >= a[1];
            a[o].first --; a[o].second += p;
            if(flag && a[o] < a[1]) ans ++;
            s.insert(a[o]);
        }
        else {
            pii prr = a[o];
            a[o].first --; a[o].second += p;
            s.insert(a[o]);
            auto it = s.lower_bound(prr);
            auto it2 = s.lower_bound(a[o]);
            while(it != it2) it --,ans --; ans ++;
            s.erase(s.lower_bound(prr));
        }
//        assert(ans >= 1);
        printf("%d\n",ans);
    }
}
