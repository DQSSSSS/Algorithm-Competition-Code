#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
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

stack<pii> s1,s2;
int nowmax;

void PUSH(int x,int i) {
  //  cout << x << " " << i << endl;
    s1.push(make_pair(x,i));
    if(x < nowmax) return ;
    s2.push(make_pair(x,i));
    nowmax = x;
}

void POP() {
    if(s1.empty()) return ;
    pii p = s1.top(); s1.pop();
    if(p.second == s2.top().second) {
        s2.pop();
        if(s2.size()) nowmax = s2.top().first;
        else nowmax = 0;
    }
}

int n,p,q,m;
UI SA,SB,SC;
UI rng61() {
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    UI t = SA; SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        while(s1.size()) s1.pop();
        while(s2.size()) s2.pop();
        nowmax = 0;
        scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
        ULL ans = 0;
        for(int i = 1;i <= n;i ++) {
            if(rng61() % (p+q) < p) {
                PUSH(rng61() % m + 1,i);
            }
            else {
                POP();
            }
            ans ^= 1ll * i * nowmax;
        }
        printf("Case #%d: %llu\n",cc,ans);
    }
}
