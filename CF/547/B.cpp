#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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
    int l,r,x;
}a[SZ];

bool cmp(haha a,haha b) { return a.x < b.x; }
multiset<int> s;

vector<int> add[SZ],del[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i].x = read();
    stack<int> S;
    for(int i = 1;i <= n;i ++) {
        while(S.size() && a[S.top()].x >= a[i].x) S.pop();
        a[i].l = S.size() ? S.top()+1 : 1;
        S.push(i);
    }
    while(S.size()) S.pop();
    for(int i = n;i >= 1;i --) {
        while(S.size() && a[S.top()].x >= a[i].x) S.pop();
        a[i].r = S.size() ? S.top()-1 : n;
        S.push(i);
    }
    while(S.size()) S.pop();
    sort(a+1,a+1+n,cmp);

    for(int i = 1;i <= n;i ++) {
        add[1].push_back(a[i].x);
        del[a[i].r-a[i].l+1].push_back(a[i].x);
    }

    for(int i = 1;i <= n;i ++) {
        for(int x : add[i]) s.insert(-x);
        printf("%d ",-*s.begin());
        for(int x : del[i]) s.erase(s.find(-x));
    }
}
