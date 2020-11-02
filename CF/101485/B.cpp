#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

struct haha {
    int l,r;
}a[SZ];

bool cmplen(haha a,haha b) { return a.r-a.l < b.r-b.l; }
bool cmplen2(haha a,haha b) { return a.r-a.l > b.r-b.l; }
bool cmpl(haha a,haha b) { return a.l < b.l; }

vector<haha> A,B;
/// A: 没包含任何

int f[210][210];

int main() {
    int n = read(),p = read();
    for(int i = 1;i <= n;i ++) {
        a[i].l = read();
        a[i].r = read();
    }
    sort(a+1,a+1+n,cmplen);
    for(int i = 1;i <= n;i ++) {
        bool flag = 0;
        for(haha p : A) {
            if(a[i].l <= p.l && p.r <= a[i].r) {
                flag = 1; break;
            }
        }
        if(!flag) A.push_back(a[i]);
        else B.push_back(a[i]);
    }
    sort(A.begin(),A.end(),cmpl);
    for(int i = 0;i <= A.size();i ++)
        for(int j = 0;j <= p;j ++)
            f[i][j] = -INF;
    f[0][0] = 0;
    for(int k = 1;k <= p;k ++) {
        for(int i = 1;i <= A.size();i ++) {
            int l = A[i-1].l;
            int r = A[i-1].r;
            for(int j = i-1;j >= 0;j --) {
                if(l>=r) break;
                f[i][k] = max(f[i][k],f[j][k-1] + r-l);
                if(j) l = max(l,A[j-1].l),r = min(r,A[j-1].r);
            }
        }
    }
    sort(B.begin(),B.end(),cmplen2);
    LL ans = f[A.size()][p],sum = 0;
    for(int i = 0;i < min((int)B.size(),p);i ++) {
        sum += B[i].r-B[i].l;
        ans = max(ans,sum+f[A.size()][p-i-1]);
    }
    cout << ans << endl;
}
