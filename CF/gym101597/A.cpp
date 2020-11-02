#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,int> pll;
const int SZ = 2e5 + 10;

int n;
LL A[SZ];
map<LL,int> mp;

bool check(LL m) {
    map<LL,int> MP;
    for(int k = 1;k <= n;k ++) MP[A[k]] ++;
    LL now = 1;
    for(int k = 0;k < n;k ++) {
        if(!MP[now]) return false;
        MP[now] --;
        now = 2 * now % m;
    }
    return true;
}


int main() {
    scanf("%d",&n);
    bool hasZero = 0;
    for(int i = 1;i <= n;i ++) {
        scanf("%lld",&A[i]);
        if(A[i] == 0) hasZero = 1;
        mp[A[i]] ++;
    }

    if(hasZero) {
        LL ans = 0;
        for(int i = 1;i <= n;i ++) {
            ans = max(ans,A[i]);
        }
        ans *= 2;
        if(ans == 0) ans = 1;
        cout << ans << endl;
        return 0;
    }


    int firstList = -1;
    vector<pll> a,b;
    for(int i = 1,fst = 0;i <= n;i ++) {
        LL x = A[i];
        if(!mp[x]) continue;
        mp[x] --;
        while(mp[x*2]) x *= 2,mp[x] --;
        if(A[i] == 1 && !fst) {
            fst = 1;
            firstList = a.size();
        }
        a.push_back(make_pair(A[i],a.size()));
        b.push_back(make_pair(x*2,b.size()));
      //  cout << A[i] << " " << x*2 << endl;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(a.size() == 1) {
        cout << b[b.size()-1].first/2+1 << endl;
        return 0;
    }

    LL M = 2e18;
   // for(int i = 0;i < a.size();i ++) printf("(%lld,%d)",a[i].first,a[i].second); puts("");
   // for(int i = 0;i < a.size();i ++) printf("(%lld,%d)",b[i].first,b[i].second); puts("");

    for(int i = 0;i < 2;i ++) {
        for(int j = 0;j < 2;j ++) {
            if(a[i].second == b[j].second) continue;
            if(a[i].second == firstList) continue;
            LL m = b[j].first - a[i].first;
            if(check(m)) M = min(M,m);
        }
    }
    cout << M << endl;
}
