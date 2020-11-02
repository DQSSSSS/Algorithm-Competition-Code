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

LL work(int n) {
    map<int,int> mp;
    LL ans = -1;
    cout << n << "   ";
    for(int i = 1;i <= 2*n;i ++) {
        LL t = 0,x = i;
        mp.clear();
        while(1) {
            if(mp[x]) break;
            mp[x] = 1; t ++;
            if(x > n) x = 2*(x-n);
            else x = 2*x-1;
        }
        cout << t << " ";
    }
    puts("");
    return ans;
}

int a[SZ],b[SZ],c[SZ];

int main(){
    for(int n = 100000;n <= 100000;n ++) {
        work(n);
    }
    /*int n = read() * 2;
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) b[i] = read();
    int ans = n;
    int tmp = 0;
    for(int i = 1;i <= n;i ++) if(a[i]!=b[i]) tmp ++;
    ans = min(ans,tmp);

    for(int i = 1,i1=1,i2=n/2+1;i <= n;i ++)
        if(i&1) c[i] = a[i1++]; else c[i] = a[i2 ++];
    for(int i = 1;i <= n;i ++) a[i] = c[i];
    tmp = 0;
    for(int i = 1;i <= n;i ++) if(a[i]!=b[i]) tmp ++;
    ans = min(ans,1+tmp);

    for(int i = 1,i1=1,i2=n/2+1;i <= n;i ++)
        if(i&1) c[i] = a[i1++]; else c[i] = a[i2 ++];
    for(int i = 1;i <= n;i ++) a[i] = c[i];
    tmp = 0;
    for(int i = 1;i <= n;i ++) if(a[i]!=b[i]) tmp ++;
    ans = min(ans,2+tmp);
    printf("%d\n",ans);*/

}
