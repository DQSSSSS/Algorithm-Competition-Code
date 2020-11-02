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

int get(int a,int b) {
    int len = abs(a-b);
    return (len+1) / 2;
}

struct haha {
    int p,d;
}c[11];

pii a[SZ];

int main() {
    freopen("B.in","r",stdin);
    freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 0;i < 4;i ++) c[i].p = -1,c[i].d = 0;
        for(int i = 1;i <= n;i ++) {
            int l = read(),r = read();
            a[i].first = l;
            a[i].second = r;
        }
        vector<pii> b; b.push_back(a[n]);
        for(int i = n-1;i >= 1;i --) {
            pii lst = b[b.size()-1];
            if(a[i].first <= lst.first && lst.second <= a[i].second) continue;
            b.push_back(a[i]);
        }
        reverse(b.begin(),b.end());

        int L = 1,R = 1e6,id = -2;
        for(int i = 0;i < b.size();i ++) {
            pii p = b[i];
            if(max(L,p.first) > min(R,p.second)) {
                id = i-1;
                break;
            }
            L=max(L,p.first);
            R=min(R,p.second);
        }

        if(id == -2) {puts("0"); continue; }

       // for(pii p : b) printf("%d %d\n",p.first,p.second);
        for(int i = id;i < b.size();i ++) {

            if(c[0].p == -1) {
                pii p = make_pair(L,R);
                c[0].p = p.first; c[1].p = min(p.first+1,p.second);
                c[2].p = p.second; c[3].p = max(p.second-1,p.first);
            }
            else {
                pii p = b[i];
                haha d[5];
                d[0].p = p.first; d[1].p = min(p.first+1,p.second);
                d[2].p = p.second; d[3].p = max(p.second-1,p.first);
                for(int i = 0;i < 4;i ++) {
                    d[i].d = INF;
                    for(int j = 0;j < 4;j ++) {
                        d[i].d = min(d[i].d,c[j].d+get(c[j].p,d[i].p));
                    }
                }
                for(int i = 0;i < 4;i ++) {
                    if(p.first <= c[i].p && c[i].p <= p.second) continue;
                    c[i] = d[i];
                }
            }
         //   for(int i = 0;i < 4;i ++) printf("%d %d\n",c[i].p,c[i].d);
         //   puts("------");
        }
        int ans = INF;
        for(int i = 0;i < 4;i ++) ans = min(ans,c[i].d);
        printf("%d\n",ans);
    }
}
/**

233
10
1
10
5 10
6 10
5 6
1 7
6 7
1 1
3 7
4 6
1 10
6 7


*/
