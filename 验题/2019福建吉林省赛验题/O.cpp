#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 500010;
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

priority_queue<LL> q;

int main() {
    int n;
    while(~scanf("%d",&n)) {
        while(q.size()) q.pop();
        for(int i = 1;i <= n;i ++) q.push(-read());
        LL ans = 0;
        while(q.size() > 1) {
            LL x = -q.top(); q.pop();
            LL y = -q.top(); q.pop();
            ans += x + y;
            q.push(-x-y);
        }
        cout << ans << endl;
    }
    return 0;
}

/**

1
5
1 3 2 3 1
5
2 1 5 1
2 1 2 1
2 1 4 3
1 1 2
2 1 3 2

8
2
6
4


*/
