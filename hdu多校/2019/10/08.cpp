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

struct pq { /// da
    priority_queue<pii> q;
    int del[SZ];

    void push(int x,int y) {
        q.push(make_pair(x,y));
    }

    pii top() {
        while(q.size() && del[q.top().second]) {
            del[q.top().second] = 0;
            q.pop();
        }
        return q.top();
    }

    void del(int x) {
        del[x] = 1;
    }

    void clear() {
        while(q.size()) {
            del[q.top().second] = 0;
            q.pop();
        }
    }
}s[3];

int main() {
    int T = read();
    while(T --) {
        for(int i = 0;i < 3;i ++) s[i].clear();
        int n = read();
        for(int i = 1;i <= n;i ++) {
            int x = read(),y = read();
            s[0].push(x+y)
        }
    }
}
