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

int n,a[SZ],c[SZ];
int s[11],sum[11],num[11];

bool check(int mid) {
    for(int i = 1;i <= n/2;i ++) a[i] = (mid+c[i]-1)/c[i];
    for(int i = 1;i <= 3;i ++) s[i] = sum[i];

    vector<pair<int,pii> > g;
    for(int i = 1;i <= 3;i ++){
        for(int j = i;j <= 3;j ++) {
            g.push_back(make_pair(num[i]+num[j],make_pair(i,j)));
        }
    }

    for(int i = n/2;i >= 1;i --) {
        bool flag = 0;
        for(pair<int,pii> p : g) {
            if(p.first >= a[i]) {
                int x = p.second.first;
                int y = p.second.second;
                s[x] --; s[y] --;
                if(s[1]>=0&&s[2]>=0&&s[3]>=0) { flag = 1; break; }
                else s[x] ++,s[y] ++;
            }
        }
        if(!flag) return false;
    }
    return true;
}

int main() {
    for(int i = 1;i <= 3;i ++) sum[i] = read(),n += sum[i];
    for(int i = 1;i <= 3;i ++) num[i] = read();
    for(int i = 1;i <= n/2;i ++) c[i] = read();
    sort(c+1,c+1+n/2);
    reverse(c+1,c+1+n/2);

    int l = 0,r = 3e8;
    while(r-l>1) {
        int mid = l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout << l << endl;
}
