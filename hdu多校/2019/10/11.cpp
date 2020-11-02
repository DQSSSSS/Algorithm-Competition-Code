#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
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

int L[SZ],R[SZ];

void pre(int a[],int n) {
    stack<int> S;
    for(int i = 1;i <= n;i ++) {
        while(S.size() && a[S.top()] < a[i]) S.pop();
        L[i] = S.size() ? S.top()+1 : 1;
        S.push(i);
    }
    while(S.size()) S.pop();
    for(int i = n;i >= 1;i --) {
        while(S.size() && a[S.top()] < a[i]) S.pop();
        R[i] = S.size() ? S.top()-1 : n;
        S.push(i);
    }
}

int sp[SZ],pr[SZ],a[SZ],maxr[SZ];

LL calcr(int n,int k,bool flag) {
    pre(a,n);
    map<int,int> mp;
    for(int i = n;i >= 1;i --) pr[i] = -1,sp[i] = n+1,maxr[i] = 0;
    for(int i = n;i >= 1;i --) {
        int x = a[i];
        if(!mp.count(x)) sp[i] = n+1;
        else sp[i] = mp[x],pr[mp[x]] = i;
        mp[x] = i;
    }

    multiset<int> s;
    for(int i = 1;i <= n;i ++) {
        if(pr[i] == -1) s.insert(sp[i]);
    }
    for(int i = 1;i <= n;i ++) {
        int l = L[i],r = R[i];
        if((!flag&&i-l<r-i)||(flag&&i-l<=r-i)) {
            maxr[i] = *s.begin()-1;
        }
        s.erase(s.lower_bound(sp[i]));
        if(sp[i]<=n) {
            s.insert(sp[sp[i]]);
        }
    }
   /* puts("---------");
    for(int i = 1;i <= n;i ++) printf("%3d",i); puts("");
    for(int i = 1;i <= n;i ++) printf("%3d",a[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%3d",L[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%3d",R[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%3d",sp[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%3d",pr[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%3d",maxr[i]); puts("");
*/
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        int l = L[i],r = R[i];
        if((!flag&&i-l<r-i)||(flag&&i-l<=r-i)) {
            int minr = min(r,maxr[i]);
            for(int j = i;j >= l;j --) {
                minr = min(minr,sp[j]-1);
                int d = a[i] - k;
                int rl = max(i,j+d-1);
            //    printf("%d %d %d %d\n",i,j,rl,minr);
                if(rl<=minr) {
                    ans += minr - rl + 1;
                }
            }
        }
    }
  //  cout << ans << endl;
    return ans;
}

int main() {
    int T = read();
    while(T --) {
        int n = read(),k = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
        }
        LL ans = calcr(n,k,0);
        reverse(a+1,a+1+n);
        ans += calcr(n,k,1);
        printf("%lld\n",ans);
    }
}
