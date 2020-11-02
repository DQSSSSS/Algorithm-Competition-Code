#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
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

pii a[SZ];
int col[SZ],lsh[SZ];
vector<int> add[SZ];

int main() {
 // freopen("H.in", "r", stdin); freopen("my.out", "w", stdout);
    int T = read();
    while(T --) {
        int n = read(),k = read();
        lsh[0] = 0;
        for(int i = 1;i <= n;i ++) {
            a[i].first = read();
            a[i].second = read();
            lsh[++ lsh[0]] = a[i].first;
            lsh[++ lsh[0]] = a[i].second;
        }
        if (n < k) {
          puts("0");
          for (int i = 0; i < n; ++i) printf("1%c", i == n - 1 ? '\n' : ' ');
          continue;
        }
        sort(lsh+1,lsh+1+lsh[0]);
        lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
        for(int i = 1;i <= lsh[0];i ++) add[i].clear();
        for(int i = 1;i <= n;i ++) {
            a[i].first = lower_bound(lsh+1,lsh+1+lsh[0],a[i].first)-lsh;
            a[i].second = lower_bound(lsh+1,lsh+1+lsh[0],a[i].second)-lsh;
        }

        for(int i = 1;i <= n;i ++) {
            add[a[i].first].push_back(i);
        }

        priority_queue<int> s;
        for(int i = 1;i <= k;i ++) s.push(i);
        priority_queue<pii,vector<pii>,greater<pii> > q;

        int ans = 0;
        for(int i = 1;i < lsh[0];i ++) {
            while(q.size() && q.top().first <= i)
                s.push(col[q.top().second]),q.pop();
            for(int id : add[i]) {
                if(s.empty()) {
                    if(q.top().first < a[id].second) {
                        col[id] = col[q.top().second];
                        q.pop();
                        q.push(make_pair(a[id].second,id));
                    }
                    else {
                        col[id] = 1;
                    }
                }
                else {
                    col[id] = s.top(); s.pop();
                    q.push(make_pair(a[id].second,id));
                }
            }
            if(s.empty()) ans += lsh[i+1]-lsh[i];
        }

        printf("%d\n",ans);
        for(int i = 1;i <= n;i ++) printf("%d%c",col[i],i==n?'\n':' ');
    }
}
/*
233
3 2
1 2
2 3
1 3

5 1
1 6
2 3
4 9
7 8
5 10


1
7 5
2 9
7 9
6 9
4 8
7 10
8 10
6 8
*/
