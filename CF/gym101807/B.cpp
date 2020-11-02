#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[SZ];
vector<pii> g;

bool cmp(pii a,pii b) {
    return a.first * b.second < a.second * b.first;
}

int main() {
    int n = read();
    int sum = 0;
    for(int q = 1,flag = 1;flag;q ++) {
        for(int p = 0;p <= q && flag;p ++) {
            int d = __gcd(p,q);
            if(d == 1) {
                if(sum + q > n) flag = 0;
                else {
                    sum += q;
                    g.push_back(make_pair(p,q));
                }
            }
        }
    }
    sort(g.begin(),g.end(),cmp);
    /*for(int i = 0;i < g.size();i ++) {
        printf("%d %d (%d/%d)\n",i,g[i].second,g[i].first,g[i].second);
    }*/
    int now = 0,j = n;
    for(int i = g.size()-1;i >= 0;i --) {
        int p = g[i].first;
        int q = g[i].second;
        while(q -- > p) a[j --] = now;
        while(p --) a[j --] = now ++;
    }
    while(j>=0) a[j --] = now;
    printf("%d\n",g.size());
    for(int i = 0;i <= n;i ++) printf("%d ",a[i]);
}
