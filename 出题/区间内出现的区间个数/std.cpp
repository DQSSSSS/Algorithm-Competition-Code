#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int read() {
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a == '-') flag = 1; a = getchar();}
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a = getchar();}
    if(flag) n = -n;
    return n;
}

int n,m;
LL L[SZ],R[SZ];

int main() {
    //freopen("times.in","r",stdin); freopen("my.out","w",stdout);
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 1;i <= n;i ++) {
            L[i] = read(),R[i] = L[i]+read()-1;
        }
        sort(L+1,L+1+n);
        sort(R+1,R+1+n);
        for(int i = 1;i <= m;i ++) {
            int l = read(),r = l+read()-1;
            int rn = upper_bound(L+1,L+1+n,r)-L;
            int ln = lower_bound(R+1,R+1+n,l)-R-1;
            rn = n - rn + 1;
            printf("%d\n",n-ln-rn);
        }
    }
}
