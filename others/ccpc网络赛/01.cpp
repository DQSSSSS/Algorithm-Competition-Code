#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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


priority_queue<pii> q;

int main(){
    int T = read();
    while(T --) {
    	int n = read();
    	while(q.size()) q.pop();
    	LL ans1 = 0,ans2 = 0;
    	for(int i = 1;i <= n;i ++) {
            LL x = read();
            if(q.size() && -q.top().first < x) {
                pii y = q.top(); q.pop();
                ans1 += x + y.first;
                if(y.second) q.push(make_pair(y.first,0));
                else ans2 += 2;
                q.push(make_pair(-x,1));
            }
            else {
            	q.push(make_pair(-x,0));
            }
    	}
    	printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
