#include <bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int f[55];

char s[SZ];

struct haha {
    int l,r,d;
}a[SZ];

bool cmp(haha a,haha b) {
    if(a.r == b.r) {
        return a.l < b.l;
    }
    return a.r < b.r;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%s",s);
        int len = strlen(s);
        int u = s[0] - 'a'+1;
        int v = s[len-1] - 'a'+1;
        a[i].l = u;
        a[i].r = v;
        a[i].d = len;
    }

    sort(a+1,a+1+n,cmp);
    f[0] = 0;
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        int x = 0;
        for(int j = 0;j <= a[i].l;j ++) {
            x = max(x,f[j]);
        }
        f[a[i].r] = max(f[a[i].r],x + a[i].d);
    }

    for(int i = 1;i <= 26;i ++) ans = max(ans,f[i]);

    cout << ans << endl;
}
