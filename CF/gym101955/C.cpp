#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

vector<vector<int> > mj(int n) {
    vector<vector<int> > ans;
    for(int v = 1;v <= n;v ++) {
        for(int t = 0;t < n;t ++) {
            if(t+1 == v || t+1 == v-1) continue;
            int d = 1;
            vector<int> a; a.resize(n);
            for(int i = 0;i < n;i ++) {
                if(d == v) d ++;
                if(i!=t) a[i] = d,d ++;
                else a[i] = v;
            }
            ans.push_back(a);
        }
    }
    vector<int> a; a.resize(n);
    for(int i = 0;i < n;i ++) a[i] = i + 1;
    ans.push_back(a);
   /* for(vector<int>& a : ans) {
        for(int x : a) printf("%d ",x);
        puts("");
    }*/
    return ans;
}

int main(){
    int T = read(),cc = 0;
    while(T --) {
        int n = read(),k = read(),mod = read();
        k = min(k,n);
        vector<vector<int> > aa = mj(n);
        LL d = 1;
        for(int i = 1;i <= k;i ++) d = d * i % mod;
        LL ans = 0;
        for(vector<int> &a : aa) {
            bool flag = 0;
            for(int i = 0;i < k - 1;i ++) {
                if(a[i] > a[i+1]) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) (ans += d) %= mod;
        }
        printf("Case #%d: %lld\n",++ cc,ans);
    }
}

