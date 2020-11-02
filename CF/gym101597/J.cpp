#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

pair<int,int> a[SZ];
bool b[SZ];

int main() {
    int n;
    scanf("%d",&n);
    LL maxy = 0;
    map<int,int> mp;
    for(int i = 1;i <= n;i ++) {
        scanf("%d%d",&a[i].first,&a[i].second);
        mp[a[i].first] = max(mp[a[i].first],a[i].second);
        maxy = max(maxy,1ll*a[i].second);
    }
    int tot = 0;
    for(pair<int,int> p : mp) {
        a[++ tot] = p;
    }
    n = tot;
    LL ans1 = a[n].first-a[1].first+3 + 2*(maxy+2);
    LL ans2 = ans1 - 2;
    LL ans3 = 0;

    for(LL i = 1,y = -1;i <= n;i ++) {
        LL yy = a[i].second;
        if(yy > y) b[i] = 1,y = yy;
    }
    for(LL i = n,y = -1;i >= 1;i --) {
        LL yy = a[i].second;
        if(yy > y) b[i] = 1,y = yy;
    }

    LL lsty = -1,lstx = a[1].first;
    for(int i = 1;i <= n;i ++) {
        LL x = a[i].first;
        LL y = a[i].second;
        if(!b[i]) continue;
        if(y > lsty) ans3 += (lsty+1) * (x - lstx);
        else if(y < lsty) ans3 += (y+1) * (x - lstx);
        else ans3 += (lsty+1) * (x - lstx);
        lstx = x;
        lsty = y;
    }
    ans3 += maxy + 1;
    printf("%lld %lld %lld\n",ans1,ans2,ans3);
}
