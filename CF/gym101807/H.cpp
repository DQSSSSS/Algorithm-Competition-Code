#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

set<int> s;
map<int,int> mp;

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        int x = read();
        s.insert(x);
        if(!mp[x]) mp[x] = i;
    }
    s.insert(0);
    s.insert(1e9);
    s.insert(-1e9);
    int q = read();
    while(q --) {
        int x = read(),y = read();
        int d = y - x;
        auto suf = s.lower_bound(d);
        auto pre = suf; pre --;
        int ans;

        //cout << suf->first << " " << pre->first<< endl;
       // cout << suf->second << " " << pre->second<< endl;
      //  cout << abs(y-*suf-x) << " " << abs(y-*pre-x) << endl;

        if(y-*suf<=0)
            ans = mp[*pre];
        else if(y-*pre<=0)
            ans = mp[*suf];
        else if(abs(y-*suf-x) == abs(y-*pre-x))
            ans = min(mp[*pre],mp[*suf]);
        else if(abs(y-*suf-x) < abs(y-*pre-x))
            ans = mp[*suf];
        else
            ans = mp[*pre];
        printf("%d\n",ans);
    }
}

/**
5
3 3 3 3 3
5
1 1
1500 1501
1500 1502
1500 1504
10 65

*/
